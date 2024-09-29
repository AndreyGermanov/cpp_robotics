#include <string>
#include <iostream>
#include "car.h"

using namespace cars;

/// @brief Конструктор по умолчанию
Car::Car() 
{
    this->brand_ = "";
    this->n_cylinders_ = 0;
    this->power_ = 0;
    // Увеличиваем общее количество объектов
    Car::count_ += 1;
}

/// @brief Основной конструктор
/// @param brand Имя брэнда
/// @param n_cylinders Количество цилиндров
/// @param power Мощность
Car::Car(std::string brand, int n_cylinders, int power):Car() 
{
    this->brand_ = brand;
    this->n_cylinders_ = n_cylinders;
    this->power_ = power;
}

/// @brief Конструктор копирования
/// @param car Указатель на объект-источник
Car::Car(const Car *car) : brand_(car->brand_),n_cylinders_(car->n_cylinders_),power_(car->power_) 
{
    Car::count_ += 1;
}

/// @brief Деструктор
Car::~Car()
{
    // Уменьшаем общее количество объектов
    Car::count_ -= 1;
}

/// @brief Вспомогательная функция, которая пишет информацию о полях объекта в поток вывода
/// @param out Ссылка на поток вывода
void Car::write_params(std::ostream &out) const
{
    out << "Брэнд: " << this->brand_ << ", " 
        << "Количество цилиндров: " << this->n_cylinders_ << ", " 
        << "Мощность: " << this->power_;
}

/// @brief Вспомогательная функция, которая пишет объект в поток вывода
/// @param out Поток вывода
void Car::write(std::ostream &out) const
{
    out << this->getClassName() << "(";
    this->write_params(out);
    out << ")" << std::endl;
}

/// @brief Вспомогательная функция, которая возвращает строковое название класса
/// @return Название класса
std::string Car::getClassName() const { return "Car"; }

/// @brief Вспомогательная функция, которая читает объект из потока ввода
/// @param in Ссылка на поток ввода
void Car::read(std::istream &in)
{
    in >> this->brand_;
    in >> this->n_cylinders_;
    in >> this->power_;
}

/// @brief Оператор вывода объекта в поток вывода
/// @param out Ссылка на поток вывода
/// @param car Объект из которого брать данные для вывода
/// @return 
std::ostream &cars::operator<<(std::ostream &out, const Car &car)
{
    car.write(out);
    return out;    
}

/// @brief Оператор вывода объекта в поток вывода если передан указатель на объект
/// @param out Ссылка на поток вывода
/// @param car Указатель на объект из которого брать данные для вывода
/// @return 
std::ostream &cars::operator<<(std::ostream &out, const Car *car)
{
    car->write(out);
    return out;    
}

/// @brief Оператор чтения объекта из потока ввода
/// @param in Ссылка на поток ввода
/// @param car Объект, в который нужно читать данные
/// @return Поток ввода
std::istream &cars::operator>>(std::istream &in, Car &car)
{
    car.read(in);
    return in;    
}

/// @brief Оператор чтения объекта из потока ввода если передан указатель на объект
/// @param in Ссылка на поток ввода
/// @param car Объект, в который нужно читать данные
/// @return Поток ввода
std::istream &cars::operator>>(std::istream &in, Car *car)
{
    car->read(in);
    return in;    
}

/// @brief Оператор присваивания
/// @param car Объект-источник
Car &cars::Car::operator=(Car &car)
{
    this->brand_ = car.brand_;
    this->n_cylinders_ = car.n_cylinders_;
    this->power_ = car.power_;
    return *this;
}

// Геттеры и сеттеры
std::string Car::getBrand() { return this->brand_; }
void Car::setBrand(std::string brand) { this->brand_ = brand; }
int Car::getPower() { return this->power_; };
void Car::setPower(int power) { this->power_ = power; }
int Car::getCylinders() { return this->n_cylinders_; };
void Car::setCylinders(int cylinders) { this->n_cylinders_ = cylinders; };

/// @brief Функция возвращает общее количество созданных объектов
/// @return 
int cars::count() {
    return Car::count_;
}