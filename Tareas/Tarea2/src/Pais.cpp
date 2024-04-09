#include "Pais.hpp"

Pais::Pais(string _nameCountry, bool _tech5g, bool _aeropuerto, bool _invcenter, int _habitantes, int _continentePais){
    this->nameCountry = _nameCountry;
    this->continentePais = _continentePais;
    this->tech5g = _tech5g;
    this->aeropuerto = _aeropuerto;
    this->invcenter = _invcenter;
    this->habitantes = _habitantes;
    this->pib = this->calculatePIB();
}

double Pais::calculatePIB(){
    return rand() % RAND_MAX + 3.17e7;
}

bool Pais::operator== (const Pais &otro){
    int primos1 = 0, primos2 = 0;
    bool isPrime = false;
    bool otroIsPrime = false;
    for(int i = 1;i <= this->id; ++i){
	    if (this->id % i == 0 )
	        ++primos1; 
	}

    for(int i = 1;i <= otro.id; ++i){
	    if (otro.id % i == 0 )
	        ++primos2; 
	}

    if (primos1 == 2){
        isPrime = true;
    }

    if (primos2 == 2){
        otroIsPrime = true;
    }
    
    if(isPrime && otroIsPrime) {
        cout << this->nameCountry << " y " << otro.nameCountry << " son del mismo tipo!" << endl;
        return true;}
    else {
        cout << this->nameCountry << " y " << otro.nameCountry << " no son del mismo tipo!" << endl;
        return false;}
}

void Pais::setID(int _id){
    this->id = _id;
}

