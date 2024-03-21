// Se incluye el header de las firmas de las funciones necesarias
#include "Funciones.hpp"

void agregarContacto(Contacto listaContactos[], int &numContactos){
    // Instanciacion del struct
    Contacto nuevoContacto;
    // Se piden datos, asumimos que el usuario va a meter los datos bien (happy path)
    std::cout << "Ingrese el nombre del contacto: ";
    std::cin >> nuevoContacto.nombre;
    std::cout << "\nIngrese el numero de telefono: ";
    std::cin >> nuevoContacto.telefono;

    listaContactos[numContactos++] = nuevoContacto; // Metiendo el nuevo contacto a la lista y se actualiza numContactos
};

void mostrarContactos(const Contacto listaContactos[], int numContactos){
    std::cout << "Lista de contactos: \n";
    // Iterar la lista de contactos entera e imprimir datos
    for (int i = 0; i < numContactos; ++i){
        std::cout << "Nombre: " << listaContactos[i].nombre << ", Telefono: " << listaContactos[i].telefono << "\n";
    }
}

void buscarContacto(const Contacto listaContactos[], int numContactos){
    std::string nombreBusqueda; // Definicion del contacto que se busca
    std::cout << "Ingrese el nombre a buscar: ";
    std::cin >> nombreBusqueda; // Usuario dice a quien busca
    // COndicion inicial: no encontrado
    bool encontrado = false; // bool -> si o no
    // Itera la lista de contactos buscando el deseado
    for (int i = 0; i < numContactos; i++){
        if (listaContactos[i].nombre == nombreBusqueda){
            // Condicional de si ya encontro el que es igual
            std::cout << "Nombre: " << listaContactos[i].nombre << ", Telefono: " << listaContactos[i].telefono << "\n";
            encontrado = true; // Encontrado
            break; // Salir del for
        }
    }
    if (!encontrado){
        // Caso en que encontrado se mantiene false
        std::cout << "Contacto no encontrado.\n";
    }
}