/**
 * @file InputValidator.hpp
 * @author Jorge Meneses (j.menesesgarro@gmail.com)
 * @brief Clase de validacion de entradas de datos y dimensiones.
 * @version 1.0
 * @date 2024-05-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef INPUTVALIDATOR_HPP
#define INPUTVALIDATOR_HPP

#include <iostream>  
#include <string>
#include<complex>

using namespace std;

/**
 * @brief Clase encargada de validar la informacion ingresada por el ususario para construir y definir las matrices.
 * 
 * @tparam T Tipo de datos para los que se estaran revisando
 */
template <class T>
class InputValidator{
    public:
        /**
         * @brief Revisa cada elemento de la matriz ingresado por el usuario en fillMatrix() de la clase Matrix<T>.
         * 
         * Itera por todo el string de entrada para verificar si es un int, double o si en efecto es un string. Se lanza una excepcion runtime_error cuando el tipo de dato ingresado no sea compatible con la matriz.
         * 
         * @param num Elemento ingresado por el usuario.
         */
        void validateData(string num);
        /**
         * @brief Revisa las dimensiones ingresadas por el usuario para construir la funcion.
         * 
         * Revisa que las dimensiones sean numeros positivos. Caso contrario, lanza una excepcion runtime_error referente a dimensiones invalidas.
         * 
         * @param r Cantidad ingresada de filas ingresada por el usuario.
         * @param c Cantidad ingresada de columnas ingresada por el usuario.
         */
        void validateDimensions(int r, int c);
};

#endif