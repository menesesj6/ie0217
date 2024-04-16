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

    Contact** ptr_head = &(this->contactList[index]);

    if(this->contactList[index] == nullptr){
        this->contactList[index] = newCon;
        return;
    }

    while ((*ptr_head)->nextContact != NULL) {
        ptr_head = &((*ptr_head)->nextContact);
    }

    (*ptr_head)->nextContact = newCon;
    
     

};

void HashTable::deleteContact(string delname){
    int index = this->hashFunction(delname);
    if(this->contactList[index]->name == delname){
        this->contactList[index] = nullptr;
    }

    while(this->contactList[index] != nullptr){
        if(this->contactList[index]->name == delname && this->contactList[index]->nextContact != nullptr){
            Contact* temp = this->contactList[index]->nextContact->nextContact;
            this->contactList[index]->name = this->contactList[index]->nextContact->name;
            this->contactList[index]->number = this->contactList[index]->nextContact->number;
            free(this->contactList[index]->nextContact);
            this->contactList[index]->nextContact = temp;
            return;
            
        }else if(this->contactList[index]->name == delname && this->contactList[index]->nextContact == nullptr){
            this->contactList[index] = nullptr;
            return;

        }else{
            this->contactList[index] = this->contactList[index]->nextContact;
        }
    }

};

void HashTable::displayHash(){
    cout << "\n---------------------" << endl;
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



