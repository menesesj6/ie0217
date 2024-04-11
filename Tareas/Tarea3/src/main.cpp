#include <iostream>
#include "Enum.hpp"

using namespace std;


int main(){
    int option;
    do{
        cout << "----------------------" << endl;
        cout << "GESTION DE CONTACTOS" << endl;
        cout << "----------------------" << endl << endl;
        cout << "MENU:" << endl;
        cout << "1. Agregar contacto" << endl;
        cout << "2. Eliminar contacto" << endl;
        cout << "3. Imprimir hash-table y linked list" << endl;
        cout << "4. Mostrar todos los contactos" << endl;
        cout << "5. Salir" << endl;
        cout << "Su seleccion: ";
        cin >> option;
        switch (option) {
            case AGREGAR:
                break;
            case ELIMINAR:
                break;
            case PRINTHTLL:
                break;
            case DISPLAY:
                break;
            case SALIR:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }

    } while (option != SALIR);
    
    return 0;
}