#ifndef LIBRO_HPP
#define LIBRO_HPP

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

class Libro {
    public:
        std::string titulo;
        std::string autor;
        int anioPublicacion;

        Libro(std::string t, std::string a, int anio) : titulo(t), autor(a), anioPublicacion(anio) {}

        bool operator<(const Libro& l) const;
};

#endif