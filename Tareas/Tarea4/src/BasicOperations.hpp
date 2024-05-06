#ifndef BASICOPS_HPP
#define BASICOPS_HPP
#include "Matrix.hpp"

template <class T>
class BasicOperations{ 
    public:
        void validateSumSub(Matrix<T>& a, Matrix<T>& b);
        void validateMultiplication(Matrix<T>& a, Matrix<T>& b);
        Matrix<T> sum(Matrix<T>& a, Matrix<T>& b);
        Matrix<T> sub(Matrix<T>& a, Matrix<T>& b);
        Matrix<T> mult(Matrix<T>& a, Matrix<T>& b);
};

#endif