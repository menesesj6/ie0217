/**
 * @file BasicOperations.cpp
 * @author Jorge Meneses (j.menesesgarro@gmail.com)
 * @brief Definicion de los metodos de la clase BasicOperations
 * @version 1.0
 * @date 2024-05-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include"BasicOperations.hpp"

template <class T>
void BasicOperations<T>::validateSumSub(Matrix<T>& a, Matrix<T>& b){
    // Lanzar excepcion si las dimensiones no son las mismas
    if(a.rows != b.rows || a.cols != b.cols){
        throw runtime_error("ERROR: Imposile hacer la operacion. Dimensiones distintas.");
    }
};

template <class T>
void BasicOperations<T>::validateMultiplication(Matrix<T>& a, Matrix<T>& b){
    // Levantar excepcion si las columnas de la primera matriz es distinta de las columnas de la segunda
    if(a.cols != b.rows){
        throw runtime_error("ERROR: Imposile hacer la operacion. Dimensiones invalidas.");
    }
};

template <class T>
Matrix<T> BasicOperations<T>::sum(Matrix<T>& a, Matrix<T>& b){
    // Validar la operacion
    validateSumSub(a, b);
    // Retornar el resultado de la suma
    return a + b;
};

template <class T>
Matrix<T> BasicOperations<T>::sub(Matrix<T>& a, Matrix<T>& b){
    // Validar la operacion
    validateSumSub(a, b);
    // Retornar el resultado de la resta
    return a - b;
};

template <class T>
Matrix<T> BasicOperations<T>::mult(Matrix<T>& a, Matrix<T>& b){
    // Validar la operacion
    validateMultiplication(a, b);
    // Retornar el resultado de la multiplicacion
    return a*b;
};

// Solucion linking problems
template class BasicOperations<int>;
template class BasicOperations<float>;
template class BasicOperations<complex<float>>;
