#include <iostream>
#include <memory>
using namespace std;

/// @brief Класс трехмерного вектора
class Vector3D {
    public:
        // Указатель на массив, в котором хранятся 3 значения
        unique_ptr<double[]> coords;
    
        /// @brief Конструктор по умолчанию
        Vector3D() {
            this->coords = make_unique<double[]>(3);
        };

        /// @brief Конструктор копирования
        /// @param arr Объект-источник
        /// @return 
        Vector3D(const Vector3D &arr) {
            this->coords = make_unique<double[]>(3);
            for (int idx=0; idx < 3; idx++) {
                this->coords.get()[idx] = arr.coords.get()[idx];
            }
        }

        /// @brief Оператор присваивания копированием
        /// @param arr Объект-источник
        /// @return 
        Vector3D operator=(const Vector3D &arr) {
            if (&arr == this) {
                return *this;
            }
            this->coords.reset(nullptr);
            this->coords = make_unique<double[]>(3);;
            for (int idx=0; idx < 3; idx++) {
                this->coords.get()[idx] = arr.coords.get()[idx];
            }
            return *this;
        }

        /// @brief Конструктор перемещения
        /// @param arr объект источник
        Vector3D(Vector3D &&arr) {
            this->coords = move(arr.coords);
        }

        /// @brief Оператор присваивания перемещением
        /// @param arr Объект-источник
        /// @return 
        Vector3D& operator=(Vector3D &&arr) {
            if (&arr == this) { return *this; }
            this->coords = move(arr.coords);            
            return *this;
        }

        /// @brief  Оператор получения значения вектора по индексу для изменения
        /// @param idx Индекс
        /// @return Значение по индексу
        double& operator[](int idx) { return this->coords.get()[idx]; }   

        /// @brief  Оператор получения значения вектора по индексу для чтения
        /// @param idx Индекс
        /// @return Значение по индексу
        const double& operator[](int idx) const { return this->coords.get()[idx]; }

        // Оператор печати вектора в поток вывода
        friend ostream& operator<<(ostream &os, const Vector3D &vec);
};

/// @brief Оператор печати вектора в поток вывода
/// @param os Ссылка на поток вывода
/// @param vec Ссылка на вектор
/// @return Поток вывода
ostream& operator<<(ostream &os, const Vector3D &vec) {
    os << vec[0] << "," << vec[1] << "," << vec[2];
    return os;
}

/// @brief Функция нормализвации вектора
/// @param vec Умный указатель на вектор
void normalize_vector(shared_ptr<Vector3D> vec) {
    double len = 0;
    // Вычисляем сумму элементов вектора
    for (int idx=0;idx<3;++idx) { len += (*vec)[idx]; };
    // Делим каждый элемент на сумму
    for (int idx=0;idx<3;idx++) { (*vec)[idx] /= len; }
    // Ничего не возвращаем, так как входящий вектор модифицируется
    // по указателю
}