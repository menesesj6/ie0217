#ifndef CONTINENTE_HPP
#define CONTINENTE_HPP

#include "PaisPrimerMundo.hpp"
#include "PaisEnDesarrollo.hpp"

class Continente{
    public:
        string nameContinent;
        // Listas de paises
        PaisEnDesarrollo paisesEDLista[MAX_PAISES]; 
        PaisPrimerMundo paisesPMLista[MAX_PAISES]; 
        // Pasa el avion o no
        bool avion;
        // Constructor y destructor
        Continente(string _nom);
        virtual ~Continente();
};

#endif