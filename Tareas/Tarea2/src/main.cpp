#include "Planeta.hpp"
#include"Funciones.hpp"

using namespace std;

int main(){
    // COntinente y planeta bases
    Continente America("America"), Asia("Asia"), Africa("Africa"), Europa("Europa"), Oceania("Oceania");
    Planeta Tierra("Tierra", &America, &Asia, &Africa, &Europa, &Oceania);
    int option; // Eleccion del menu
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
            // Configuracion de dificultad
            case INFO:
                displayInfo(&Tierra);
                break;

            // Inicio del juego
            case COMPARAR:
                break;

            // Agregar palabras al diccionario
            case AGREGAR:
                addCountry();
                break;

            // Ver diccionario
            case QUITAR:
                break;

            // Salir del juego
            case SALIR:
                break;

            // Caso default, eleccion invalida
            default:
                cout << "Ingrese uno de los numeros disponibles." << endl;
                break;
        }
    }while(option != SALIR);

    return 0;
}