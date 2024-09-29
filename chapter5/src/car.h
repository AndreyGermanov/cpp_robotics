#pragma once
#include <string>
#include <iostream>

// Пространство имен
namespace cars {
    // Класс машин
    class Car
    {
    private:
        // Название брэнда
        std::string brand_;
        // Количество цилиндров
        int n_cylinders_;
        // Мощность
        int power_;
        // Общее количество созданных объектов
        inline static int count_ = 0;
    public:
        // Конструктор по умолчанию
        Car();
        // Основной конструктор
        Car(std::string brand, int n_cylinders, int power);
        // Конструктор копирования
        Car(const Car *car);
        // Деструктор
        ~Car();       
        // Геттеры и сеттеры
        std::string getBrand();
        void setBrand(std::string brand);        
        int getCylinders();
        void setCylinders(int cylinders);
        int getPower();
        void setPower(int power);
        // Оператор вывода если объект передан по ссылке
        friend std::ostream& operator<< (std::ostream &out, const Car &car);
        // Оператор вывода если передан указатель на объект
        friend std::ostream& operator<< (std::ostream &out, const Car *car);
        // Оператор ввода если объект передан по ссылке
        friend std::istream& operator>> (std::istream &in, Car &car);
        // Оператор ввода если передан указатель на объект
        friend std::istream& operator>> (std::istream &in, Car *car);
        // Оператор присваивания
        Car& operator= (Car &car);
        // Метод возвращает общее количество созданных объектов
        friend int count();
    protected:
        // Читает объект и потока ввода
        void read(std::istream &in);
        // Пишет объект в поток вывода
        void write(std::ostream &out) const;
        // Пишет поля объекта в поток вывода
        virtual void write_params(std::ostream &out) const;
        // Возвращает название текущего класса
        virtual std::string getClassName() const;
    };

    // Оператор вывода если объект передан по ссылке
    std::ostream& operator<< (std::ostream &out, const Car *car);
    // Оператор вывода если передан указатель на объект
    std::ostream& operator<< (std::ostream &out, const Car &car);
    // Оператор ввода если объект передан по ссылке
    std::istream& operator>> (std::istream &in, Car &car);
    // Оператор ввода если передан указатель на объект
    std::istream& operator>> (std::istream &in, Car *car);
    // Возвращает общее количество созданных объектов
    int count();
}