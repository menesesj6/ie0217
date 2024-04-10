/**
 * @file Funciones.hpp
 * @author Jorge Meneses Garro
 * @brief Se definen las funciones que seran de utilidad para el flujo del programa
 * @version 1.0
 * @date 2024-04-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include <string>
#include "Planeta.hpp"

/**
 * @brief Obtiene la informacion del planeta enter y la imprime
 * 
 * @param tierra Puntero hacia el objeto planeta instanciado en main()
 */
void displayInfo(Planeta *tierra);

/**
 * @brief Genera un objeto de tipo Pais para agregarlo al Planeta
 * 
 * @param tierra Puntero hacia el objeto planeta instanciado en main()
 * @return Pais Nuevo objeto tipo Pais
 */
Pais addCountry(Planeta *tierra);

/**
 * @brief Hace uso de punteros para agregar un objeto base tipo PaisPrimerMundo al sistema y actualiza el planeta y continentes
 * 
 * @param ppm Puntero hacia el objeto de tipo PaisPrimerMundo que se desea agregar
 * @param cont Puntero hacia el continente al que pertenece el pais
 * @param tierra Puntero hacia el objeto planeta instanciado en main()
 */
void basePPMCountries(PaisPrimerMundo* ppm, Continente* cont, Planeta* tierra);

/**
 * @brief Hace uso de punteros para agregar un objeto base tipo PaisEnDesarrollo al sistema y actualiza el planeta y continentes
 * 
 * @param ppm Puntero hacia el objeto de tipo PaisEnDesarrollo que se desea agregar
 * @param cont Puntero hacia el continente al que pertenece el pais
 * @param tierra Puntero hacia el objeto planeta instanciado en main()
 */
void basePEDCountries(PaisEnDesarrollo* ped, Continente* cont, Planeta* tierra);

/**
 * @brief Elimina un objeto pais del sistema. 
 * 
 * Por orden de destruccion de los destructores de las clases, se le solicita al usuario que especifica que se elimine un pais
 * en desarrollo o primer mundo. Basado en eso, se elimina EL ULTIMO objeto instanciado de ese tipo de pais
 * 
 * @param tierra Puntero hacia el objeto planeta instanciado en main()
 */
void quitCountry(Planeta* tierra);

/**
 * @brief Genera las listas de posibles identificadores primos y no primos dentro de un objeto tipo Planeta
 * @param tierra Puntero hacia el objeto planeta instanciado en main()
 */
void generateIDS(Planeta* tierra);

/**
 * @brief Indica si dos paises son del mismo tipo (PED o PPM) o distintos
 * 
 * Hace uso de una sobrecarga de operadores en la clase Pais. ESta comparacion se hace basada en el identificador de los dos
 * objetos involucrados.
 * 
 * @param tierra Puntero hacia el objeto planeta instanciado en main()
 */
void compareCountries(Planeta* tierra);
