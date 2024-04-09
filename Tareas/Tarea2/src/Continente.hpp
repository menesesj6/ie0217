/**
 * @file Continente.hpp
 * @author Jorge Meneses Garro
 * @brief Se define la clase Continente, que se instanciara en varios objetos, los continentes que componen a Tierra
 * @version 1.0
 * @date 2024-04-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef CONTINENTE_HPP
#define CONTINENTE_HPP

#include "PaisPrimerMundo.hpp"
#include "PaisEnDesarrollo.hpp"

/**
 * @brief Clase Continente almacena los datos de cuantos paises de cada tipo tiene y si el avion pasa por el
 * 
 */
class Continente{
    public:
        string nameContinent; /**<- Nombre del continente*/
        int ped = 0; /**<- Cantidad de paises en desarrollo en el continente*/
        int ppm = 0; /**<- Cantidad de paises primer mundo en el continente*/
        bool avion = false; /**<- Dato de si el avion pasa o no por el continente*/

        /**
         * @brief CConstructor de un objeto tipo Continente
         * 
         * @param _nom NOmbre que se le desea dar
         */
        Continente(string _nom);

        /**
         * @brief Destructor de un objeto de tipo Continente
         * 
         */
        virtual ~Continente();
};

#endif