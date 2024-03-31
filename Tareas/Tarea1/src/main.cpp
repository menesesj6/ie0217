#include <iostream>

#include "Ahorcado.hpp"
#include "Funciones.hpp"

#define MAX_DICTIONARY 15

using namespace std;


int main() {
    // Se instancia le struct
    Ahorcado ahorcado;

    // Inicializar variables de seleccion del menu
    int option;
    int dif = EASY; // Facil predeterminado

    // Definir diccionario predefinido con 7 palabras
    string dict[MAX_DICTIONARY] = {"curso", "nota", "codigo", "estructura", "intel", "programa", "linux"};
    int currWords = 7; // Cantidad inicial de palabras en el diccionario

    // Letra que adivinara el usuario
    char guess;

    // Definir el menu
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
                cout << "\n\n DIFICULTAD: \n" << dif << endl;
                break;

            // Inicio del juego
            case INICIAR:
                Initialize(currWords, &dif, dict, &ahorcado);
                break;

            // Agregar palabras al diccionario
            case AGREGAR:
                AddWords(&currWords, dict);
                cout << &dict[0] << endl;
                cout << &dict[1] << endl;
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