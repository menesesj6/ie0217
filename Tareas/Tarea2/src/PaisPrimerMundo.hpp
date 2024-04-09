#ifndef PAISPRIMERMUNDO_HPP
#define PAISPRIMERMUNDO_HPP

#include "Pais.hpp"

class PaisPrimerMundo : public Pais{
    public: 
        string typePPM = "Primer mundo";
        int workers;
        // Constructor y destructor
        PaisPrimerMundo(string _nameCountry, bool _tech5g, bool _aeropuerto, bool _invcenter, 
                        int _habitantes, int _continentePais);
        virtual ~PaisPrimerMundo();
        void displayPPM() const;
    private:
        // Metodo de calculo de trabajadores
        void getWorkers();


};

#endif