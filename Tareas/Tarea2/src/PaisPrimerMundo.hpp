#ifndef PAISPRIMERMUNDO_HPP
#define PAISPRIMERMUNDO_HPP

#include "Pais.hpp"

class PaisPrimerMundo : public Pais{
    public: 
        // Si tiene o no centro de investigacion
        bool invcenter;
        // Constructor y destructor
        PaisPrimerMundo();
        ~PaisPrimerMundo();
    protected:
        // Metodo de calculo de trabajadores
        int getWorkers();

};

#endif