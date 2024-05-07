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
template void BasicOperations<int>::validateSumSub(Matrix<int>& a, Matrix<int>& b);
template void BasicOperations<float>::validateSumSub(Matrix<float>& a, Matrix<float>& b);
template void BasicOperations<complex<float>>::validateSumSub(Matrix<complex<float>>& a, Matrix<complex<float>>& b);
//template void BasicOperations<complex<int>>::validateSumSub(Matrix<complex<int>>& a, Matrix<complex<int>>& b);

template void BasicOperations<int>::validateMultiplication(Matrix<int>& a, Matrix<int>& b);
template void BasicOperations<float>::validateMultiplication(Matrix<float>& a, Matrix<float>& b);
template void BasicOperations<complex<float>>::validateMultiplication(Matrix<complex<float>>& a, Matrix<complex<float>>& b);
//template void BasicOperations<complex<int>>::validateMultiplication(Matrix<complex<int>>& a, Matrix<complex<int>>& b);

template Matrix<int> BasicOperations<int>::sum(Matrix<int>& a, Matrix<int>& b);
template Matrix<float> BasicOperations<float>::sum(Matrix<float>& a, Matrix<float>& b);
template Matrix<complex<float>> BasicOperations<complex<float>>::sum(Matrix<complex<float>>& a, Matrix<complex<float>>& b);
//template Matrix<complex<int>> BasicOperations<complex<int>>::sum(Matrix<complex<int>>& a, Matrix<complex<int>>& b);

template Matrix<int> BasicOperations<int>::sub(Matrix<int>& a, Matrix<int>& b);
template Matrix<float> BasicOperations<float>::sub(Matrix<float>& a, Matrix<float>& b);
template Matrix<complex<float>> BasicOperations<complex<float>>::sub(Matrix<complex<float>>& a, Matrix<complex<float>>& b);
//template Matrix<complex<int>> BasicOperations<complex<int>>::sub(Matrix<complex<int>>& a, Matrix<complex<int>>& b);

template Matrix<int> BasicOperations<int>::mult(Matrix<int>& a, Matrix<int>& b);
template Matrix<float> BasicOperations<float>::mult(Matrix<float>& a, Matrix<float>& b);
template Matrix<complex<float>> BasicOperations<complex<float>>::mult(Matrix<complex<float>>& a, Matrix<complex<float>>& b);
//template Matrix<complex<int>> BasicOperations<complex<int>>::mult(Matrix<complex<int>>& a, Matrix<complex<int>>& b);