/**
 * @file Matrix.hpp
 * @author Jorge Meneses (j.menesesgarro@gmail.com)
 * @brief Clase Matriz que define los objetos para la calculadora
 * @version 1.0
 * @date 2024-05-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <vector>
#include <complex>
#include <string>
#include <random>
#include "InputValidator.hpp"


using namespace std;

template <class T>
class Matrix{
    public:
        vector<vector<T>> data; /**<- Vector de vectores que contiene los elementos de la matriz*/
        int rows; /**<- Cantidad de filas de la matriz*/
        int cols; /**<- Cantidad de columnas de la matriz*/
        InputValidator<T> checker; /**<- Validador de datos*/
        /**
         * @brief Constructor de un objeto tipo Matriz<T>.
         * 
         * Invoca setDimentions() para validar y asignar los atributos dimensionales del objeto.
         * 
         * @param r Cantidad de filas.
         * @param c Cantidad de columnas.
         */
        Matrix(int r, int c);
        /**
         * @brief Destructor de un objeto tipo Matrix<T>.
         * 
         */
        ~Matrix();
        /**
         * @brief Encargado de  validar, asignar las dimensiones del objeto e inicializa la matriz con ceros.
         * 
         * Hace uso de checker para validar las dimensiones ingresadas, usa el puntero this para asignar los atributos e inicializa con ceros la matriz al iterar sobre esta.
         * 
         * @param rows 
         * @param columns 
         */
        void setDimensiones(int rows, int columns);
        /**
         * @brief Ingresar y asignar elementos de la matriz manualmente por el usuario.
         * 
         */
        void fillMatrix();
        /**
         * @brief Generar y asignar elementos aleatorios del tipo adecuado a cada elemento de la matriz.
         * 
         * Hace uso de la libreria random con random_device y dos distribuciones numericas uniformes para la generacion de numeros aleatorios no deterministicos.
         * Se hizo uso de uniform_int_distribution para los ints y uniform_real_distribution para floats, Ambos tipos en un rango de -100 a 100.
         * Para la creacion de numeros complejos aleatorios se generaron dos floats aleatorios y en base a eso se creaba el complejo.
         */
        void randomFillMatrix(int type);
        /**
         * @brief Imprime la matriz en pantalla.
         * 
         */
        void display();
        /**
         * @brief Sobrecarga para la suma de matrices.
         * 
         * @param other Segunda matriz de la operacion.
         * @return Matrix<T> Matriz resultante de la suma.
         */
        Matrix<T> operator+(const Matrix<T>& other);
        /**
         * @brief Sobrecarga para la resta de matrices.
         * 
         * @param other Segunda matriz de la operacion.
         * @return Matrix<T> Matriz resultante de la resta.
         */
        Matrix<T> operator-(const Matrix<T>& other);
        /**
         * @brief Sobrecarga para la multiplicacion de matrices.
         * 
         * @param other Segunda matriz de la operacion.
         * @return Matrix<T> Matriz resultante de la resta.
         */
        Matrix<T> operator*(const Matrix<T>& other);
};


#endif