#ifndef PAIS_HPP
#define PAIS_HPP

#include <iostream>
#include <string>
#include "Menu.hpp"
using namespace std;

#define MAX_PAISES 54
#define TOTAL_PAISES 195

class Pais{
    public:
        // Atributos de un pais que se heredaran
        string nameCountry;
        bool tech5g;
        bool aeropuerto;
        int habitantes;
        double pib, continentePais;
        // Si tiene o no centro de investigacion
        bool invcenter;
        //Constructor
        Pais(string _nameCountry, bool _tech5g, bool _aeropuerto, 
            bool _invcenter, int _habitantes, int continentePais);
        // Metodo de calculo del PIB
        double calculatePIB();
    protected:
        int id; // ID del pais
        // Sobrecarga del ==
        bool operator== (const Pais otro);
};

#endif