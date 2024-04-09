#ifndef PAISDESARROLLO_HPP
#define PAISDESARROLLO_HPP

#include "Pais.hpp"

class PaisEnDesarrollo : public Pais{
    public:
        string typeED = "En desarrollo";
        // COnstructor y destructor
        PaisEnDesarrollo(string _nameCountry, bool _tech5g, bool _aeropuerto, bool _invcenter, int _habitantes, int continentePais);
        virtual ~PaisEnDesarrollo();
};

#endif