#include "Funciones.hpp"

void displayInfo(Planeta *tierra){
    cout << tierra->planetName << " tiene los continentes: ";
    for (int i = 0; i < 5; i++){
        cout << i + 1 << ". " <<tierra->listaContinentes[i]->nameContinent << endl;
    }
}

void addCountry(){
    string pais;
    int aux, habs, cont;
    bool _aeropuerto = false;
    bool _tech5g = false;
    bool center = false;

    cout << "---------------" << endl;
    cout << "AGREGAR UN PAIS" << endl;

    // Pedir nombre
    cout << "\nNombre del pais: ";
    cin >> pais;

    // Pedir continente
    cout << "\nContinentes: " << endl;
    cout << "1. America " << endl;
    cout << "2. Asia " << endl;
    cout << "3. Africa " << endl;
    cout << "4. Europa " << endl;
    cout << "5. Oceania " << endl;
    cout << "En cual esta? ";
    cin >> cont;

    // Pedir habitantes
    cout << "\nCuantos habitantes tiene? ";
    cin >> habs;

    // Tecnologia 5G
    cout << "\nTiene tecnologia 5G?\n0. NO\n1. Si \n Seleccion: ";
    cin >> aux;
    if (aux == 1) {!_tech5g;}

    // Aeropuerto
    cout << "\nTiene aeropuerto?\n0. NO\n1. Si \n Seleccion: ";
    cin >> aux;
    if (aux == 1) {!_aeropuerto;}

    // Centro de investigacion
    cout << "\nTiene centro de investigacion y desarrollo?\n0. NO\n1. Si \n Seleccion: ";
    cin >> aux;
    if (aux == 1) {!center;}

    Pais p(_tech5g, _aeropuerto, center, habs, cont);
} 

void quitCountry(){
    
}

int generatePrimeNumbers(){
    return 0;
}