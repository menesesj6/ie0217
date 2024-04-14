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
        const int size = MAX_CONTACTS;
        vector<Contact*> contactList;
        int hashFunction(string name);
    public:
        HashTable();
        ~HashTable();
        void addContact();
        void deleteContact();
        void printHTLL();
        void displayContacts();
};

#endif