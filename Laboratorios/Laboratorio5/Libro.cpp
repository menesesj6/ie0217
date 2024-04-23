#include "Libro.hpp"

Libro::Libro(std::string t, std::string a, int anio) : titulo(t), autor(a), anioPublicacion(anio) {}


bool Libro::operator<(const Libro& l) const {
            return anioPublicacion < l.anioPublicacion;
};