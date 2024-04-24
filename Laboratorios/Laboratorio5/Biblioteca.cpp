#include"Biblioteca.hpp"

// Ingresar un nuevo libro a la biblioteca
void Biblioteca::agregarLibro(const Libro& libro) {
    libros.push_back(libro);
}

// Iterar el vector de libros de la biblioteca e imprimir sus datos
void Biblioteca::mostrarLibros() {
    for (const auto& libro : libros) {
        std::cout << libro.titulo << ", " << libro.autor << ", " << libro.anioPublicacion << std::endl;
    }
}

// Ordenar el vector de libros por anio de publicacion
// Los ordena usando el operador < que se sobrecargo
void Biblioteca::ordenarLibrosPorAnio() {
    std::sort(libros.begin(), libros.end());
}

// Usar funcion find_if para encontrar el primer objeto con el parametro pasado, en este caso el titulo del libro 'l'
std::vector<Libro>::iterator Biblioteca::buscarLibroPorTitulo(const std::string& titulo) {
    return std::find_if(libros.begin(), libros.end(), [&titulo](const Libro& l) {
        // Retornar que se encontro el nombre igual
        return l.titulo == titulo;
    });
}

// Obtener el ultimo libro del vector de la biblioteca
std::vector<Libro>::iterator Biblioteca::end() {
    return libros.end();
}
