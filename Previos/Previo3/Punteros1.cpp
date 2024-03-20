// Programa para ver punteros
#include <iostream>
using namespace std;

int main() {
    int var = 5; // Se inicializa una variable cualquiera
    int* pointVar; // Se inicializa una variable de tipo puntero integer
    pointVar = &var; // Se guarda la posicion de memoria de la primera variable creada

    cout << "var = " << var << endl; // Imprimir variable inicial

    cout << "Direccion de var (&var): " << &var << endl; // Imprimir direccion de memoria de var usando &

    cout << "pointVar = " << pointVar << endl; // Imprimir variable donde se guardo la direccion de var
    
    cout << "Contenido de la direccion guardada en pointVar: " << *pointVar << endl; // Se imprime lo que haya en la direccion guardada, usando el caracter de de-referencia

    return 0;
}