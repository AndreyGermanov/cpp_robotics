#pragma once
#include <QWidget>
#include <QTimer>

using namespace std;

/// @brief Класс основного окна приложения
class Window : public QWidget {
Q_OBJECT    
private:    
    // Текущее направления движения змеи (UP, DOWN, LEFT, RIGHT)
    int direction;
    // Объект таймера, через который реализуется основной цикл игры
    QTimer *timer;
    // Изображения
    // Фон
    QPixmap bg_image;
    // Яблоко
    QPixmap apple_image;
    // Фрагмент тела змеи
    QPixmap snake_image;
    // Голова змеи направленная влево
    QPixmap snake_head_left;
    // Голова змеи направленная вправо
    QPixmap snake_head_right;
    // Голова змеи направленная вниз
    QPixmap snake_head_down;
    // Голова змеи направленная ввер
    QPixmap snake_head_up;
    // Координаты яблока (x,y)
    pair<int,int> applePos;
    // Координаты всех сегментов змеи.
    // Первый сегмент это голова
    vector<pair<int,int>> snakePos;
    // Признак того, что игра завершена
    bool isGameOver;
    // Метод загрузки изображений из файлов
    void loadImages();
    // Метод проверяет столкновения змеи с другими объектами
    void checkCollisions();
    // Метод проверяет столкновение указанной точки со змеей
    bool collideWithSnake(int x, int y);
    // Метод запускающий игру
    void initGame();
    // Метод размещает яблоко на поле
    void locateApple();
    // Метод завершающий игру
    void gameOver();
    // Метод увеличивает размер змеи на один сегмент
    void extendBody();
    // Метод меняет направление змеи в зависимости от
    // нажатой клавиши
    void move(int key);
private slots:
    // Метод обработки события таймера
    void on_timeout();
protected:
    // Метод обработки нажатия клавиши на клавиатуре
    void keyPressEvent(QKeyEvent *e);
    // Метод перерисовки содержимого окна
    void paintEvent(QPaintEvent *e);
public:
    // Основной конструктор окна
    Window(QWidget *parent = 0);
};