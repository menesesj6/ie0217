/**
 * @file PaisPrimerMundo.hpp
 * @author Jorge Meneses Garro
 * @brief Se define la clase PaisPrimerMundo, que se instanciara en objetos
 * @version 1.0
 * @date 2024-04-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef PAISPRIMERMUNDO_HPP
#define PAISPRIMERMUNDO_HPP

#include "Pais.hpp"

class PaisPrimerMundo : public Pais{
    public: 
        int workers; /**<- Cantidad de personas que trabajan en el pais*/
        
        /**
         * @brief Constructor de un objeto tipo PaisPrimerMundo
         * 
         * @param _nameCountry Nombre del pais
         * @param _tech5g Si tiene tecnologia 5G o no
         * @param _aeropuerto Si tiene aeropuerto o no
         * @param _invcenter Si tiene centro de investigacion y desarrollo o no
         * @param _habitantes Cantidad de habitantes del pais
         * @param _continentePais Continente donde esta ubicado
         */
        PaisPrimerMundo(string _nameCountry, bool _tech5g, bool _aeropuerto, bool _invcenter, 
                        int _habitantes, int _continentePais);

        /**
         * @brief Destructor del objeto tipo PaisEnDesarrollo
         * 
         */
        virtual ~PaisPrimerMundo();

        /**
         * @brief Imprime toda la informacion de un objeto tipo PaisEnDesarrollo
         * 
         */
        void displayPPM() const;
    private:
        /**
         * @brief Calcula, aleatoriamente, cuantos de los habitantes trabajan
         * 
         */
        void getWorkers();
};

#endif