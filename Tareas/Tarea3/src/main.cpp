#include <iostream>
#include "Funciones.hpp"
#include "Enum.hpp"
#include "HashTable.hpp"

using namespace std;


int main(){
    // Instanciar Hash Table y Liked List
    HashTable ht;

    // COntacto inicial en el cloud
    ht.addContact(84310164, "Jorge Meneses");
    ht.addContact(85002305, "Daniela Granados");

    // COntacto inicial del celular
    ContactNode* head = (ContactNode*) malloc(sizeof(ContactNode));
    ContactNode* second = (ContactNode*) malloc(sizeof(ContactNode));
    head->name = "Jorge Meneses";
    head->number = 84310164;
    head->nextContactNode = second;

    second->name = "Daniela Granados";
    second->number = 85002305;
    second->nextContactNode = nullptr;

    

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
                addContact(&ht, &head);
                break;
            case ELIMINAR:
                deleteContact(&ht, head);
                break;
            case PRINTHTLL:
                ht.displayHash();
                break;
            case DISPLAY:
                orderLL(head);
                displayContacts(&head);
                break;
            case SALIR:
                freeLinkedList(&head);
                displayContacts(&head);
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }

    } while (option != SALIR);
    return 0;
}