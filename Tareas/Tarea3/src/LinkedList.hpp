/**
 * @file Funciones.hpp
 * @author Jorge Meneses Garro
 * @brief Struct para la creacion del linked list que hara de memoria del celular.
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
#include <vector>
using namespace std;

/**
 * @brief EStructura que define los nodos del linked list que hara como memoria del celular.
 * 
 */
struct ContactNode{
    string name;
    int number;
    ContactNode* nextContactNode; 
};

#endif