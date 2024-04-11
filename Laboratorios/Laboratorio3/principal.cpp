#include "Funciones.hpp"

int main(){
    
    // Puntero nulo inicial
    Libro* listaLibros = nullptr;

    // Opcion del menu
    int opcion;

    // Menu
    do{
        cout << "Seleccione su opcion:" << endl;
        cout << "1. Agregar libro" << endl;
        cout << "2. Mostrar todos los libros" << endl;
        cout << "3. Salir" << endl; 
        cin >> opcion;

        switch (opcion){
            // Agregar libro
            case AGREGAR_LIBRO:
                agregarLibro(listaLibros);
                break;

            // Imprimir lista
            case MOSTRAR_LIBRO:
                mostrarLibros(listaLibros);
                break;

            // Salir
            case SALIR:
                cout << "Saliendo del programa..." << endl;
                break;

            // Seleccion invalida
            default:
                cout << "Opcion invalida." << endl;
                break;
        }

    } while(opcion != SALIR);

    // Limpiar memoria asignada dinamicamente
    liberarMemoria(listaLibros);
    
    return 0;
}