#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include <vector>
#include"libro.hpp"

class Biblioteca{
    public:
        // Metodo de agregar libro
        void agregarLibro(
            const std::string& titulo,
            const std::string& autor
        );
        // Metodo de imprimir libros
        void mostrarCatalogo();
    private:
        // Lista de libros
        std::vector<Libro> catalogo;
};

#endif