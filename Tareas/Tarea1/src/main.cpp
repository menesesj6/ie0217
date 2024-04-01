#include <iostream>
#include "Ahorcado.hpp"
#include "Funciones.hpp"
using namespace std;

int main() {
    // Se instancia e; struct
    Ahorcado ahorcado;

    int option; /**< Eleccion del menu principal*/
    int dif = EASY; /**< Dificultad, con un valor de 1 (FACIL) predeterminado*/

    string dict[MAX_DICTIONARY] = {"curso", "nota", "codigo", "estructura", "intel", "programa", "linux", "pollo"}; /**< Diccionario prefedinido del juego*/
    int currWords = 8; // Cantidad inicial de palabras en el diccionario

    // Definir el menu principal
    do{
        cout << "\nMENU" << endl;
        cout << "1. Elegir dificultad del juego. " << endl;
        cout << "2. Iniciar juego. " << endl;
        cout << "3. Agregar palabras al diccionario del juego. " << endl;
        cout << "4. Ver el diccionario de palabras. " << endl;
        cout << "5. Salir. " << endl;

        cout << "Ingrese el numero de su eleccion: ";
        cin >> option;
        cout << " " << endl;

        switch(option){
            // Configuracion de dificultad
            case DIFICULTAD:
                SetDifficulty(&dif);
                break;

            // Inicio del juego
            case INICIAR:
                Initialize(currWords, &dif, dict, &ahorcado);
                Guessing(&ahorcado);
                break;

            // Agregar palabras al diccionario
            case AGREGAR:
                AddWords(&currWords, dict);
                break;

            // Ver diccionario
            case DICCIONARIO:
                PrintDictionary(currWords, dict);
                break;

            // Salir del juego
            case SALIR:
                cout << "Gracias por jugar! Saliendo..." << endl;
                break;

            // Caso default, eleccion invalida
            default:
                cout << "Ingrese uno de los numeros disponibles." << endl;
                break;
        }
    }while(option != SALIR);

    return 0;
}