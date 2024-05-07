#ifndef LIBRO_HPP
#define LIBRO_HPP

#include <string>

class Libro{
    public:
        // COnstructor parametrizado
        Libro(const std::string& titulo, const std::string& autor);
        // Metodo de imprimir datos
        void mostrarInfo() const;
    private:
        // Atributos de informacion
        std::string titulo;
        std::string autor;
};

#endif