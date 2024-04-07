#include "Planeta.hpp"
#include "Menu.hpp"
using namespace std;

int main(){
    Planeta Tierra;
    int option;
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
                break;

            // Inicio del juego
            case COMPARAR:
                break;

            // Agregar palabras al diccionario
            case AGREGAR:
                break;

            // Ver diccionario
            case QUITAR:
                break;

            // Salir del juego
            case SALIR;
                break;

            // Caso default, eleccion invalida
            default:
                cout << "Ingrese uno de los numeros disponibles." << endl;
                break;
        }
    }while(option != SALIR);

    return 0;
}