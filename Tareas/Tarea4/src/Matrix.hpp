#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <vector>
#include <complex>
#include <typeinfo>
#include <type_traits>
using namespace std;

template <class T>
class Matrix{
    private:
        int rows, cols;
        vector<vector<T>> data;
    public:
        Matrix(int r, int c);
        ~Matrix();
        void setDimensiones(int rows, int columns);
        void fillMatrix();
        void display();
        Matrix<T> operator+(const Matrix<T>& other);
        Matrix<T> operator-(const Matrix<T>& other);
        Matrix<T> operator*(const Matrix<T>& other);
};


#endif