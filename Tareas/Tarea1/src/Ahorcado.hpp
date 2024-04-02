/**
 * @file Ahorcado.hpp
 * @author Jorge A. Meneses Garro (j.menesesgarro@gmail.com.com)
 * @brief Creacion de struct del juego Ahorcado y los enums para los menus
 * @version 1.0
 * @date 2024-04-3
 * @copyright Copyright (c) 2024
 */
#ifndef AHORCADO_H
#define AHORCADO_H

/**
 * @brief Macro que define la cantidad maxima de palabras en el diccionario
 */
#define MAX_DICTIONARY 50

/**
 * @brief Macro que define el largo maximo del status de la palabra
 */
#define MAX_LENGTH_WORD 30


#include <iostream>
#include <string>
#include <random>
#include <cstdlib>

using namespace std;

/**
 * @brief Enumeracion con las opciones del menu principal
 * Se asignan las opciones 1 a 5 asociados a las opciones del menu principal programado, para la facilidad de programacion
 */
enum Options {
    DIFICULTAD = 1,
    INICIAR,
    AGREGAR,
    DICCIONARIO,
    SALIR
};

/**
 * @brief Enumeracion con las opciones del menu de dificultades
 * Se asignan las opciones 1 a 3 asociados a las opciones de dificultad del juego. Esto se asociara con la cantidad de intentos maximos que tendra el usuario 
 */
enum Difficulties {
    EASY = 1,
    MEDIUM,
    HARD
};

/**
 * @brief Struct del juego Ahorcado
 * Una instanciacion de este struct abre un juego, para poder acceder a sus miembros mas sencillamente
 */
struct Ahorcado{
    string word; /**< Palabra a adivinar*/
    char wordStatus[MAX_LENGTH_WORD]; /**< EStado de la palabra, incluyendo letras adivinadas y por adivinar*/
    int maxTries; /**< Numero de intentos maximos, depende de la dificultad*/
    int remainingTries; /**< Intentos restantes, van bajando uno con cada letra ingresada por el usuario*/
};

#endif // HEADER_H