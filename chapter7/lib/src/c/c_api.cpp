#include "c_api.h"
#include "../matrix.h"

/// @brief Структура для привязки объекта Matrix
struct Matrix : public matrix::Matrix {
public:
    Matrix(const struct matrix::Matrix &M) : matrix::Matrix(M) {}
};

/// @brief Создание матрицы
/// @param rows Количество строк
/// @param cols Количество столбцов
/// @return Объект Matrix
Matrix MATRIXLIB_EXPORT *math_createMatrix(int rows, int cols)
{
    return new Matrix(matrix::Matrix(rows, cols));
}

/// @brief Удаление матрицы
/// @param M Указатель на матрицу
/// @return 
void MATRIXLIB_EXPORT math_deleteMatrix(Matrix *M)
{
    delete M;
}

/// @brief Получение значения элемента матрицы
/// @param M Указатель на матрицу
/// @param row Номер строки
/// @param col Номер столбца
/// @return Значение по указанному адресу
real MATRIXLIB_EXPORT math_get(const Matrix *M, int row, int col)
{
    return M->operator()(row, col);
}

/// @brief Установка значения элемента матрицы
/// @param M Указатель на матрицу
/// @param row Номер строки
/// @param col Номер столбца
/// @param val Значение для установки
/// @return 
void MATRIXLIB_EXPORT math_set(Matrix *M, int row, int col, real val)
{
    M->operator()(row, col) = val;
}

/// @brief Сложение матриц
/// @param A Указатель на первую матрицу
/// @param B Указатель на вторую матрицу
/// @return Матрица результат сложения
Matrix * MATRIXLIB_EXPORT math_add(const Matrix *A, const Matrix *B)
{
    return new Matrix(*A+*B);
}

/// @brief Вычитание матриц
/// @param A Указатель на первую матрицу
/// @param B Указатель на вторую матрицу
/// @return Матрица результат вычитания
Matrix * MATRIXLIB_EXPORT math_sub(const Matrix *A, const Matrix *B)
{
    return new Matrix(*A-*B);
}

/// @brief Умножение матриц
/// @param A Указатель на первую матрицу
/// @param B Указатель на вторую матрицу
/// @return Матрица результат умножения
Matrix * MATRIXLIB_EXPORT math_mul(const Matrix *A, const Matrix *B)
{
    return new Matrix(*A * *B);
}

/// @brief Вывод матрицы в стандартный поток вывода
/// @param M Указатель на матрицу
/// @return 
void MATRIXLIB_EXPORT math_print(const Matrix *M)
{   
    M->print();
}
