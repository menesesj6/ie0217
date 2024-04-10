/**
 * @file Planeta.hpp
 * @author Jorge Meneses Garro
 * @brief Se define la clase Planeta, que se instanciara en un objeto (Tierra)
 * @version 1.0
 * @date 2024-04-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef PLANETA_HPP
#define PLANETA_HPP

#include "Continente.hpp"

/**
 * @brief Clase Planeta. Se compone de continentes y paises y almacena los IDs
 * 
 */
class Planeta{
    public:
        int pedtot = 0; /**<- Cantidad actual de paises en desarrollo*/
        int ppmtot = 0; /**<- Cantidad actual de paises primer mundo*/
        Continente* c1; /**<- Primer continente del planeta*/
        Continente* c2; /**<- Segundo continente del planeta*/
        Continente* c3; /**<- Tercer continente del planeta*/
        Continente* c4; /**<- Cuarto continente del planeta*/
        Continente* c5; /**<- Quinto continente del planeta*/
        string planetName; /**<- Nombre del planeta*/
        
        Continente* listaContinentes[5] = {c1, c2, c3, c4, c5}; /**<- Array de continentes que componen al planeta*/

        PaisEnDesarrollo* listaPEDTotal[TOTAL_PAISES]; /**<- Lista de paises en desarrollo*/
        PaisPrimerMundo* listaPPMTotal[TOTAL_PAISES]; /**<- LIsta de paises primer mundo*/
        
        int primeIDS[95]; /**<- Array con los indicadores primos*/
        int nonprimeIDS[200]; /**<- Array con los indicadores no primos*/

        /**
         * @brief Constructor de un objeto tipo Planera, Tierra en este proyecto
         * 
         * @param _planetName Nombre del planeta (Tierra)
         * @param _c1 Primer continente del planeta (America)
         * @param _c2 Segundo continente del planeta (Asia)
         * @param _c3 Tercer continente del planeta (Africa)
         * @param _c4 Cuarto continente del planeta (Europa)
         * @param _c5 Quinto continente del planeta (Oceania)
         */
        Planeta(string _planetName, Continente* _c1, Continente* _c2, Continente* _c3, Continente* _c4, Continente* _c5);

        /**
         * @brief Destructor del objeto de tipo Planeta
         * 
         */
        virtual ~Planeta();
};

#endif