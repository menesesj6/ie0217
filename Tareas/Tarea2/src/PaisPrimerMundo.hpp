#ifndef PAISPRIMERMUNDO_HPP
#define PAISPRIMERMUNDO_HPP

#include "Pais.hpp"

class PaisPrimerMundo : public Pais{
    public: 
        string typePPM = "Primer mundo";
        int workers;
        // Constructor y destructor
        PaisPrimerMundo(string _nameCountry, bool _tech5g, bool _aeropuerto, bool _invcenter, int _habitantes, int continentePais);
        virtual ~PaisPrimerMundo();
        void displayPaisPPM();
    protected:
        // Metodo de calculo de trabajadores
        int getWorkers();

};

#endif