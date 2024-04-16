#ifndef HASHTAHBLE_HPP
#define HASHTAHBLE_HPP
#include  <iostream>
#include <string>
#include <vector>
using namespace std;

#define MAX_CONTACTS = 100;
#define MAX_INDEXES 20

// Elemento del hash table
struct Contact{
    int number;
    string name;
    Contact* nextContact;
};

// Hash Table
class HashTable{
    private:
        int size = MAX_INDEXES;
    public:
        HashTable();
        ~HashTable();
        Contact* contactList[MAX_INDEXES];
        int hashFunction(string name);
        void addContact(int num, string name);
        void deleteContact(string name);
        void displayHash();
};

#endif