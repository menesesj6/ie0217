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
    ppm->setID(tierra->primeIDS[tierra->ppmtot]);
    tierra->listaPPMTotal[tierra->ppmtot] = ppm;
    tierra->ppmtot++;
};

void addPEDCountries(PaisEnDesarrollo* ped, Continente* cont, Planeta* tierra){
    if(ped->aeropuerto){cont->avion = true;}
    ped->setID(tierra->nonprimeIDS[tierra->pedtot]);
    cont->ped++;
    tierra->listaPEDTotal[tierra->pedtot] = ped;
    tierra->pedtot++;
};

Pais addCountry(Planeta* tierra){
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
    
    Pais p(pais, _tech5g, _aeropuerto, center, habs, cont);
    return p;
} 

void quitCountry(Planeta* tierra){
    char choice;
    cout << "Se eliminara el ultimo pais. Desea eliminar Pais de primer mundo o en desarrollo?" << endl;
    cout << "D. En Desarrollo" << endl;
    cout << "P. Primer Mundo" << endl;
    cout << "Seleccion: ";
    cin >> choice;
    
    if(choice == 'P'){
        tierra->listaPPMTotal[0]->~PaisPrimerMundo();
        tierra->listaContinentes[tierra->listaPPMTotal[0]->continentePais - 1]->ppm--;
        tierra->ppmtot--;
    }else if(choice == 'D'){
        tierra->listaPEDTotal[0]->~PaisEnDesarrollo();
        tierra->listaContinentes[tierra->listaPEDTotal[0]->continentePais - 1]->ped--;
        tierra->pedtot--;
    }
}

void generateIDS(Planeta* tierra){
    int _id = 0;
    int primecount = 0, nonprimecount = 0;
    while (_id < 500){
        int primos = 0;
        if (_id > 1){
	
	        for(int i = 1;i <= _id; ++i){
	        	if (_id % i == 0 )
	        		++primos; 
	        }

	        if (primos == 2){
                tierra->primeIDS[primecount] = _id;
                primecount++;
            }else if (primos != 2){
                tierra->nonprimeIDS[nonprimecount] = _id;
                nonprimecount++;
            }
        }
        _id++;
    }
}

void compareCountries(Planeta* tierra){
    string p1, p2;
    PaisPrimerMundo* ptr1;
    PaisPrimerMundo* ptr2;
    bool result;
    cout << "Ingrese los nombres de los paises que desea comparar." << endl;
    cout << "Pais 1: " << endl;
    cin.ignore();
    getline(cin, p1);
    cout << "\nPais 2: " << endl;
    cin.ignore();
    getline(cin, p2);

    for (int i = 0; i < tierra->ppmtot; i++){
        if(tierra->listaPPMTotal[i]->nameCountry == p1){
            ptr1 = tierra->listaPPMTotal[i];
        }else if(tierra->listaPPMTotal[i]->nameCountry == p2){
            ptr2 = tierra->listaPPMTotal[i];
        }
    }
    if(*ptr1 == *ptr2){
        cout << ptr1->nameCountry << " y " << ptr2->nameCountry << " son del mismo tipo!";
    }
}
