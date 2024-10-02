#pragma once

#include "../build/export_shared.h"

typedef double real;

#ifdef __cplusplus 
extern "C"
{
#endif

// Структура для привязки объекта класса Matrix
typedef struct Matrix Matrix;

// Создание матрицы
Matrix * MATRIXLIB_EXPORT math_createMatrix(int rows, int cols);

// Удаление матрицы
void MATRIXLIB_EXPORT math_deleteMatrix(Matrix* M);

// Получение значения матрицы по указанным строке и столбцу
real MATRIXLIB_EXPORT math_get(const Matrix *M, int row, int col);

// Установка значения матрицы по указанным строке и столбцу
void MATRIXLIB_EXPORT math_set(Matrix *M, int row, int col, real val);

// Сложение матриц
Matrix * MATRIXLIB_EXPORT math_add(const Matrix *A, const Matrix *B);

// Вычитание матриц
Matrix * MATRIXLIB_EXPORT math_sub(const Matrix *A, const Matrix *B);

// Умножение матриц
Matrix * MATRIXLIB_EXPORT math_mul(const Matrix *A, const Matrix *B);

// Вывод матрицы в стандартный поток вывода
void MATRIXLIB_EXPORT math_print(const Matrix *M);

#ifdef __cplusplus 
}
#endif