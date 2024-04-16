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

    // Ingresar al Hash Table
    ht->addContact(newnumber, newname);
    
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
            ht->deleteContact(delname);
            cout << "Se elimino a " << delname << " del cloud!" << endl;
            deleteofLL(delname, &con);
            cout << "Se elimino a " << delname << " del celular!" << endl;
            break;
        case 2:
            deleteofLL(delname, &con);
            break;
        default:
            break;
    }

}

void deleteofLL(string name, ContactNode** head){   
    ContactNode* temp;
    while((*head) != nullptr){
        if((*head)->name == name && (*head)->nextContactNode != nullptr){
            (*head)->name = (*head)->nextContactNode->name;
            (*head)->number = (*head)->nextContactNode->number;
            temp = (*head)->nextContactNode->nextContactNode;
            free((*head)->nextContactNode);
            (*head)->nextContactNode = temp;
            cout << "Se ha eliminado a " << name << " exitosamente!"<< endl;
            return;
        } else if((*head)->name == name && (*head)->nextContactNode == nullptr){
            (*head) = nullptr;
            return;

        }
        head = &((*head)->nextContactNode);
    }
    
}

void displayContacts(ContactNode** head){
    cout << "\nCONTACTOS EN ORDEN ALFABETICO" << endl;
    cout << "-------------------------------" << endl;
    if(*head == nullptr){
        cout << "El celular esta vacio." << endl;
    }
    while(*head != nullptr){
        cout << "Nombre: " << (*head)->name << endl;
        cout << "Numero: " << (*head)->number << endl << endl;
        head = &((*head)->nextContactNode);
    }
    cout << endl;
}

void orderLL(ContactNode* con){
    string tempstr;
    int tempint, check;
    ContactNode* memory = con;
    ContactNode** head = &con;
    bool swapped = true;

    while(swapped){
        swapped = false;
        head = &memory;

        while((*head)->nextContactNode != nullptr){
        check = (*head)->name.compare((*head)->nextContactNode->name);
        if(check == 0 || check < 0){
            head = &((*head)->nextContactNode);
        } else{
            tempstr = (*head)->name;
            tempint = (*head)->number;
            (*head)->name = (*head)->nextContactNode->name;
            (*head)->number = (*head)->nextContactNode->number;

            (*head)->nextContactNode->name = tempstr;
            (*head)->nextContactNode->number = tempint;

            swapped = true;
            head = &((*head)->nextContactNode);
        }
    }       
    }
    
}

void freeLinkedList(ContactNode** head){
    while(*head != nullptr){
        ContactNode* temp = (*head)->nextContactNode;
        free(*head);
        *head = temp; 
    }
    cout << "Memoria limpia correctamente" << endl;
}

