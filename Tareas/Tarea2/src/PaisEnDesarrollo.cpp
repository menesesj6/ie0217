#include "PaisEnDesarrollo.hpp"

PaisEnDesarrollo::PaisEnDesarrollo(string _nameCountry, bool _tech5g, bool _aeropuerto, bool _invcenter, 
                    int _habitantes, int _continentePais) : Pais(_nameCountry, _tech5g, _aeropuerto, _invcenter, 
                    _habitantes, _continentePais){
    this->pib = this->calculatePIB(); // ASignar el PIB usando la funcion
};

PaisEnDesarrollo::~PaisEnDesarrollo(){
};

void PaisEnDesarrollo::displayPED() const{
    // Imprimir todos sus parametros de importancia
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