#ifndef CONTINENTE_HPP
#define CONTINENTE_HPP

#include "PaisPrimerMundo.hpp"
#include "PaisEnDesarrollo.hpp"

class Continente{
    public:
        string nameContinent;
        // Listas de paises
        int ped = 0; 
        int ppm = 0;
        // Pasa el avion o no
        bool avion = false;
        // Constructor y destructor
        Continente(string _nom);
        virtual ~Continente();
};

#endif