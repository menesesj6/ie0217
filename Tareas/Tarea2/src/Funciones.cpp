#include "Funciones.hpp"

void displayInfo(Planeta *tierra){
    int count = 1; 
    cout << "\n-------------------" << endl;
    cout << "INFORMACION MUNDIAL" << endl;
    // COntinentes planeta
    cout << tierra->planetName << " tiene los continentes: " << endl;
    for (int i = 0; i < 5; i++){
        cout << i + 1 << ". " << tierra->listaContinentes[i]->nameContinent << ": " 
        << tierra->listaContinentes[i]->ped << " paises en desarrollo y " << 
        tierra->listaContinentes[i]->ppm << " paises de primer mundo." << endl;
    }

    // COntinentes con avion
    cout << "\nContinentes por los que pasa el avion:" << endl;
    for (int i = 0; i < 5; i++){
        if(tierra->listaContinentes[i]->avion){
            cout << count << ". " << tierra->listaContinentes[i]->nameContinent << endl;
            count++;
        }
    }

    for (int i = 0; i < tierra->ppmtot; i++){
        tierra->listaPPMTotal[i]->displayPPM();
    }
    cout << "\n-------------------" << endl;
}

void basePPMCountries(PaisPrimerMundo* ppm, Continente* cont, Planeta* tierra){
    if(ppm->aeropuerto){cont->avion = true;}
    cont->ppm++;
    tierra->listaPPMTotal[tierra->ppmtot] = ppm;
    tierra->ppmtot++;
};

void basePEDCountries(PaisEnDesarrollo* ped, Continente* cont, Planeta* tierra){
    if(ped->aeropuerto){cont->avion = true;}
    cont->ped++;
    tierra->listaPEDTotal[tierra->pedtot] = ped;
    tierra->pedtot++;
};

void addCountry(Planeta* tierra){
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


} 

void quitCountry(){
    
}

int generatePrimeNumbers(){
    return 0;
}

