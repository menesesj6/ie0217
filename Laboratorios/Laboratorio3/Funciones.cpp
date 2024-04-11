#include "Funciones.hpp"
// Se usa *& porque es la referencia a una variable de tipo Libro puntero
// Si envio solo Libro*, hay que hacer mas manipulacion para asignar todo
void agregarLibro(Libro*& lista){
    // Reservar un espacio en el heap
    Libro* nuevoLibro = new Libro;

    // Pedir datos al usuario
    cout << "Ingrese el titulo del libro: " << endl;
    cin.ignore();
    getline(cin, nuevoLibro->titulo);

    cout << "Ingrese el autor del libro: " << endl;
    getline(cin, nuevoLibro->autor);

    cout << "Ingrese el genero del libro: " << endl;
    getline(cin, nuevoLibro->genero);

    // Cambiar el siguiente elemento linear del nuevo libro
    nuevoLibro->siguiente = lista;

    // Cambiar al nuevo elemento de la lista
    lista = nuevoLibro;

    cout << "Libro agregado correctamente!" << endl;
}

void mostrarLibros(Libro* lista){
    // Revisa si hay algo
    if(lista == nullptr){
        cout << "La libreria no tiene libros" << endl;
        return;
    }

    // Imprime los libros hasta que haya un nullptr
    cout << "Lista de libros: " << endl;
    while (lista != nullptr){
        cout << "Titulo: " << lista->titulo << endl;
        cout << "Autor: " << lista->autor << endl;
        cout << "Genero: " << lista->genero << endl << endl;
        lista = lista->siguiente; // Pasa de elemento
    }
}

void liberarMemoria(Libro*& lista){
    // Va liberando memoria hasta encontrarse un nullptr
    // Usa una variable temporal para esto
    while(lista != nullptr){
        Libro* temp = lista;
        lista = lista->siguiente;
        delete temp;
    }
}