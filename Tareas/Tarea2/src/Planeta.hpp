#ifndef PLANETA_HPP
#define PLANETA_HPP

#include "Continente.hpp"

class Planeta{
    public:
        // Atributos
        Continente* c1;
        Continente* c2;
        Continente* c3;
        Continente* c4;
        Continente* c5;
        string planetName;
        Continente* listaContinentes[5] = {c1, c2, c3, c4, c5};
        // Constructor y destructor
        Planeta(string _planetName, Continente* _c1, Continente* _c2, Continente* _c3, Continente* _c4, Continente* _c5);
        virtual ~Planeta();
};

#endif