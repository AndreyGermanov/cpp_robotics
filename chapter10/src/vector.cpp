#include <vector>
#include "math.h"
#include <string> 
#include <iostream> 
#include <sstream> 
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/operators.h>

using namespace std;

/// @brief Класс вектора
class Vector
{
private:
    // Вектор хранится в стандартном контейнере std::vector
    std::vector<double> vec_;
public:
    // Конструктор по умолчанию
    Vector(): vec_({}) {};
    
    /// @brief Основной конструктор
    /// @param vec 
    Vector(const vector<double> &vec) : vec_(vec) {};

    /// @brief Функция возвращает евклидову норму вектора
    /// @return Евклидова норма вектора
    double norm() const
    {
        double sum = 0;
        for (double item: this->vec_) { sum += item*item; }
        return sqrt(sum);
    }

    /// @brief Функция нормализует вектор in-place
    void normalize()
    {
        double len = this->norm();
        for (double &item : this->vec_) {
            item /= len;
        }
    }

    /// @brief Функция возвращает строковое представление вектора
    /// @return Строка
    string to_string() const
    {
        std::stringstream buffer;
        buffer << *this;
        return buffer.str();
    }

    // Оператор сложения векторов
    friend Vector operator+(const Vector& A, const Vector& B);
    // Оператор вычитания векторов
    friend Vector operator-(const Vector& A, const Vector& B);
    // Оператор скалярного произведения векторов
    friend double operator*(const Vector& A, const Vector& B);
    // Оператор печати объекта в поток вывода
    friend std::ostream& operator<<(std::ostream &os, const Vector &other);
};

/// @brief Оператор сложения векторов
/// @param A Первый вектор
/// @param B Второй вектора
/// @return Итоговыф вектор
Vector operator+(const Vector& A, const Vector& B)
{
    if ((A.vec_.size() != B.vec_.size()))
    {
        std::cerr << "Vector: Vectors can't be added" << std::endl;
        return Vector();
    }
    Vector M = Vector(vector<double>(A.vec_.size(),0));
    for (int idx=0;idx<A.vec_.size();++idx) {
        M.vec_.at(idx) = A.vec_.at(idx) + B.vec_.at(idx);
    }
    return M;
}

/// @brief Оператор вычитания векторов
/// @param A Первый вектор
/// @param B Второй вектор
/// @return Итоговый вектор
Vector operator-(const Vector& A, const Vector& B)
{
    if ((A.vec_.size() != B.vec_.size()))
    {
        std::cerr << "Vector: Vectors can't be subtracted" << std::endl;
        return Vector();
    }
    Vector M = Vector(vector<double>(A.vec_.size(),0));
    for (int idx=0;idx<A.vec_.size();++idx) {
        M.vec_.at(idx) = A.vec_.at(idx) - B.vec_.at(idx);
    }
    return M;
}

/// @brief Оператор скалярного произведения векторов
/// @param A Первый вектор
/// @param B Второй вектор
/// @return Итоговый вектор
double operator*(const Vector& A, const Vector& B)
{
    if ((A.vec_.size() != B.vec_.size()))
    {
        std::cerr << "Vector: Vectors can't be multiplied" << std::endl;
        return -1.;
    }
    double result = 0;
    for (int idx = 0;idx<A.vec_.size();++idx)
    {
        result += A.vec_.at(idx) * B.vec_.at(idx);
    }
    return result;    
}

/// @brief Оператор печати вектора в поток вывода
/// @param os Ссылка на поток вывода
/// @param self Вектор-источник
/// @return Поток вывода
std::ostream& operator<<(std::ostream &os, const Vector &self)
{
    for (double item: self.vec_) { os << item << " "; }
    os << std::endl;
    return os;
}

// Экспорт класса в модуль Python

namespace py = pybind11;

// Модуль будет называться "linalgebra"
PYBIND11_MODULE(linalgebra, m) {
    // Класс будет называться Vector
    py::class_<Vector>(m, "Vector")
        // Импорт конструктора
        .def(py::init<const vector<double>&>())
        // Импорт оператора сложения
        .def(py::self + py::self)
        // Импорт оператора вычитания
        .def(py::self - py::self)
        // Импорт оператора умножения, который выполняет скалярное произведение
        .def(py::self * py::self)        
        // Импорт функции евклидовой нормы вектора
        .def("norm", &Vector::norm)
        // Импорт функции нормализации вектора
        .def("normalize", &Vector::normalize)
        // Импорт функции для создания строкового представления объекта в Python
        // (для того чтобы выводить вектор с помощью функции "print")
        .def("__str__", &Vector::to_string);        
}