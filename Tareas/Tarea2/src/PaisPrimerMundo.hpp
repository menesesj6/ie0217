#ifndef PAISPRIMERMUNDO_HPP
#define PAISPRIMERMUNDO_HPP

#include "Pais.hpp"

class PaisPrimerMundo : public Pais{
    public: 
        // Constructor y destructor
        PaisPrimerMundo();
        virtual ~PaisPrimerMundo();
    protected:
        // Metodo de calculo de trabajadores
        int getWorkers();

};

#endif