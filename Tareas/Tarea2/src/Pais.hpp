#ifndef PAIS_HPP
#define PAIS_HPP

#include <iostream>
#include <string>
#include "Menu.hpp"
using namespace std;

#define TOTAL_PAISES 195

class Pais{
    protected:
        int id; // ID del pais
    public:
        // Atributos de un pais que se heredaran
        string nameCountry;
        bool tech5g;
        bool aeropuerto;
        int habitantes, continentePais;
        double pib;
        // Si tiene o no centro de investigacion
        bool invcenter;
        //Constructor
        Pais(string _nameCountry, bool _tech5g, bool _aeropuerto, 
            bool _invcenter, int _habitantes, int _continentePais);
        // Metodo de calculo del PIB
        double calculatePIB();
        void setID(int _id);
        // Sobrecarga del ==
        bool operator== (const Pais &otro);
};

#endif