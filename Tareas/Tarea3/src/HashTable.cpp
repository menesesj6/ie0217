#include "HashTable.hpp"

HashTable::HashTable(){
    // Iicializar todos los indices en null
    for(int i = 0; i < this->size; i++){
        this->contactList[i] = nullptr;
    }
}

HashTable::~HashTable(){
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
        x += name[i];
    }
    return x % this->size;
};

void HashTable::addContact(int num, string name){
    // Ingresar al linked list
    int index = this->hashFunction(name);
    Contact* newCon = (Contact*) malloc(sizeof(Contact));
    newCon->name = name;
    newCon->number = num;
    newCon->nextContact = nullptr;

    Contact* head = this->contactList[index];
    Contact** ptr_head = &head;

    if(head == nullptr){
        this->contactList[index] = newCon;
        return;
    }else{
        while(*ptr_head != nullptr){
            if((*ptr_head)->nextContact == nullptr){
                this->contactList[index]->nextContact = newCon;
            }
            (*ptr_head) = (*ptr_head)->nextContact;
        };  
    }
     

};

void HashTable::deleteContact(){

};

void HashTable::displayHash(){
    cout << "---------------------" << endl;
    cout << "ALMACENAMIENTO CLOUD" << endl;
    cout << "---------------------" << endl;
    for(int i = 0; i < size; i++){
        Contact* head = this->contactList[i];
        Contact** ptr_head = &head;
        cout << "Indice " << i << ":" << endl;
        if(head == nullptr){
            cout << "No hay nada almacenado en este indice.\n" << endl;
        }
        while(head != nullptr){
            cout << "Nombre: " << head->name << endl << endl;
            cout << "Numero: " << head->number << endl << endl;
            *ptr_head = (*ptr_head)->nextContact;
        }
    }
};



