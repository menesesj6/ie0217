#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include "HashTable.hpp"
#include "LinkedList.hpp"
// Funciones para el linked list

void addContact(HashTable* ht, ContactNode** head);
void addContactLL(ContactNode* newCon, ContactNode** head, string name, int num);
void deleteContact(HashTable* ht, ContactNode* con);
void deleteofLL(string name, ContactNode** head);
void displayContacts(ContactNode* head);
void freeLinkedList(ContactNode** head);


#endif