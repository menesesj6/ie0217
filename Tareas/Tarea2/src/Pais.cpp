#include "Pais.hpp"

Pais::Pais(bool _tech5g, bool _aeropuerto, bool _invcenter, int _habitantes, int _continentePais){
    this->tech5g = _tech5g;
    this->aeropuerto = _aeropuerto;
    this->invcenter = _invcenter;
    this->habitantes = _habitantes;
    this->pib = this->calculatePIB();
}

double Pais::calculatePIB(){
    return 0;
}

bool Pais::operator== (Pais p1){
    return false;
}