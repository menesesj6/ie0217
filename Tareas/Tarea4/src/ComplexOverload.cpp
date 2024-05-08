#include "ComplexOverload.hpp"

template <class T>
Complex<T> Complex<T>::operator+=(const Complex<T>& other){
    Matriz<T> result = (this->real() + other.real(), this->imag() + other.imag());
    return result;
};