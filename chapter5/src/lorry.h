#pragma once
#include <string>
#include "car.h"

namespace cars {
    // Класс грузовиков, унаследованный от класса машин
    class Lorry: public Car
    {
    private:
        // Грузоподъемность кузова
        int load_capacity_;
    public:
        // Конструктор по умолчанию
        Lorry();
        // Основной конструктор
        Lorry(std::string brand, int n_cylinders, int power, int load_capacity);
        // Конструктор копирования
        Lorry(const Lorry *lorry);
        // Геттеры и сеттеры
        int getLoadCapacity();
        void setLoadCapacity(int capacity);
        // Оператор присваивания
        Lorry& operator= (Lorry &lorry);
        // Оператор вывода если объект передан по ссылке
        friend std::ostream& operator<< (std::ostream &out, const Lorry &lorry);
        // Оператор вывода если передан указатель на объект
        friend std::ostream& operator<< (std::ostream &out, const Lorry *lorry);
        // Оператор ввода если объект передан по ссылке
        friend std::istream& operator>> (std::istream &in, Lorry &lorry);
        // Оператор ввода если передан указатель на объект
        friend std::istream& operator>> (std::istream &in, Lorry *lorry);
    protected:
        // Читает объект и потока ввода
        void read(std::istream &in);
        // Пишет поля объекта в поток вывода
        void write_params(std::ostream &out) const override;
        // Возвращает название текущего класса
        std::string getClassName() const override;
    };

    // Оператор вывода если объект передан по ссылке
    std::ostream& operator<< (std::ostream &out, const Lorry &lorry);
    // Оператор вывода если передан указатель на объект
    std::ostream& operator<< (std::ostream &out, const Lorry *lorry);
    // Оператор ввода если объект передан по ссылке
    std::istream& operator>> (std::istream &in, Lorry &lorry);
    // Оператор ввода если передан указатель на объект
    std::istream& operator>> (std::istream &in, Lorry *lorry);
}