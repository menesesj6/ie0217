/**
 * @file Funciones.hpp
 * @author Jorge A. Meneses Garro (j.menesesgarro@gmail.com.com)
 * @brief Header file con los prototipos de las funciones
 * @version 1.0
 * @date 2024-04-3
 * @copyright Copyright (c) 2024
 */
#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "Ahorcado.hpp"

/**
 * @brief Configura dificultad del juego segun seleccion del ususario
 * 
 * Esta funcion despliega un menu de dificultad y accede, por medio de punteros, a la variable dif 
 * para configurar la dificultad del juego segun lo que elija el usuario
 * @param dif Dificultad del juego
 */
void SetDifficulty(int* dif);

/**
 * @brief Inicializa el juego
 * 
 * Esta funcion configura obtiene una palabra aleatoria del diccionario del juego por medio de punteros, 
 * inicializa el estado de la palabra con puros guines bajos y asigna valor de intentos maximos e intentos 
 * restantes segun la dificultad escogida.
 * @param currWords Cantidad actual de palabras en el diccionario
 * @param dif Dificultad del juego
 * @param dict Diccionario de palabras del juego
 * @param ahorcado Instanciacion de la struct del juego
 */
void Initialize(int currWords, int* dif, string dict[], Ahorcado* ahorcado);

/**
 * @brief Usuario ingresa una letra y se actualiza el estado de la palabra
 * 
 * Este tiene un bucle que esta activo si el return de Verification() es true. Dentro de este bucle se solicita al 
 * una letra e itera sobre la palabra a adivinar para ver si la letra ingresada esta. Si la letra ingresada esta, 
 * se actualiza el estado de la palabra cambiando los guines bajos por la letra acertada. Tambien, se lleva conteo 
 * en tiempo real de los intentos restantes. AL momento que el return de Verification() sea false, el bucle se 
 * detiene totalmente.
 * @param ahorcado Instanciacion de la struct del juego
 * @see Verification
 */
void Guessing(Ahorcado* ahorcado);

/**
 * @brief Se encarga de verificar el estado
 * 
 * Compara constantemente el estado de la palabra con la palabra a adivinar para saber cuando llegan a ser iguales;
 * o bien, cuando se agoten los intentos. Funciona como el argumento del ciclo while de Guessing(), pues indica si
 * el juego ya esta en condiciones de terminar o no. Tambien, controla la ultima oportunidad del usuario cuando se 
 * le agoten los intentos
 * @param ahorcado Instanciacion de la struct del juego 
 * @return true El juego continua (La palabra no es igual a la deseada y aun sobran intentos)
 * @return false El juego termina, ya sea ganado palabra acertada normal o por ultima oportunidad) o perdido (no mas intentos)
 */
bool Verification(Ahorcado* ahorcado);

/**
 * @brief Agrega palabras al diccionario
 * 
 * Solicita al usuario una palabra para agregarla al diccionario del juego por medio de punteros. Esta palabra
 * es agregada despues de las palabras que ya estaban.
 * @param currWords Cantidad actual de palabras en el diccionario
 * @param dict Diccionario de palabras del juego
 */
void AddWords(int* currWords, string dict[]);

/**
 * @brief Imprime el diccionario del juego
 * 
 * Itera a lo largo de todo el diccionario del juego e imprime cada una de las palabras de las que se podria obtener la
 * eleccion aleatoria para el juego
 * @param currWords Cantidad actual de palabras en el diccionario
 * @param dict Diccionario de palabras del juego
 */
void PrintDictionary(int currWords, string dict[]);
#endif