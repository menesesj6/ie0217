/**
 * @file Funciones.hpp
 * @author Jorge Meneses Garro
 * @brief Prototipos de funciones base para el funcionamienot del programa. 
 * 
 * @version 1.0
 * @date 2024-04-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include "HashTable.hpp"
#include "LinkedList.hpp"

/**
 * @brief Agrega un contacto al Hash-Table y al linked list aparte
 * 
 * @param ht Puntero al Hash-Table existente que hace como la memoria cloud.
 * @param head Doble puntero hacia el primer nodo del linked list de la memoria dle celular.
 */
void addContact(HashTable* ht, ContactNode** head);

/**
 * @brief Elimina un contacto solo del celular o de la nube y el celular.
 * 
 * Se le solicita al usuario que indique si desea eliminar el contacto solo de la memoria del celular o si tambien del cloud, eliminandolo totalmente. ELimina el ususario basado en el nombre deseado.
 * 
 * @param ht Puntero al Hash-Table existente que hace como la memoria cloud.
 * @param con Primer nodo de la linked list que hace de memoria del celular.
 */
void deleteContact(HashTable* ht, ContactNode* con);

/**
 * @brief Elimina un contacto de un linked list
 * 
 * @param name Nombre del contacto que se desea eliminar.
 * @param head Doble puntero hacia el primer nodo del linked list de la memoria del celular.
 */
void deleteofLL(string name, ContactNode** head);

/**
 * @brief Imprime los contactos en orden alfabetico.
 * 
 * @param head Primer nodo de la linked list que hace de memoria del celular.
 */
void displayContacts(ContactNode* head);

/**
 * @brief LIbera la memoria de toda la linked list que hace de memoria del celular
 * 
 * @param head Doble puntero hacia el primer nodo del linked list de la memoria del celular.
 */
void freeLinkedList(ContactNode** head);


#endif