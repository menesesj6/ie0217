#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Matrix{
    private:
        int rows, cols;
        vector<vector<T>> data;
    public:
        Matrix();
        ~Matrix();
        void setDimensiones(int rows, int columns);
        void fillMatrix();
        void display();
        Matrix operator+(const Matrix& other);
        Matrix operator-(const Matrix& other);
        Matrix operator*(const Matrix& other);
};


#endif