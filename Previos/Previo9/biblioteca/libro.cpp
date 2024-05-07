#include<iostream>
#include"libro.hpp"

// Constructor parametrizado
Libro::Libro(
    const std::string& titulo, const std::string& autor
) : titulo(titulo), autor(autor){}

// Imprimir data
void Libro::mostrarInfo() const {
    std::cout << "Titulo: " << titulo << ", Autor: " << autor << std::endl;
}