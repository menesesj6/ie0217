#include "Pais.hpp"

Pais::Pais(string _nameCountry, bool _tech5g, bool _aeropuerto, bool _invcenter, int _habitantes, int _continentePais){
    // Asignar valores segun parametros
    this->nameCountry = _nameCountry;
    this->continentePais = _continentePais;
    this->tech5g = _tech5g;
    this->aeropuerto = _aeropuerto;
    this->invcenter = _invcenter;
    this->habitantes = _habitantes;
    this->pib = this->calculatePIB(); // Invocar calculo del PIB
}

double Pais::calculatePIB(){
    // Obtener un resultado deterministico entre 2147483647 y 3.17e7
    return rand() % RAND_MAX + 3.17e7;
}

bool Pais::operator== (const Pais &otro){
    // Revision de valores con operadores logicos para determinar return
    if(this->tech5g && otro.tech5g){return true;}
    else if(this->invcenter && otro.invcenter){return true;}
    else if(this->tech5g && otro.invcenter){return true;}
    else if(this->invcenter && otro.tech5g){return true;}
    else if(!this->tech5g && !otro.tech5g){return true;}
    else{return false;}
}

void Pais::setID(int _id){
    this->id = _id; // COnfigurar el ID
}

