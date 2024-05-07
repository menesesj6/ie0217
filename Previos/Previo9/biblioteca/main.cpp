#include"biblioteca.hpp"

int main(){
    // Instanciar objeto tipo biblioteca
    Biblioteca biblioteca;

    // Agregar libros
    biblioteca.agregarLibro("El Gran Gatsby", "F. Scot FItzgerald");
    biblioteca.agregarLibro("1984", "George Orwell");

    // Obtener catalogo
    biblioteca.mostrarCatalogo();

    return 0;
}