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

    //Se vuelven a poner todos sin avion
    for(int i = 0; i < 5; i++){
        tierra->listaContinentes[i]->avion = false;
    }

    // Se revisa si los PPM aportan avion
    for(int i = 0; i < tierra->ppmtot; i++){
        if(tierra->listaPPMTotal[i]->aeropuerto){
            tierra->listaContinentes[tierra->listaPPMTotal[i]->continentePais - 1]->avion = true;
        }
    }

    // Se revisa si los PED aportan avion
    for(int i = 0; i < tierra->pedtot; i++){
        if(tierra->listaPEDTotal[i]->aeropuerto){
            tierra->listaContinentes[tierra->listaPEDTotal[i]->continentePais - 1]->avion = true;
        }
    }

    cout << "\nContinentes por los que pasa el avion:" << endl;
    for (int i = 0; i < 5; i++){
        if(tierra->listaContinentes[i]->avion){
            cout << count << ". " << tierra->listaContinentes[i]->nameContinent << endl;
            count++;
        }
    }

    cout << "\nPAISES DE PRIMER MUNDO" << endl;
    for (int i = 0; i < tierra->ppmtot; i++){
        tierra->listaPPMTotal[i]->displayPPM();
    }

    cout << "\nPAISES EN DESARROLLO" << endl;
    for (int i = 0; i < tierra->pedtot; i++){
        tierra->listaPEDTotal[i]->displayPED();
    }
    cout << "\n-------------------" << endl;
}

void addPPMCountries(PaisPrimerMundo* ppm, Continente* cont, Planeta* tierra){
    if(ppm->aeropuerto){cont->avion = true;}
    cont->ppm++;
    tierra->listaPPMTotal[tierra->ppmtot] = ppm;
    tierra->ppmtot++;
};

void addPEDCountries(PaisEnDesarrollo* ped, Continente* cont, Planeta* tierra){
    if(ped->aeropuerto){cont->avion = true;}
    cont->ped++;
    tierra->listaPEDTotal[tierra->pedtot] = ped;
    tierra->pedtot++;
};

void addCountry(Planeta* tierra){
    string pais;
    int type = 0; 
    int aux, habs, cont;
    bool _aeropuerto = false;
    bool _tech5g = false;
    bool center = false;

    cout << "---------------" << endl;
    cout << "AGREGAR UN PAIS" << endl;

    // Pedir nombre
    cout << "\nNombre del pais: ";
    cin.ignore();
    getline(cin, pais);

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
    if (aux == 1) {_tech5g = true;}

    // Aeropuerto
    cout << "\nTiene aeropuerto?\n0. NO\n1. Si \n Seleccion: ";
    cin >> aux;
    if (aux == 1) {_aeropuerto = true;}

    // Centro de investigacion
    cout << "\nTiene centro de investigacion y desarrollo?\n0. NO\n1. Si \n Seleccion: ";
    cin >> aux;

    if(_tech5g){type = 1;}
    else if(center){type = 1;}
    
    cout << type << endl;
    if(type = 1){
        PaisPrimerMundo p1(pais, _tech5g, _aeropuerto, center, habs, cont);
        cout << "\nSe ha creado " << p1.nameCountry << " con exito!" << endl;
        p1.displayPPM();
        tierra->ppmtot++;
        
    }else{
        PaisEnDesarrollo p2(pais, _tech5g, _aeropuerto, center, habs, cont);
        cout << "\nSe ha creado " << p2.nameCountry << " con exito!" << endl;
        p2.displayPED();
    }
} 

void quitCountry(Planeta* tierra){
    string paisEliminar;
    cout << "Cual pais desea eliminar?" << endl;
    cin.ignore();
    getline(cin, paisEliminar);
    for(int i = 0; i < tierra->ppmtot; i++){
        if(tierra->listaPPMTotal[i]->nameCountry == paisEliminar){
            tierra->listaContinentes[(tierra->listaPPMTotal[i]->continentePais) - 1]->ppm--;
            tierra->listaPPMTotal[i]->~PaisPrimerMundo();
            cout << tierra->listaPPMTotal[i]->nameCountry << "ha sido eliminado." << endl;
            tierra->ppmtot--;
            break;
        }
    }
    for(int i = 0; i < tierra->pedtot; i++){
        if(tierra->listaPEDTotal[i]->nameCountry == paisEliminar){
            tierra->listaContinentes[(tierra->listaPEDTotal[i]->continentePais) - 1]->ped--;
            tierra->listaPEDTotal[i]->~PaisEnDesarrollo();
            cout << tierra->listaPEDTotal[i]->nameCountry << "ha sido eliminado." << endl;
            tierra->pedtot--;
            break;
        }
    }
}


