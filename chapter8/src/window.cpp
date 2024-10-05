#include <QApplication>
#include <QKeyEvent>
#include <QTimer>
#include <QPainter>
#include <QTransform>
#include <QDir>
#include "random.h"
#include "window.h"

// Ширина одного элемента поля
#define ROW_HEIGHT 13
// Длина одного элемента поля
#define COL_WIDTH 13

// Направления движения змеи
enum Directions { UP, DOWN, LEFT, RIGHT };

// Частота срабатывания таймера (мс)
#define TIMER_INTERVAL 300

Window::Window(QWidget *parent) : QWidget(parent)
{    
    // Изначальный размер окна
    this->resize(520, 520);
    // Запускаем таймер
    this->timer = new QTimer(this);
    // и привязываем обработчик таймера "timerEvent"
    // в нем происходит основной цикл игры: перемещение змеи,
    // проверка коллизий и перерисовка поля
    connect(timer, SIGNAL(timeout()), this, SLOT(timerEvent()));
    // Загрузка изображений
    this->loadImages();
    // Старт игры
    this->initGame();
}

/// @brief Загружает все необходимые изображения
void Window::loadImages()
{
    // трава
    this->bg_image = QPixmap(qApp->applicationDirPath()+"/img/bg.png");
    // яблоко
    this->apple_image = QPixmap(qApp->applicationDirPath()+"/img/apple.png");
    // сегмент тела змеи
    this->snake_image = QPixmap(qApp->applicationDirPath()+"/img/body.png");
    // голова змеи повернутая вверх
    this->snake_head_up = QPixmap(qApp->applicationDirPath()+"/img/head.png");
    // голова змеи повернутая вправо
    this->snake_head_right = this->snake_head_up.transformed(QTransform().rotate(90));
    // голова змеи повернутая вниз
    this->snake_head_down = this->snake_head_right.transformed(QTransform().rotate(90));
    // голова змеи повернутая влево
    this->snake_head_left = this->snake_head_down.transformed(QTransform().rotate(90));        
}

/// @brief Старт игры
void Window::initGame() {
    // Изначально змея движется вправо
    this->direction = Directions::RIGHT;
    // Размещаем яблоко
    this->locateApple();
    // Получаем произвольную позицию головы змеи
    pair snakeHeadPos = getRandPos(this->size().width()-COL_WIDTH,this->size().height()-ROW_HEIGHT);
    // Подгоняем позицию под сетку COL_WIDTH x ROW_HEIGHT
    snakeHeadPos.first = (snakeHeadPos.first / COL_WIDTH) * COL_WIDTH;
    snakeHeadPos.second = (snakeHeadPos.second / ROW_HEIGHT) * ROW_HEIGHT;
    // Добавляем голову к змее
    this->snakePos = {snakeHeadPos};
    // Добавляем два сегмента к змее
    this->snakePos.push_back({snakeHeadPos.first-COL_WIDTH,snakeHeadPos.second});
    this->snakePos.push_back({snakeHeadPos.first-COL_WIDTH*2,snakeHeadPos.second});
    // Выходим из режима "Game Over"
    this->isGameOver = false;
    // Запускаем таймер
    this->timer->start(TIMER_INTERVAL);
}

/// @brief Обработчик нажатия клавиши на клавиатуре
/// @param e Событие нажатия клавиши
void Window::keyPressEvent(QKeyEvent *e)
{
    switch (e->key()) {
        case Qt::Key_Up:
        case Qt::Key_Down:
        case Qt::Key_Left:
        case Qt::Key_Right:
            // Если нажата клавиша управления курсором,
            // то изменяем направление движения змеи
            this->move(e->key());
            break;
        case Qt::Key_Space:
            // Если нажат пробел
            if (this->isGameOver) {                
                // и игра завершена,
                // то запускаем игру заново
                this->initGame();
            }
            break;
        case Qt::Key_Escape:
            // Выход из программы при нажатии Esc
            qApp->quit();
            break;
    }
}

/// @brief Изменяет направление движения змеи
/// @param key Код клавиши управления курсором
void Window::move(int key) {
    switch (key) {
        case Qt::Key_Up:
            if (this->direction != Directions::DOWN) { this->direction = Directions::UP; }            
            break;
        case Qt::Key_Down:
            if (this->direction != Directions::UP) { this->direction = Directions::DOWN; }
            break;
        case Qt::Key_Left:
            if (this->direction != Directions::RIGHT) { this->direction = Directions::LEFT; }
            break;
        case Qt::Key_Right:
            if (this->direction != Directions::LEFT) { this->direction = Directions::RIGHT; }
            break;
    }
}

/// @brief Обработчик таймера, запускается периодически
void Window::timerEvent()
{   
    // Перемещаем змею в зависимости от текущего направления
    // движения (direction)
    pair<int,int> prevPos = {0,0};
    for (int idx=0;idx<this->snakePos.size();++idx) {
        if (idx == 0) {
            // перемещаем голову
            prevPos = this->snakePos[idx];
            switch (this->direction) {
                case Directions::RIGHT:
                    this->snakePos[idx].first += COL_WIDTH;
                    break;
                case Directions::LEFT:
                    this->snakePos[idx].first -= COL_WIDTH;
                    break;
                case Directions::DOWN:
                    this->snakePos[idx].second += ROW_HEIGHT;
                    break;
                case Directions::UP:
                    this->snakePos[idx].second -= ROW_HEIGHT;
                    break;
            }            
        } else {
            // остальные сегменты следуют за головой и друг за другом
            auto swap = this->snakePos[idx];
            this->snakePos[idx] = prevPos;
            prevPos = swap;
        }             
    }
    // перерисовываем окно
    this->repaint();
    // проверяем коллизии
    this->checkCollision();
}

/// @brief Отображает яблоко на поле
void Window::locateApple() {
    // Получаем произвольную позицию яблока
    this->applePos = getRandPos(this->size().width()-COL_WIDTH,this->size().height()-ROW_HEIGHT);    
    // Подгоняем позицию под сетку COL_WIDTH x ROW_HEIGHT
    this->applePos.first = (this->applePos.first / COL_WIDTH) * COL_WIDTH;
    this->applePos.second = (this->applePos.second / ROW_HEIGHT) * ROW_HEIGHT;
    // Если яблоко слишком близко к краям окна или оказалось под змеей,
    // то вызываем функцию снова
    if (this->applePos.first == 0 || this->applePos.second == 0 || 
        this->applePos.first >= this->size().width()-COL_WIDTH*2 || 
        this->applePos.second >= this->size().height()-ROW_HEIGHT*2 ||
        this->collideWithSnake(this->applePos.first,this->applePos.second)) {
            this->locateApple();
    }
}

/// @brief Функция перерисовки содержимого окна. Вызывается каждый раз когда необходимо перерисовать содержимое
/// @param e Событие перерисовки окна
void Window::paintEvent(QPaintEvent *e) {    
    QPainter painter;
    painter.begin(this);
    // Рисуем поле
    for (int y=0;y<this->size().height();y+=ROW_HEIGHT) {
        for (int x=0;x<this->size().width();x+=COL_WIDTH) {
            painter.drawPixmap(x,y, this->bg_image);
        }
    }    
    
    if (!this->isGameOver) {        
        // В режиме когда игра не закончена
        // Рисуем яблоко
        painter.drawPixmap(this->applePos.first, this->applePos.second, this->apple_image);                    
        // Рисуем змею
        for (int idx=0;idx<this->snakePos.size();++idx) {
            auto [x,y] = this->snakePos[idx];
            // рисуем голову
            if (idx == 0) {
                // В зависимости от направления, рисуем голову, повернутую в этом направлении
                switch (this->direction) {
                    case Directions::UP:
                        painter.drawPixmap(x,y, this->snake_head_up);
                        break;
                    case Directions::DOWN:
                        painter.drawPixmap(x,y, this->snake_head_down);
                        break;
                    case Directions::LEFT:
                        painter.drawPixmap(x,y, this->snake_head_left);
                        break;
                    case Directions::RIGHT:
                        painter.drawPixmap(x,y, this->snake_head_right);
                        break;                        
                };
            } else {        
                // рисуем сегменты тела    
                painter.drawPixmap(x,y,this->snake_image);
            }            
        }
    } else {
        // Если игра закончена, то просто пишем "GAME OVER"

        // Устанавливаем шрифт
        QFont font = QFont();
        font.setBold(true);
        font.setPointSize(48);        
        painter.setFont(font);
        // Устанавливаем цвет
        painter.setPen(QColor(0,255,0));
        // Рисуем надпись по центру окна
        painter.drawText(QRect(0,0,this->size().width(),this->size().height()),Qt::AlignCenter | Qt::AlignVCenter, "GAME OVER");
    };
    painter.end();
}

/// @brief Проверяет столкновения змеи
void Window::checkCollision()
{
    // столкновение с границами окна и со своим телом
    auto [x,y] = this->snakePos[0];
    if (x<=0 || y<=0 || x>=this->size().width() || y>=this->size().height() || this->collideWithSnake(x,y)) { 
        // завершение игры
        this->gameOver(); 
        return;
    };    

    // столкновение с яблоком
    auto [apple_x, apple_y] = this->applePos;        
    if (x==apple_x && y==apple_y) {
        // перемещаем яблоко в другое место
        this->locateApple();
        // добавляем сегмент к телу змеи
        this->extendBody();
    }
}

/// @brief Проверяет, пересекается ли точка с одним из сегментов змеи (кроме первого)
/// @param x абсцисса точки
/// @param y Ордината точки
/// @return 
bool Window::collideWithSnake(int x, int y)
{
    for (int idx=1;idx<this->snakePos.size();++idx) {
        auto [body_x, body_y] = this->snakePos[idx];
        if (x==body_x && y==body_y) {
            return true;
        }
    }
    return false;
}

/// @brief Добавляет сегмент в конец тела змеи
void Window::extendBody()
{
    auto [x,y] = this->snakePos[this->snakePos.size()-1];
    this->snakePos.push_back({x+COL_WIDTH, y});
}

/// @brief Завершает игру
void Window::gameOver() {
    // Останавливаем таймер
    this->timer->stop();
    // Устанавливаем флаг что игра завершена
    this->isGameOver = true;
    // Перерисовываем экран
    this->repaint();
}