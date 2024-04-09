#include "PaisEnDesarrollo.hpp"

PaisEnDesarrollo::PaisEnDesarrollo(string _nameCountry, bool _tech5g, bool _aeropuerto, bool _invcenter, 
                    int _habitantes, int continentePais) : Pais(_nameCountry, _tech5g, _aeropuerto, _invcenter, 
                    _habitantes, continentePais){
    this->pib = this->calculatePIB();
};

PaisEnDesarrollo::~PaisEnDesarrollo(){
};

void PaisEnDesarrollo::displayPED() const{
    cout << "\n" << this->nameCountry << ": " << endl;
    cout << "ID: " << this->id << endl;
    cout << "Poblacion: " << this->habitantes << endl;
    cout << "PIB: $" << this->pib << endl;
    cout << "Aeropuerto: ";
    if(this->aeropuerto) {
        cout << "Si" << endl;;
    }else{
        cout << "No" << endl;
    }
}