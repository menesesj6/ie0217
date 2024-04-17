/**
 * @file Funciones.cpp
 * @author Jorge Meneses Garro
 * @brief Definicion de las funciones del programa
 * @version 1.0
 * @date 2024-04-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "Funciones.hpp"

void addContact(HashTable* ht, ContactNode** head){
    // NOmbre nuevo contacto
    string newname;
    // Numero nuevo contacto
    int newnumber;
    // Alocar memoria de un nuevo objeto ContactNode
    ContactNode* newLLCon = (ContactNode*) calloc(1, sizeof(ContactNode));
    // Pedir los datos al usuario
    cout << "AGREGAR CONTACTO" << endl;
    cout << "-----------------" << endl;
    cout << "Ingrese los datos del nuevo contacto." << endl;
    cout << "Nombre: ";
    cin.ignore();
    getline(cin, newname); 
    cout << "Numero: ";
    cin >> newnumber;

    // Ingresar al linked list
    ContactNode* last = *head;
    newLLCon->name = newname;
    newLLCon->number = newnumber;
    newLLCon->nextContactNode = nullptr;
    
    // Caso 1: El nodo es null, lo asigna
    if (last == nullptr) {
        *head = newLLCon;
        ht->addContact(newnumber, newname);
        return;
    }

    // Caso 2: Itera la linked list y pone el nuevo contacto al final
    while (last->nextContactNode != NULL) {
        last = last->nextContactNode;
    }

    last->nextContactNode = newLLCon;

    // Ingresar contacto al Hash Table
    ht->addContact(newnumber, newname);
    
}


void deleteContact(HashTable* ht, ContactNode** con){
    // Eleccion sobre de donde se eliminara
    int choice;
    // Nombre del contacto a eliminar
    string delname;
    // Pedir datos de eliminacion
    cout << "ELMINIAR CONTACTO" << endl;
    cout << "-----------------" << endl;
    cout << "De donde desea eliminarlo? Ingrese el numero de su eleccion." << endl;
    cout << "1. Cloud storage (Eliminacion total)" << endl; 
    cout << "2. Memoria del celular" << endl;
    cout << "\nEleccion: ";
    cin >> choice; 
    cout << endl;

    cout << "Ingrese el nombre del contacto que desea eliminar: ";
    cin.ignore();
    getline(cin, delname);

    switch (choice){
        case 1:
            // Eliminar contacto del hash tabe y del linked list aparte
            ht->deleteContact(delname);
            cout << "Se elimino a " << delname << " del cloud!" << endl;
            deleteofLL(delname, con);
            cout << "Se elimino a " << delname << " del celular!" << endl;
            break;
        case 2:
            // Eliminar solo de la linked list aparte (memoria celular)
            deleteofLL(delname, con);
            cout << "Se elimino a " << delname << " del celular!" << endl;
            break;
        default:
            break;
    }

}

void deleteofLL(string name, ContactNode** head){   
    ContactNode* temp; // Variable temporal, como en swap

    if((*head)->name == name && (*head)->nextContactNode == nullptr){
        *head = nullptr;
        return;
    }

    while((*head) != nullptr){
        // Caso #1: se encuentra el nombre y el proximo nodo no es nulo
        if((*head)->name == name && (*head)->nextContactNode != nullptr){
            // Se copian los datos del proximo y se elimina el siguiente
            (*head)->name = (*head)->nextContactNode->name;
            (*head)->number = (*head)->nextContactNode->number;
            temp = (*head)->nextContactNode->nextContactNode;
            free((*head)->nextContactNode);
            (*head)->nextContactNode = temp;
            return;
        // Caso #2: sencuentra el nombre y el proximo nodo es nulo (fin de la lista)
        } else if((*head)->name == name && (*head)->nextContactNode == nullptr){
            (*head) = nullptr;
            return;
        }
        // Apuntar al siguiente nodo de la lista enlazada
        head = &((*head)->nextContactNode);
    } 
}

void displayContacts(ContactNode** head){
    cout << "\nCONTACTOS EN ORDEN ALFABETICO" << endl;
    cout << "-------------------------------" << endl;
    // Caso en que el primero sea null (NO hay lista)
    if(*head == nullptr){
        cout << "El celular esta vacio." << endl << endl;
        return;
    }
    // Iterar lista e imprimir valores
    while(*head != nullptr){
        cout << "Nombre: " << (*head)->name << endl;
        cout << "Numero: " << (*head)->number << endl << endl;
        head = &((*head)->nextContactNode);
    }
    cout << endl;
}

void orderLL(ContactNode* con){
    // Almacena el nombre para hacer el swap
    string tempstr;
    // Almacena el numero para hacer el swap
    int tempint;
    // Guarda el valor de la comparacion de strings
    int check;

    ContactNode* memory = con;
    ContactNode** head = &con;
    bool swapped = true;
    // Caso que no haya nada
    if(con == nullptr){
        return;
    }
    // Algoritmo de acomodo en orden alfabetico
    // Mantener un loop while siempre que haya habido un cambio entre los nodos
    while(swapped){
        swapped = false; // Se pone qu eno hubo swaps,
        head = &memory; // Puntero base

        // Iterar la lista enlazada
        while((*head)->nextContactNode != nullptr){
        // Obtener la comparacion entre el nombre del contacto actual y del proximo
        check = (*head)->name.compare((*head)->nextContactNode->name);
        // Casos en los que no pasa nada
        if(check == 0 || check < 0){
            head = &((*head)->nextContactNode);
        } else{
            // Intercambiar nombre y numero
            tempstr = (*head)->name;
            tempint = (*head)->number;
            (*head)->name = (*head)->nextContactNode->name;
            (*head)->number = (*head)->nextContactNode->number;

            (*head)->nextContactNode->name = tempstr;
            (*head)->nextContactNode->number = tempint;

            // Indicar que si hubo un cambio
            swapped = true;
            // Apuntar al proximo contacto
            head = &((*head)->nextContactNode);
        }
    }       
    }
    
}

void freeLinkedList(ContactNode** head){
    // Iterar por toda la linked list y liberar la memoria
    while(*head != nullptr){
        ContactNode* temp = (*head)->nextContactNode;
        free(*head);
        *head = temp; 
    }
}

