/**
 * @file BasicOperations.hpp
 * @author Jorge Meneses (j.menesesgarro@gmail.com)
 * @brief Clase de validacion y realizacion de operaciones basicas de matrices.
 * @version 1.0
 * @date 2024-05-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef BASICOPS_HPP
#define BASICOPS_HPP
#include "Matrix.hpp"

/**
 * @brief Clase encargada de validar y realizar las operaciones suma, resta y multiplicacion para matrices.
 * 
 * @tparam T Tipo de datos sobre los que se estaran operando. 
 */
template <class T>
class BasicOperations{ 
    public:
        /**
         * @brief Se encarga de verificar si es valido realizar una suma o resta.
         * 
         * Para la validez de suma o resta en matrices se necesita que sus dimensiones sean iguales, se lanza una excepcion runtime_error en caso de invalidez de la operacion.
         * 
         * @param a Primera matriz de la operacion.
         * @param b Segunda matriz de la operacion.
         */
        void validateSumSub(Matrix<T>& a, Matrix<T>& b);
        /**
         * @brief Se encarga de verificar si es valido realizar una multiplicacion.
         * 
         * Para la validez de suma o resta en matrices se necesita la cantidad de columnas de a sea igual a las filas de b; se lanza una excepcion runtime_error en caso de invalidez de la operacion.
         * 
         * @param a Primera matriz de la operacion.
         * @param b Segunda matriz de la operacion.
         */
        void validateMultiplication(Matrix<T>& a, Matrix<T>& b);
        /**
         * @brief Realiza la suma de matrices.
         * 
         * @param a Primera matriz de la operacion.
         * @param b Segunda matriz de la operacion.
         * @return Matrix<T> Matriz resultante de la suma.
         */
        Matrix<T> sum(Matrix<T>& a, Matrix<T>& b);
        /**
         * @brief Realiza la resta de matrices.
         * 
         * @param a Realiza la suma de matrices.
         * @param b Realiza la suma de matrices.
         * @return Matrix<T> Matriz resultante de la resta.
         */
        Matrix<T> sub(Matrix<T>& a, Matrix<T>& b);
        /**
         * @brief Realiza la multiplicacion de matrices.
         * 
         * @param a Realiza la resta de matrices.
         * @param b Realiza la resta de matrices.
         * @return Matrix<T> Matriz resultante de la multiplicacion.
         */
        Matrix<T> mult(Matrix<T>& a, Matrix<T>& b);
};

#endif