#include "Funciones.hpp"

void addContact(HashTable* ht, ContactNode** head){
    string newname;
    int newnumber;
    ContactNode* newLLCon = (ContactNode*)malloc(sizeof(ContactNode));
    int choice;
    int index;

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

    if (*head == nullptr) {
        *head = newLLCon;
        return;
    }

    while (last->nextContactNode != NULL) {
        last = last->nextContactNode;
    }

    last->nextContactNode = newLLCon;
    
}

void addContactLL(ContactNode* newCon, ContactNode** head, string name, int num){
    
}

void deleteContact(HashTable* ht, ContactNode* con){
    int choice;
    string delname;
    // Pedir datos de eliminacion
    cout << "ELMINIAR CONTACTO" << endl;
    cout << "-----------------" << endl;
    cout << "De donde desea eliminarlo? Ingrese el numero de su eleccion." << endl;
    cout << "1. Cloud storage (Eliminacion total)" << endl; 
    cout << "2. Memoria del celular" << endl;
    cout << "\nEleccion: " << endl;
    cin >> choice; 

    cout << "Ingrese el nombre del contacto que desea eliminar: ";
    cin.ignore();
    getline(cin, delname);

    switch (choice){
        case 1:
            ht->deleteContact();
            deleteofLL(delname, &con);
            break;
        case 2:
            deleteofLL(delname, &con);
            break;
        default:
            break;
    }

}

void deleteofLL(string name, ContactNode** head){   
    while(*head != nullptr){
        if((*head)->name == name){
            if((*head)->nextContactNode == nullptr){
                (*head) = nullptr;
                break;
            }else if((*head)->nextContactNode != nullptr){
                (*head)->name = (*head)->nextContactNode->name;
                (*head)->number = (*head)->nextContactNode->number;
                (*head)->nextContactNode = (*head)->nextContactNode->nextContactNode;
                free((*head)->nextContactNode);
                cout << "Se ha eliminado a " << name << " exitosamente!"<< endl;
            }

        } 
        *head = (*head)->nextContactNode;
    }
}

void displayContacts(ContactNode* head){
    cout << "\nCONTACTOS EN ORDEN ALFABETICO" << endl;
    cout << "-------------------------------" << endl;
    if(head == nullptr){
        cout << "El celular esta vacio." << endl;
    }
    while(head != nullptr){
        cout << "Nombre: " << head->name << endl;
        cout << "Numero: " << head->number << endl << endl;
        head = head->nextContactNode;
    }
    cout << endl;
}

void freeLinkedList(ContactNode** head){
    while(*head != nullptr){
        ContactNode* temp = (*head)->nextContactNode;
        free(*head);
        *head = temp; 
    }
    cout << "Memoria limpia correctamente" << endl;
}

