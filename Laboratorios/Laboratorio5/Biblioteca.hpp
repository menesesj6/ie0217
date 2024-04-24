#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include"Libro.hpp"

// Inicializacion de la clase Biblioteca
class Biblioteca {
private:
    // Todos los libros de la biblioteca
    std::vector<Libro> libros;
public:
    // Metodos de la clase
    void agregarLibro(const Libro& libro);
    void mostrarLibros();
    void ordenarLibrosPorAnio();
    std::vector<Libro>::iterator buscarLibroPorTitulo(const std::string& titulo);
    std::vector<Libro>::iterator end();
};

#endif