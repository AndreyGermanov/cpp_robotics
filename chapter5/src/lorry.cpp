#include <string>
#include "lorry.h"
#include "car.h"

using namespace cars;

/// @brief Конструктор по умолчанию
Lorry::Lorry():Car() {
    this->load_capacity_ = 0;
}

/// @brief Основной конструктор
/// @param brand Имя брэнда
/// @param n_cylinders Количество цилиндров
/// @param power Мощность
/// @param load_capacity Грузоподъемность
Lorry::Lorry(std::string brand, int n_cylinders, int power, int load_capacity):Car(brand,n_cylinders,power)
{
    this->load_capacity_ = load_capacity;
}

/// @brief Конструктор копирования
/// @param lorry Указатель на объект источник
Lorry::Lorry(const Lorry *lorry): Car(lorry) , load_capacity_(lorry->load_capacity_) { }

/// @brief Вспомогательный метод, выводящий поля объекта в поток вывода
/// @param out Ссылка на поток вывода
void Lorry::write_params(std::ostream &out) const
{
    // сначала выводим поля класса-предка
    this->Car::write_params(out);
    // и добавляем поля, уникальные для данного объекта
    out << ", " << "Грузоподъемность: " << this->load_capacity_;
}

/// @brief Вспомогательная функция для чтения объекта из потока ввода
/// @param in Ссылка на поток ввода
void Lorry::read(std::istream &in)
{
    // Сначала читаем поля класса-предка
    this->Car::read(in);
    // И добавляем поля уникальные для данного класса
    in >> this->load_capacity_;
}

/// @brief Вспомогательная функция, которая возвращает строковое название класса
/// @return Название класса
std::string Lorry::getClassName() const { return "Lorry"; }

/// @brief Оператор вывода объекта в поток вывода
/// @param out Ссылка на поток вывода
/// @param lorry Объект из которого брать данные для вывода
/// @return 
std::ostream &cars::operator<<(std::ostream &out, const Lorry &lorry)
{
    lorry.write(out);
    return out;    
}

/// @brief Оператор вывода объекта в поток вывода если передан указатель на объект
/// @param out Ссылка на поток вывода
/// @param lorry Указатель на объект из которого брать данные для вывода
/// @return 
std::ostream &cars::operator<<(std::ostream &out, const Lorry *lorry)
{
    lorry->write(out);
    return out;    
}

/// @brief Оператор чтения объекта из потока ввода
/// @param in Ссылка на поток ввода
/// @param lorry Объект в который записывать прочитанные данные
/// @return 
std::istream &cars::operator>>(std::istream &in, Lorry &lorry)
{        
    lorry.read(in);
    return in;
}

/// @brief Оператор чтения объекта из потока ввода если передан указатель на объект
/// @param in Ссылка на поток ввода
/// @param lorry Объект в который записывать прочитанные данные
/// @return 
std::istream &cars::operator>>(std::istream &in, Lorry *lorry)
{        
    lorry->read(in);
    return in;
}

/// @brief Оператор присванивания
/// @param lorry 
/// @return 
Lorry& Lorry::operator=(Lorry &lorry) 
{    
    // Вызываем метод предка для присваивания базовых свойств
    lorry.Car::operator=(lorry);
    // и добавляем уникальные для данного класса поля
    this->load_capacity_ = lorry.load_capacity_;
    return *this;
}

// Геттеры и сеттеры
int Lorry::getLoadCapacity() { return this->load_capacity_; }
void Lorry::setLoadCapacity(int capacity) { this->load_capacity_ = capacity; }