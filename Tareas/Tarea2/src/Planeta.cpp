#include "Planeta.hpp"

Planeta::Planeta(string _planetName, Continente* _c1, Continente* _c2, Continente* _c3, Continente* _c4, Continente* _c5){
    this->planetName = _planetName;
    this->listaContinentes[0] = _c1;
    this->listaContinentes[1] = _c2;
    this->listaContinentes[2] = _c3;
    this->listaContinentes[3] = _c4;
    this->listaContinentes[4] = _c5;
}

Planeta::~Planeta(){  
}