/**
 * @file HashTable.hpp
 * @author Jorge Meneses Garro
 * @brief Struct de los nodos para la slinked lists del Hash table y la clase de Hash-Table.
 * 
 * @version 1.0
 * @date 2024-04-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef HASHTAHBLE_HPP
#define HASHTAHBLE_HPP
#include  <iostream>
#include <string>
#include <vector>
using namespace std;

#define MAX_INDEXES 20

/**
 * @brief Estructura de un nodo para una linked list.
 * 
 * Estos nodos son usados para la creacion de las listas enlazadas de cada indice en el Hash Table.
 */
struct Contact{
    int number; /**<- Numero del contacto.*/
    string name; /**<- Nombre del contacto.*/
    Contact* nextContact; /**<- Direccion del siguiente contacto.*/
};

/**
 * @brief Clase que define un Hash-Table
 * 
 */
class HashTable{
    private:
        int size = MAX_INDEXES; /**<- Cantidad de indices en el Hash-Table.*/
    public:
        Contact* contactList[MAX_INDEXES]; /**<- Array de punteros tipo Contact, un puntero por indice.*/

        /**
         * @brief Constructor de un objeto tipo Hash-Table
         * 
         * Inicializa todos sus indices con un puntero nulo, para ser accesible a crear linked lists en cada uno.
         * 
         */
        HashTable();

        /**
         * @brief Destructor de un objeto tipo Hash-Table
         * 
         * Libera toda la memoria usada para el Hash-Table, incluido cada nodo de sus linked lists asociadas a los indices.
         * 
         */
        ~HashTable();

        /**
         * @brief Computa el indice del Hash-Table donde se almacenara el par llave-valor
         * 
         * @param name Llave en base a la cual se calcula el indice del Hash-Table.
         * @return int INdice del Hash-Table donde se almacenara el contacto.
         */
        int hashFunction(string name);

        /**
         * @brief Agrega un contacto al Hash-Table.
         * 
         * Agrega el nuevo contacto al indice elegido. En caso de colisiones, hace uso de chaining para poner el nuevo contacto en el ultimo nodo de la linked list asociada.
         * 
         * @param num Numero del nuevo contacto.
         * @param name Nombre del nuevo contacto.
         */
        void addContact(int num, string name);

        /**
         * @brief Elimina un contacto del Hash-Table
         * 
         * @param name Nombre del contacto que se deaea eliminar.
         */
        void deleteContact(string name);

        /**
         * @brief Imprime la informacion de todos los indices del Hash-Table, tengan o no contenido.
         * 
         */
        void displayHash();
};

#endif