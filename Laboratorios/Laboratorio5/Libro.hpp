#ifndef LIBRO_HPP
#define LIBRO_HPP

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

// Inicializacion de clase Libro
class Libro {
    public:
        // Atributos
        std::string titulo;
        std::string autor;
        int anioPublicacion;
        
        // Metodos
        Libro(std::string t, std::string a, int anio);
        bool operator<(const Libro& l) const;
};

#endif