#include "Funciones.hpp"

/*
Se hace amplio uso del operador -> para acceder a miembros por medio de punteros*/

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

// Agregar Pais de Primer Mundo a Planeta
void basePPMCountries(PaisPrimerMundo* ppm, Continente* cont, Planeta* tierra){
    if(ppm->aeropuerto){cont->avion = true;}
    cont->ppm++;
    tierra->listaPPMTotal[tierra->ppmtot] = ppm;
    ppm->setID(tierra->primeIDS[tierra->ppmtot]);
    tierra->ppmtot++;
};

// Agregar Pais En DEsarrollo a Planeta
void basePEDCountries(PaisEnDesarrollo* ped, Continente* cont, Planeta* tierra){
    if(ped->aeropuerto){cont->avion = true;}
    cont->ped++;
    tierra->listaPEDTotal[tierra->pedtot] = ped;
    ped->setID(tierra->nonprimeIDS[tierra->pedtot]);
    tierra->pedtot++;
};

// Obtener datos del nuevo pais
Pais addCountry(Planeta* tierra){
    // Atributos del pais
    string pais;
    int aux = 0, habs = 0, cont = 0;
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
    if (aux == 1) {center = true;}
    
    // INstanciar el nuevo Pais y retornarlo
    Pais p(pais, _tech5g, _aeropuerto, center, habs, cont);
    return p;
} 

// Eliminar un  
void quitCountry(Planeta* tierra){
    char choice;
    cout << "Se eliminara el ultimo pais. Desea eliminar Pais de primer mundo o en desarrollo?" << endl;
    cout << "D. En Desarrollo" << endl;
    cout << "P. Primer Mundo" << endl;
    cout << "Seleccion: ";
    cin >> choice;
    
    // Eleccion del tipo a eliminar
    if(choice == 'P'){
        tierra->listaPPMTotal[0]->~PaisPrimerMundo();
        tierra->listaContinentes[tierra->listaPPMTotal[tierra->ppmtot - 1]->continentePais - 1]->ppm--;
        tierra->ppmtot--;
    }else if(choice == 'D'){
        tierra->listaPEDTotal[0]->~PaisEnDesarrollo();
        tierra->listaContinentes[tierra->listaPEDTotal[tierra->pedtot - 1]->continentePais - 1]->ped--;
        tierra->pedtot--;
    }
}

void generateIDS(Planeta* tierra){
    int _id = 0; // ID por el que se itera
    int primecount = 0, nonprimecount = 0; // INdice para asignacion en el array
    // Se sacaran 500 IDs totales
    while (_id < 500){
        int primos = 0; // Auxiliar para saber si es primo
        if (_id > 1){
            // Verificar is id es primo
	        for(int i = 1;i <= _id; ++i){
	        	if (_id % i == 0 )
	        		++primos; 
	        }

            // Caso en que es primo
	        if (primos == 2){
                tierra->primeIDS[primecount] = _id;
                primecount++;
            } // Caso que no es primo
            else if (primos != 2){
                tierra->nonprimeIDS[nonprimecount] = _id;
                nonprimecount++;
            }
        }
        _id++; // Ir al proximo ID
    }
}

void compareCountries(Planeta* tierra){
    string p1, p2;
    Pais* ptr1;
    Pais* ptr2;

    // Pedirle al usuario los paises a comparar
    // Usar getline para poder ingresar strings con espacios
    cout << "Ingrese los nombres de los paises que desea comparar." << endl;
    cout << "Pais 1: " << endl;
    cin.ignore();
    getline(cin, p1);
    cout << "\nPais 2: " << endl;
    getline(cin, p2);

    cout << "\nSon " << p1 << " y " << p2 << "del mismo tipo? " << endl;

    // BUscar los paises deseados
    // Revisar PPM
    for (int i = 0; i < tierra->ppmtot; i++){
        if(tierra->listaPPMTotal[i]->nameCountry == p1){
            ptr1 = tierra->listaPPMTotal[i]; // Extraer puntero
        }else if(tierra->listaPPMTotal[i]->nameCountry == p2){
            ptr2 = tierra->listaPPMTotal[i]; // EXtraer puntero
        }
    }

    // Revisar PED
    for (int i = 0; i < tierra->pedtot; i++){
        if(tierra->listaPEDTotal[i]->nameCountry == p1){
            ptr1 = tierra->listaPEDTotal[i]; // EXtraer puntero
        }else if(tierra->listaPEDTotal[i]->nameCountry == p2){
            ptr2 = tierra->listaPEDTotal[i]; // Extraer puntero
        }
    }

    // Comparar el contenido de los punteros extraidos con el operador sobrecargado
    if(*ptr1 == *ptr2){
        cout << "Si, son del mismo tipo!" << endl;
    }else{
        cout << "No, no son el mismo tipo!" << endl;
    }
    
}
