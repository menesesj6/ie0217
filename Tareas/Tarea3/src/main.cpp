/**
 * @file main.cpp
 * @author Jorge Meneses Garro
 * @brief Implementacion principal del programa
 * @version 1.0
 * @date 2024-04-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */
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
    ht.addContact(84139015, "Esteban Badilla");

    // COntacto inicial del celular
    ContactNode* head = (ContactNode*) malloc(sizeof(ContactNode));
    ContactNode* second = (ContactNode*) malloc(sizeof(ContactNode));
    head->name = "Jorge Meneses";
    head->number = 84310164;
    head->nextContactNode = second;

    second->name = "Esteban Badilla";
    second->number = 84139015;
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
            // Agregar contacto
            case AGREGAR:
                addContact(&ht, &head);
                break;
            // ELiminar contacto
            case ELIMINAR:
                deleteContact(&ht, &head);
                break;
            // Imprimir almacenamiento cloud
            case PRINTHTLL:
                ht.displayHash();
                break;
            // Imprimir contactos celular
            case DISPLAY:
                orderLL(head);
                displayContacts(&head);
                break;
            // Salir del programa
            case SALIR:
                // Liberar memoria
                freeLinkedList(&head);
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }

    } while (option != SALIR);
    return 0;
}