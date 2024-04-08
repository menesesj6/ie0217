#ifndef PLANETA_HPP
#define PLANETA_HPP

#include "Continente.hpp"

class Planeta{
    public:
        // Atributos
        string name;
        Continente continentesLista[5];
        // Constructor y destructor
        Planeta();
        ~Planeta();
};

#endif