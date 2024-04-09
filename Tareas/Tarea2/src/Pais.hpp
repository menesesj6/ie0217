/**
 * @file Pais.hpp
 * @author Jorge Meneses Garro
 * @brief Se define la clase Pais que heredara a PaisPrimerMundo y PaisEnDesarrollo
 * @version 1.0
 * @date 2024-04-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef PAIS_HPP
#define PAIS_HPP

#include <iostream>
#include <string>
#include "Menu.hpp"
using namespace std;

#define TOTAL_PAISES 195

/**
 * @brief Clase Pais sera instanciada en objetos para despues ser clasificada en PaisPrimerMundo o PaisEnDesarrollo
 * 
 */
class Pais{
    protected:
        int id; /**<- Identificador del pais*/
    public:
        // Atributos de un pais que se heredaran
        string nameCountry; /**<- Nombre del pais*/
        bool tech5g; /**<- Si tiene tecnologia 5G o no*/
        bool aeropuerto; /**<- Si tiene aeropuerto o no*/
        int habitantes; /**<- Cantidad de habitantes*/
        int continentePais; /**<- Continente en el que esta ubicado*/
        double pib; /**<- PIB del pais*/
        bool invcenter; /**<- SI tiene centro de investigacion y desarrollo o no*/

        /**
         * @brief Constructor de un objeto tipo Pais
         * 
         * @param _nameCountry Nombre del pais
         * @param _tech5g Si tiene tecnologia 5G o no
         * @param _aeropuerto Si tiene aeropuerto o no
         * @param _invcenter Si tiene centro de investigacion y desarrollo o no
         * @param _habitantes Cantidad de habitantes del pais
         * @param _continentePais Continente donde esta ubicado
         */
        Pais(string _nameCountry, bool _tech5g, bool _aeropuerto, 
            bool _invcenter, int _habitantes, int _continentePais);

        /**
         * @brief Calcula de forma aleatoria el PIB de un pais entre un rango predefinido
         * 
         * @return double PIB del pais, asignado por puntero en el constructor
         */
        double calculatePIB();

        /**
         * @brief Permite a funciones externas tener acceso al atributo id del objeto
         * 
         * @param _id ID que se le asignara
         */
        void setID(int _id);
        
        /**
         * @brief Sobrecarga del operador == entre dos objetos tipo Pais
         * 
         * @param otro El otro objeto tipo Pais con el que se comparara
         * @return true Los tipos son iguales
         * @return false Los tipos son distintos
         */
        bool operator== (const Pais* otro);
};

#endif