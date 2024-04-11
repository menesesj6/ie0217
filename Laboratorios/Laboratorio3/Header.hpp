#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <string>

using namespace std;

// Elementos de lista enlazada
struct Libro{
    // ELementos normales
    string titulo; 
    string autor;
    string genero;
    
    // Direccion del proximo elemento de la lista
    Libro* siguiente;
};

// Enum para mejor legibilidad del menu
enum opciones{
    AGREGAR_LIBRO = 1,
    MOSTRAR_LIBRO,
    SALIR,
    OPCIONES_MAX
};

#endif