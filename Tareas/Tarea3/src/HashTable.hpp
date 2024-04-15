#ifndef HASHTAHBLE_HPP
#define HASHTAHBLE_HPP
#include  <iostream>
#include <string>
#include <vector>
using namespace std;

#define MAX_CONTACTS 20

// Elemento del hash table
struct Contact{
    int number;
    string name;
    Contact* nextContact;
};

// Hash Table
class HashTable{
    private:
        int size = MAX_CONTACTS;
    public:
        HashTable();
        ~HashTable();
        Contact* contactList[MAX_CONTACTS];
        int hashFunction(string name);
        void addContact(string name, int index);
        void deleteContact();
        void displayHash();
};

#endif