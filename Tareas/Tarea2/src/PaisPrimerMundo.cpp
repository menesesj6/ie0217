#include "PaisPrimerMundo.hpp"

PaisPrimerMundo::PaisPrimerMundo(string _nameCountry, bool _tech5g, bool _aeropuerto, bool _invcenter, int _habitantes, int continentePais) : Pais(_nameCountry, _tech5g, _aeropuerto, _invcenter, _habitantes, continentePais){
       this->workers = this->getWorkers();
}       

PaisPrimerMundo::~PaisPrimerMundo(){

}

int PaisPrimerMundo::getWorkers(){
    return 0;
}
