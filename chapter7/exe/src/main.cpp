#include <iostream>

// Определение структуры Matrix для привязке к объектам 
// класса Matrix, импортируемого из библиотеки
struct Matrix;

#ifdef __cplusplus
extern "C"
{
#endif    

// Функции, импортируемые из динамической библиотеки

// Создание матрицы
Matrix * math_createMatrix(int rows, int cols);

// Удаление матрицы
void math_deleteMatrix(Matrix* M);

// Получение значения элемента
double math_get(const Matrix *M, int row, int col);

// Установка значения элемента
void math_set(Matrix *M, int row, int col, double val);

// Сложение матриц
Matrix * math_add(const Matrix *A, const Matrix *B);

// Вычитание матриц
Matrix * math_sub(const Matrix *A, const Matrix *B);

// Умножение матриц
Matrix * math_mul(const Matrix *A, const Matrix *B);

// Вывод матрицы в стандартный поток вывода
void math_print(const Matrix *M);

#ifdef __cplusplus
}
#endif

using namespace std;

int main() {

    // Создаем первую матрицу
    Matrix *m = math_createMatrix(3,3);

    // устанавливаем ее элементы
    math_set(m, 0, 0, 2.0);
    math_set(m, 1, 1, 2.0);

    cout << "Матрица m" << endl;            
    // Вывод матрицы на экран
    math_print(m);

    // Создаем вторую матрицу
    Matrix *m1 = math_createMatrix(3,3);

    // устанавливаем ее элементы
    math_set(m1, 0, 0, 5.0);
    math_set(m1, 1, 1, 5.0);

    cout << "Матрица m1" << endl;        
    // Вывод матрицы на экран
    math_print(m1);

    // Сложение матриц
    Matrix *m2 = math_add(m,m1);
    cout << "Матрица m+m1" << endl;       
    math_print(m2);

    // Вычитание матриц
    Matrix *m3 = math_sub(m,m1);
    cout << "Матрица m-m1" << endl;       
    math_print(m3);

    // Умножение матриц
    Matrix *m4 = math_mul(m,m1);
    cout << "Матрица m*m1" << endl;       
    math_print(m4);

    // Удаление матриц
    math_deleteMatrix(m);
    math_deleteMatrix(m1);
    math_deleteMatrix(m2);
    math_deleteMatrix(m3);
    math_deleteMatrix(m4);
    
    return 0;
}