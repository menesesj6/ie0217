#include "HashTable.hpp"

HashTable::HashTable(){
    // INicializar todos los indices en null
    for(int i = 0; i < size; i++){
        contactList[i] = nullptr;
    }
}

HashTable::~HashTable(){
    
}

int HashTable::hashFunction(string name){
    int x = 0;
    for(int i = 0; i < name.length(); i++){
        x += name[i];
    }
    return x % this->size;
};

void HashTable::addContact(){
    Contact* newContact = (Contact*) malloc(sizeof(Contact)); 
};

void HashTable::deleteContact(){

};

void HashTable::printHTLL(){

};

void HashTable::displayContacts(){

};

