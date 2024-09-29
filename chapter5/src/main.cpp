#include <iostream>
#include "car.h"
#include "lorry.h"
#include <string>

using namespace cars;

int main()
{

    std::cout << "ОПЕРАЦИИ С КЛАССОМ CAR" << std::endl;

    // Создаем автомобиль
    auto car1 = new Car("Mitsubishi",16,210);
    // Вывод в стандартный поток вывода
    std::cout << "Основной конструктор: " << car1 << std::endl;

    // Вывод количества объектов
    std::cout << "Общее количество объектов (должно быть 1): " << count() << std::endl;

    // Использование сеттеров
    car1->setCylinders(20);
    car1->setPower(300);
    car1->setBrand("Land Rower");

    // Использование геттеров
    std::cout << "Использование геттеров и сеттеров: "
        << car1->getBrand() << ", " 
        << car1->getCylinders() << ", " 
        << car1->getPower() 
        << std::endl;

    // Присваивание объектов
    auto car2 = new Car();
    *car2 = *car1;
    std::cout << "Присваивание объекта: " << car2 << std::endl;
    
    // Вывод количества объектов
    std::cout << "Общее количество объектов (должно быть 2): " << count() << std::endl;

    // Использование конструктора копирования
    auto car3 = new Car(car2);
    std::cout << "Копирование объекта: " << car3 << std::endl;
    
    // Вывод количества объектов
    std::cout << "Общее количество объектов (должно быть 3): " << count() << std::endl;

    // Чтение объекта из стандартного ввода
    Car *car4 = new Car();
    std::cin >> car4;
    std::cout << "Чтение объекта из стандартного ввода: " << car4 << std::endl;

    // Вывод количества объектов
    std::cout << "Общее количество объектов (должно быть 4): " << count() << std::endl;

    // Уничтожение объекта 
    delete car1;

    // Вывод количества объектов
    std::cout << "Общее количество объектов (должно быть 3): " << count() << std::endl;

    std::cout << "ОПЕРАЦИИ С КЛАССОМ LORRY" << std::endl;

    // Создаем грузовик
    Lorry *lorry1 = new Lorry("Caterpillar",16,210,1000);
    // Вывод в стандартный поток вывода
    std::cout << "Основной конструктор: " << lorry1 << std::endl;

    // Вывод количества объектов
    std::cout << "Общее количество объектов (должно быть 4): " << count() << std::endl;

    // Использование сеттеров
    lorry1->setCylinders(20);
    lorry1->setPower(300);
    lorry1->setBrand("Kamaz");
    lorry1->setLoadCapacity(2000);

    // Использование геттеров
    std::cout << "Использование геттеров и сеттеров: "
        << lorry1->getBrand() << ", " 
        << lorry1->getCylinders() << ", " 
        << lorry1->getPower() << ", "
        << lorry1->getLoadCapacity()
        << std::endl;

    // Присваивание объектов
    Lorry *lorry2 = new Lorry();
    *lorry2 = *lorry1;
    std::cout << "Присваивание объекта: " << lorry2 << std::endl;
    
    // Вывод количества объектов
    std::cout << "Общее количество объектов (должно быть 5): " << count() << std::endl;

    // Использование конструктора копирования
    Lorry *lorry3 = new Lorry(lorry2);
    std::cout << "Копирование объекта: " << lorry3 << std::endl;
    
    // Вывод количества объектов
    std::cout << "Общее количество объектов (должно быть 6): " << count() << std::endl;

    // Чтение объекта из стандартного ввода
    Lorry *lorry4 = new Lorry();
    std::cin >> lorry4;
    std::cout << "Чтение объекта из стандартного ввода: " << lorry4 << std::endl;

    // Вывод количества объектов
    std::cout << "Общее количество объектов (должно быть 7): " << count() << std::endl;

    // Уничтожение объекта 
    delete lorry1;

    // Вывод количества объектов
    std::cout << "Общее количество объектов (должно быть 6): " << count() << std::endl;
}