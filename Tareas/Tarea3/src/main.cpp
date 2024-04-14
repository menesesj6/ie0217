#include <iostream>
#include "Enum.hpp"
#include "HashTable.hpp"

using namespace std;


int main(){
    // Instanciar Hash Table
    HashTable ht;
    // Eleccion del menu
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
                ht.addContact();
                break;
            case ELIMINAR:
                ht.deleteContact();
                break;
            case PRINTHTLL:
                ht.printHTLL();
                break;
            case DISPLAY:
                ht.displayContacts();
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