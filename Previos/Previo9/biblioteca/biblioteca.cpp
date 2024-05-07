#include<iostream>
#include"biblioteca.hpp"

void Biblioteca::agregarLibro(
    const std::string& titulo,
    const std::string& autor
){
    // Agregar el libro al catalogo
    catalogo.emplace_back(titulo, autor);
}

void Biblioteca::mostrarCatalogo(){
    // Iterar catalogo
    for(const auto& libro : catalogo){
        // Llamar el metodo del libro
        libro.mostrarInfo();
    }
}