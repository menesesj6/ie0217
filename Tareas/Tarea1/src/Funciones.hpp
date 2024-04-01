/**
 * @file Funciones.hpp
 * @author Jorge A. Meneses Garro (j.menesesgarro@gmail.com.com)
 * @brief Header file con los prototipos de las funciones
 * @version 1.0
 * @date 2024-04-3
 */
#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "Ahorcado.hpp"

/**
 * @brief Configura dificultad del juego segun seleccion del ususario
 * Esta funcion despliega un menu de dificultad y accede, por medio de punteros, a la variable dif 
 * para configurar la dificultad del juego segun lo que elija el usuario
 * @param dif Dificultad del juego
 */
void SetDifficulty(int* dif);

/**
 * @brief Inicializa el juego
 * Esta funcion configura obtiene una palabra aleatoria del diccionario del juego por medio de punteros, 
 * inicializa el estado de la palabra con puros guines bajos y asigna valor de intentos maximos e intentos 
 * restantes segun la dificultad escogida.
 * @param currWords Cantidad actual de palabras en el diccionario
 * @param dif Dificultad del juego
 * @param dict Diccionario de palabras del juego
 * @param ahorcado Instanciacion de la struct del juego
 */
void Initialize(int currWords, int* dif, string dict[], Ahorcado* ahorcado);

void Guessing(Ahorcado* ahorcado);
bool Verification(Ahorcado* ahorcado);

/**
 * @brief Agrega palabras al diccionario
 * Solicita al usuario una palabra para agregarla al diccionario del juego por medio de punteros. Esta palabra
 * es agregada despues de las palabras que ya estaban.
 * @param currWords Cantidad actual de palabras en el diccionario
 * @param dict Diccionario de palabras del juego
 */
void AddWords(int* currWords, string dict[]);

/**
 * @brief Imprime el diccionario del juego
 * 
 * @param currWords Cantidad actual de palabras en el diccionario
 * @param dict Diccionario de palabras del juego
 */
void PrintDictionary(int currWords, string dict[]);
#endif