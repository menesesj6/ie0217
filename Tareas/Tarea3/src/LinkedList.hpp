/**
 * @file LinkedList.hpp
 * @author Jorge Meneses Garro
 * @brief EStructura de nodo para la creacion de un linked list.
 * 
 * @version 1.0
 * @date 2024-04-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

/**
 * @brief Estructura que define los nodos del linked list que hara como memoria del celular.
 * 
 */
struct ContactNode{
    string name; /**<- Nombre del contacto.*/
    int number; /**<- Numero del contacto*/
    ContactNode* nextContactNode; /**<- Direccion del siguiente contacto.*/
};

#endif