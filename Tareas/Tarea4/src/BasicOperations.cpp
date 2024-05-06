#include"BasicOperations.hpp"

template <class T>
void BasicOperations<T>::validateSumSub(Matrix<T>& a, Matrix<T>& b){
    if(a.rows != b.rows || a.cols != b.cols){
        throw runtime_error("ERROR: Imposile hacer la operacion. Dimensiones distintas.");
    } else{
        cout << "Operacion valida!" << endl;
    }
};

template <class T>
void BasicOperations<T>::validateMultiplication(Matrix<T>& a, Matrix<T>& b){
    if(a.cols != b.rows){
        throw runtime_error("ERROR: Imposile hacer la operacion. Dimensiones invalidas.");
    } else{
        cout << "Operacion valida!" << endl;
    }
};

template <class T>
Matrix<T> BasicOperations<T>::sum(Matrix<T>& a, Matrix<T>& b){
    validateSumSub(a, b);
    return a + b;
};

template <class T>
Matrix<T> BasicOperations<T>::sub(Matrix<T>& a, Matrix<T>& b){
    return a - b;
};

template <class T>
Matrix<T> BasicOperations<T>::mult(Matrix<T>& a, Matrix<T>& b){
    return a*b;
};


template void BasicOperations<int>::validateSumSub(Matrix<int>& a, Matrix<int>& b);
template void BasicOperations<float>::validateSumSub(Matrix<float>& a, Matrix<float>& b);

template void BasicOperations<int>::validateMultiplication(Matrix<int>& a, Matrix<int>& b);
template void BasicOperations<float>::validateMultiplication(Matrix<float>& a, Matrix<float>& b);

template Matrix<int> BasicOperations<int>::sum(Matrix<int>& a, Matrix<int>& b);
template Matrix<float> BasicOperations<float>::sum(Matrix<float>& a, Matrix<float>& b);

template Matrix<int> BasicOperations<int>::sub(Matrix<int>& a, Matrix<int>& b);
template Matrix<float> BasicOperations<float>::sub(Matrix<float>& a, Matrix<float>& b);

template Matrix<int> BasicOperations<int>::mult(Matrix<int>& a, Matrix<int>& b);
template Matrix<float> BasicOperations<float>::mult(Matrix<float>& a, Matrix<float>& b);