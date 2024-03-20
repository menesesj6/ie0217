// Segundo programa para ver punteros
#include <iostream>
using namespace std;

int main() {
    int var = 5; // Se inicializa una variable cualquiera
    int* pointVar; // Se inicializa una variable de tipo puntero integer
    pointVar = &var; // Se guarda la posicion de memoria de la primera variable creada

    cout << "Valor inicial de var es 5." << endl;
    cout << "var = " << var << endl; // Imprimir variable inicial
    cout << "*pointVar = " << *pointVar << endl; // Imprimir variable donde se guardo la direccion de var
    
    cout << "Cambiando valor de var a 7..." << endl; 
    var = 7; // Re asignacion de la variable var

    cout << "var = " << var << endl; // Imprimir variable inicial
    cout << "*pointVar = " << *pointVar << endl; // Imprimir variable donde se guardo la direccion de var

    cout << "Cambiando valor de *pointVar a 16..." << endl;
    *pointVar = 16;

    cout << "var = " << var << endl; // Imprimir variable inicial
    cout << "*pointVar = " << *pointVar << endl; // Imprimir variable donde se guardo la direccion de var

    return 0;
}