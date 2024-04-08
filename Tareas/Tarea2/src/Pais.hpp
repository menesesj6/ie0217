#ifndef PAIS_HPP
#define PAIS_HPP

#include <iostream>
#include <string>
using namespace std;

#define MAX_PAISES 54
#define TOTAL_PAISES 195

class Pais{
    public:
        // Atributos de un pais que se heredaran
        bool tech5g;
        bool aeropuerto;
        int id;
        int habitantes;
        // Metodo de calculo del PIB
        int calculatePIB();
    protected:
        int id; // ID del pais
    private:
        // Sobrecarga del ==
        Pais operator== (Pais p1);
};

#endif