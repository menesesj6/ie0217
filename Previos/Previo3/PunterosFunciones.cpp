// SPrograma para ver punteros con funciones
#include <iostream>
using namespace std;

// Funcion swap sin usar punteros
void swapSIN(int &n1, int &n2) {
    // Le llegan las referencias de las variables
    int temp; // Variable temporal

    // Reasignacion
    temp = n1;
    n1 = n2;
    n2 = temp;
}

// Funcion swap con punteros
void swapCON(int* n1, int* n2){
    // Le llegan las direcciones en memoria directamente (punteros)
    int temp; // Variable temporal
    
    // Reasignacion
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int main() {
    int a = 1, b = 2; // Inicializacion de variables

    // Imprimir variables iniciales
    cout << "Antes del swap: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    swapSIN(a, b); // Swap sin usar punteros

    // Imprimir variables swapeadas
    cout << "Despues del swap sin punteros: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    swapCON(&a, &b); // Swap con punteros

    // Imprimir variables swapeadas de nuevo
    cout << "Despues del swap con punteros: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}