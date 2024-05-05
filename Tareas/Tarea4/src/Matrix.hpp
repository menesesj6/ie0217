#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <vector>
#include <complex>
#include <string>
#include "InputValidator.hpp"

using namespace std;

template <class T>
class Matrix{
    private:
        int rows, cols;
        vector<vector<T>> data;
    public:
        InputValidator<T> checker;
        Matrix(int r, int c);
        ~Matrix();
        void setDimensiones(int rows, int columns);
        void fillMatrix();
        void randomFillMatrix();
        void display();
        Matrix<T> operator+(const Matrix<T>& other);
        Matrix<T> operator-(const Matrix<T>& other);
        Matrix<T> operator*(const Matrix<T>& other);
};


#endif