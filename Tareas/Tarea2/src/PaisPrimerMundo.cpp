#include "PaisPrimerMundo.hpp"

PaisPrimerMundo::PaisPrimerMundo(string _nameCountry, bool _tech5g, bool _aeropuerto, bool _invcenter, 
                int _habitantes, int _continentePais) : Pais(_nameCountry, _tech5g, _aeropuerto, _invcenter,
                 _habitantes, _continentePais){
    this->getWorkers();
    this->pib = this->calculatePIB();
}       

PaisPrimerMundo::~PaisPrimerMundo(){
}

void PaisPrimerMundo::getWorkers(){
    this->workers = rand() % this->habitantes + 1;
}
void PaisPrimerMundo::displayPPM() const{
    cout << "\n" << this->nameCountry << ": " << endl;
    cout << "ID: " << this->id << endl;
    cout << "Poblacion: " << this->habitantes << endl;
    cout << "Trabajadores: " << this->workers << endl;
    cout << "PIB: $" << this->pib << endl;
 
    cout << "Tecnologia 5G: ";
    if(this->tech5g) {
        cout << "Si" << endl;;
    }else{
        cout << "No" << endl;
    }

    cout << "Aeropuerto: ";
    if(this->aeropuerto) {
        cout << "Si" << endl;;
    }else{
        cout << "No" << endl;
    }

    cout << "Centro de investigacion y desarrollo: ";
    if(this->invcenter) {
        cout << "Si\n" << endl;;
    }else{
        cout << "No\n" << endl;
    }
}
