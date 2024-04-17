/**
 * @file HashTable.cpp
 * @author Jorge Meneses
 * @brief Definicion de metodos de la clase HashTable
 * @version 1.0
 * @date 2024-04-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "HashTable.hpp"

HashTable::HashTable(){
    // Iicializar todos los indices en null
    for(int i = 0; i < this->size; i++){
        this->contactList[i] = nullptr;
    }
}

HashTable::~HashTable(){
    // Liberar la memoria de cada linked list en cada indice del Hash-Table
    for(int i = 0; i < size; i++){
        Contact* head = this->contactList[i];
        while(head != nullptr){
            Contact* temp = head->nextContact;
            free(head);
            head = temp;
        }
    }
}

int HashTable::hashFunction(string name){
    int x = 0;
    for(int i = 0; i < name.length(); i++){
        // Obtener el valor ASCII del string entero
        x += name[i];
    }
    // Retornar el indice
    return x % this->size;
};

void HashTable::addContact(int num, string name){
    // Ingresar al linked list
    int index = this->hashFunction(name);
    // Alocar nuevo nodo de tipo COntact
    Contact* newCon = (Contact*) malloc(sizeof(Contact));
    // Asignar data al nuevo nodo
    newCon->name = name;
    newCon->number = num;
    newCon->nextContact = nullptr;

    // Doble puntero al nodo base del linked list del del indice
    Contact** ptr_head = &(this->contactList[index]);

    // Caso #1: NOdo base es null, se asigna el nuevo ahi directamente
    if(this->contactList[index] == nullptr){
        this->contactList[index] = newCon;
        return;
    }

    // Caso #2: Iterar linked list hasta encontrar donde ingresar el nuevo nodo
    while ((*ptr_head)->nextContact != NULL) {
        ptr_head = &((*ptr_head)->nextContact);
    }
    // Ingresar el nuevo nodo
    (*ptr_head)->nextContact = newCon;
    
};

void HashTable::deleteContact(string delname){
    // OBtener indice del contacto que se desea eliminar
    int index = this->hashFunction(delname);

    // Caso que sea una linked list de solo uno
    if(this->contactList[index]->name == delname && this->contactList[index]->nextContact == nullptr){
        this->contactList[index] = nullptr;
    }

    // Caso contrario, iterar hasta eliminar el correcto y cubrir el hueco en la conexion
    while(this->contactList[index] != nullptr){
        // Caso que este en medio del linked list
        if(this->contactList[index]->name == delname && this->contactList[index]->nextContact != nullptr){
            Contact* temp = this->contactList[index]->nextContact->nextContact;
            this->contactList[index]->name = this->contactList[index]->nextContact->name;
            this->contactList[index]->number = this->contactList[index]->nextContact->number;
            free(this->contactList[index]->nextContact);
            this->contactList[index]->nextContact = temp;
            return;
        // Caso que sea el ultimo del linked list
        }else if(this->contactList[index]->name == delname && this->contactList[index]->nextContact == nullptr){
            this->contactList[index] = nullptr;
            return;

        }else{
            // Cambiar al siguiente contacto
            this->contactList[index] = this->contactList[index]->nextContact;
        }
    }

};

void HashTable::displayHash(){
    cout << "\n---------------------" << endl;
    cout << "ALMACENAMIENTO CLOUD" << endl;
    cout << "---------------------" << endl;
    // Iterar todos los indices
    for(int i = 0; i < size; i++){
        Contact* head = this->contactList[i];
        Contact** ptr_head = &head;
        cout << "Indice " << i << ":" << endl;
        // Indicar cuando no hay nada en el indice
        if(head == nullptr){
            cout << "No hay nada almacenado en este indice.\n" << endl;
        }
        // Iterar la linked list de los indices que tienen e imprimir
        while(head != nullptr){
            cout << "Nombre: " << head->name << endl;
            cout << "Numero: " << head->number << endl << endl;
            *ptr_head = (*ptr_head)->nextContact;
        }
    }
};



