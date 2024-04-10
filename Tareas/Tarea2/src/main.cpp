#include "Planeta.hpp"
#include"Funciones.hpp"

using namespace std;

int main(){
    // COntinente y planeta bases
    Continente America("America"), Asia("Asia"), Africa("Africa"), Europa("Europa"), Oceania("Oceania");
    Planeta Tierra("Tierra", &America, &Asia, &Africa, &Europa, &Oceania);
    int option; // Eleccion del menu
    

    // Generar IDS posibles
    generateIDS(&Tierra);

    // Paises iniciales
    PaisPrimerMundo USA("Estados Unidos", true, true, true, 333300000, AMERICA);
    PaisPrimerMundo China("China", true, true, true, 1412000000, ASIA);
    PaisPrimerMundo Rusia("Rusia", true, true, true, 271200000, EUROPA);
    PaisEnDesarrollo Cuba("Cuba", false, true, false, 11000000, AMERICA);
    PaisEnDesarrollo Uganda("Uganda", false, false, false, 47000000, AFRICA);
    
    basePPMCountries(&USA, &America, &Tierra);
    basePPMCountries(&China, &Asia, &Tierra);
    basePPMCountries(&Rusia, &Europa, &Tierra);
    basePEDCountries(&Cuba, &America, &Tierra);
    basePEDCountries(&Uganda, &Africa, &Tierra);

    // Vectores y conteo para agregar paises
    vector<PaisPrimerMundo> auxPPM;
    vector<PaisEnDesarrollo> auxPED;
    int auxcountppm = 0, auxcountped = 0;

    // Menu
    do{
        cout << "\nMENU: Administracion Mundial" << endl;
        cout << "1. Desplegar la informacion del planeta. " << endl;
        cout << "2. Comparar paises. " << endl;
        cout << "3. Agregar paises. " << endl;
        cout << "4. Quitar pais. " << endl;
        cout << "5. Salir. " << endl;

        cout << "Ingrese el numero de su eleccion: ";
        cin >> option;
        cout << " " << endl;

        switch(option){
            // imprimir informacion entera
            case INFO:
                displayInfo(&Tierra);
                break;

            // Comparar dos paises
            case COMPARAR:
                compareCountries(&Tierra);
                break;

            // Agregar pais
            case AGREGAR:
                break;

            // Quitar pais
            case QUITAR:
                quitCountry(&Tierra);
                break;

            // Salir del juego
            case SALIR:
                cout << "Saliendo del sistema..." << endl;
                exit(0);
                break;

            // Caso default, eleccion invalida
            default:
                cout << "Ingrese uno de los numeros disponibles." << endl;
                break;
        }
        
        /*
        Se separa este caso del switch-case porque ocasionaba problemas con la instanciacion del objeto p
        */
        if(option == AGREGAR){
            Pais p = addCountry(&Tierra); // Crear pais base

            // Verificar atributos del pais
            if(p.tech5g || p.invcenter){
                // Crear Pais Primer MUndo
                PaisPrimerMundo p1(p.nameCountry, p.tech5g, p.aeropuerto, p.invcenter, p.habitantes, p.continentePais);
                cout << "Se ha creado " << p1.nameCountry << " exitosamente!" << endl;
                auxPPM.push_back(p1);
                basePPMCountries(&auxPPM[auxcountppm], Tierra.listaContinentes[p.continentePais - 1], &Tierra);
                auxcountppm++; // AUmentar conteo
            }else{
                // Crear Pais en Desarrollo
                PaisEnDesarrollo p2(p.nameCountry, p.tech5g, p.aeropuerto, p.invcenter, p.habitantes, p.continentePais);
                cout << "Se ha creado " << p2.nameCountry << " exitosamente!" << endl;
                auxPED.push_back(p2);
                basePEDCountries(&auxPED[auxcountped], Tierra.listaContinentes[p.continentePais - 1], &Tierra);
                auxcountped++; // AUmentar conteo
            };

        }
    }while(option != SALIR);

    return 0;
}