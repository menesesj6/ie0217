#include <iostream>
#include <string>
#include "Planeta.hpp"

void displayInfo(Planeta *tierra);
Pais addCountry(Planeta *tierra);
void addPPMCountries(PaisPrimerMundo* ppm, Continente* cont, Planeta* tierra);
void addPEDCountries(PaisEnDesarrollo* ped, Continente* cont, Planeta* tierra);
void quitCountry(Planeta* tierra);
void generateIDS(Planeta* tierra);
void compareCountries(Planeta* tierra);
