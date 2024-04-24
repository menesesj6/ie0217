#include "Libro.hpp"

/* Constructor de la clase por parametros.

Requiere titulo, autor y anio de publicacion para instanciar un libro.
*/
Libro::Libro(std::string t, std::string a, int anio) : titulo(t), autor(a), anioPublicacion(anio) {}

/* Sobrecarga del operador <

Compara los anios de publicacion de dos objetos tipo Libro
*/
bool Libro::operator<(const Libro& l) const {
    return anioPublicacion < l.anioPublicacion;
};
