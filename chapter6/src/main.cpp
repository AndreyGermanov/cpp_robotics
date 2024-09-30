#include "matrix.h"
#include <iostream>

int main() {
    matrix::Matrix m(3,3);
    m(0,0) = 2.;
    m(1,1) = 2.;
    matrix::Matrix m1(3,3);
    std::cout << "Введите по порядку элементы матрицы m1 (3x3)" << std::endl;
    std::cin >> m1;
    std::cout << "Matrix m is:" << std::endl << m << std::endl;
    std::cout << "Matrix m1 is:" << std::endl << m1 << std::endl;
    m += m1;    
    std::cout << "Matrix m+=m1 is:" << std::endl << m << std::endl;
    m *= m1;
    std::cout << "Matrix m*=m1 is:" << std::endl << m << std::endl;
    m -= m1;
    std::cout << "Matrix m-=m1 is:" << std::endl << m << std::endl;
    return 0;
}