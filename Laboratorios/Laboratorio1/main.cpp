// Libreria basica
#include <iostream>
// Incluir los headers
#include "Contacto.hpp"
#include "Funciones.hpp"

// Macro que define el maximo de contactos
#define MAX_CONTACTOS 100

// Enum para el menu
enum Opciones{
    AGREGAR = 1,
    MOSTRAR, // = 2
    BUSCAR, // = 3
    SALIR // = 4
};

// Programa entero asume happy path, que todo se va a ameter bien, sin errores.

int main() {
    /*Instanciacion del struct
    
    ES un array de 100 espacios, cada uno del array tendra nombre y telefono
    */
    Contacto listaContactos[MAX_CONTACTOS];

    // Inicializacion de variables
    int numContactos = 0;
    int opcion;

    // Menu con sentencia switch-case en un do-while
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Agregar contacto\n";
        std::cout << "2. Mostrar contactos\n";
        std::cout << "3. Buscar contacto\n";
        std::cout << "4. Salir\n";
        std::cout << "Ingrese su opcion: ";
        std::cin >> opcion;

        switch(opcion){
            case AGREGAR:
                agregarContacto(listaContactos, numContactos);
                break;
            case MOSTRAR:
                mostrarContactos(listaContactos, numContactos);
                break;
            case BUSCAR:
                buscarContacto(listaContactos, numContactos);
                break;
            case SALIR:
                std::cout << "Saliendo del programa...";
                break;
            default:
                std::cout << "Opcion invalida. Intente de nuevo.\n";
                break;
        }
    } while (opcion != SALIR); // Se rompe el do-while cuando se elige salir

    return 0;
}