// Define condicional
#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "Contacto.hpp"

// Se definen los encabezados de las funciones
void agregarContacto(Contacto listaContactos[], int &numContactos); // Referencia de numContactos, pues se ocupa modificar
void mostrarContactos(const Contacto listaContactos[], int numContactos); // Lo constante se va a guardar a la memoria de instrucciones
void buscarContacto(const Contacto listaContactos[], int numContactos);
// Esto es conocido como firmas

#endif //FUNCIOPNES_HPP