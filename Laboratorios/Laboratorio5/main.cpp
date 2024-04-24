#include "Biblioteca.hpp"

int main() {
    // Instanciar una biblioteca
    Biblioteca miBiblioteca;

    // Agregar libros iniciales
    miBiblioteca.agregarLibro({"Cien años de soledad", "Gabriel García Márquez", 1967});
    miBiblioteca.agregarLibro({"1984", "George Orwell", 1949});
    miBiblioteca.agregarLibro({"El señor de los anillos", "J.R.R. Tolkien", 1954});
    miBiblioteca.agregarLibro({"Dune", "Frank Herbert", 1965});

    // Ordenar los libros acomodados por anio
    miBiblioteca.ordenarLibrosPorAnio();

    std::cout << "Lista ordenada: " << std::endl; 
    std::cout << "---------------" << std::endl; 

    // Imrpimir los libros
    miBiblioteca.mostrarLibros();

    std::cout << std::endl;

    std::cout << "Buscando libro por titulo..." << std::endl; 
    // Encontrar un libro por titulo
    auto libro = miBiblioteca.buscarLibroPorTitulo("1984");
    // Imprimir que se encontro el libro
    if (libro != miBiblioteca.end()) {
        std::cout << "Libro encontrado: " << libro->titulo << std::endl;
    } else {
        std::cout << "Libro no encontrado." << std::endl;
    }

    std::cout << std::endl;

    // Agregar libros
    miBiblioteca.agregarLibro({"Harry Potter and the Philosopher's Stone", "J.K. Rowling", 1997});
    miBiblioteca.agregarLibro({"La Divina Comedia", "Dante Alighieri", 1314});
    miBiblioteca.agregarLibro({"Orgullo y Prejuicio", "Jane Austen", 1813});
    miBiblioteca.agregarLibro({"Mobby Dick", "Herman Melville", 1851});
    miBiblioteca.agregarLibro({"El secreto de Wilhelm Storitz", "Julio Verne", 1910});

    // Imprimir lista desordenada con nuevos libros
    std::cout << "Lista desordenada: " << std::endl; 
    std::cout << "------------------" << std::endl; 
    miBiblioteca.mostrarLibros();

    // Ordenar la lista
    std::cout << std::endl;
    std::cout << "Ordenando lista..." << std::endl; 
    miBiblioteca.ordenarLibrosPorAnio();
    std::cout << std::endl;

    // Imprimir lista ordenada con nuevos libros
    std::cout << "Lista ordenada: " << std::endl; 
    std::cout << "---------------" << std::endl; 
    miBiblioteca.mostrarLibros();

    // BUscar un libro que no esta
    std::cout << "\nBuscando Harry Potter and the Goblet of Fire..." << std::endl; 
    auto libro1 = miBiblioteca.buscarLibroPorTitulo("Buscando Harry Potter and the Goblet of Fire");
    if (libro1 != miBiblioteca.end()) {
        std::cout << "Libro encontrado: " << libro->titulo << std::endl;
    } else {
        std::cout << "Libro no encontrado." << std::endl;
    }

    return 0;
}
