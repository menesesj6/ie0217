
/**
 * @file PaisEnDesarrollo.hpp
 * @author Jorge Meneses Garro
 * @brief Se define la clase PaisEnDesarrollo, que se instanciara en objetos
 * @version 1.0
 * @date 2024-04-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef PAISDESARROLLO_HPP
#define PAISDESARROLLO_HPP

#include "Pais.hpp"

/**
 * @brief Clase que hereda de Pais atributos y metodos
 * 
 */
class PaisEnDesarrollo : public Pais{
    public:
        /**
         * @brief Constructor de un objeto tipo PaisEnDesarrollo
         * 
         * @param _nameCountry Nombre del pais
         * @param _tech5g Si tiene tecnologia 5G o no (Siempre no)
         * @param _aeropuerto Si tiene aeropuerto o no
         * @param _invcenter Si tiene centro de investigacion y desarrollo o no (Siempre no)
         * @param _habitantes Cantidad de habitantes del pais
         * @param _continentePais Continente donde esta ubicado
         */
        PaisEnDesarrollo(string _nameCountry, bool _tech5g, bool _aeropuerto, 
                        bool _invcenter, int _habitantes, int _continentePais);

        /**
         * @brief Destructor del objeto tipo PaisEnDesarrollo
         * 
         */
        virtual ~PaisEnDesarrollo();

        /**
         * @brief Imprime toda la informacion de un objeto tipo PaisEnDesarrollo
         * 
         */
        void displayPED() const;
};

#endif