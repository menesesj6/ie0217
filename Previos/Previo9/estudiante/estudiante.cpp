#include<iostream>
#include"estudiante.hpp"

// Constructor parametrizado
Estudiante::Estudiante(
    const std::string& nombre, int edad
) : nombre(nombre), edad(edad) {}

void Estudiante::mostrarDatos(){
    // IMprimir datos
    std::cout << "Nombre: " << nombre;
    std::cout << ", Edad: " << edad << std::endl;
}