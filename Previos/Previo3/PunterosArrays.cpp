// Segundo programa para ver punteros con arrays
#include <iostream>
using namespace std;

int main() {
    float arr[3]; // Definir array de dimension 3

    float *ptr; // DEfinir un puntero de tipo float

    // Usar array para iterar e ir obteniendo las direcciones de memoria
    cout << "Ensenando direcciones con arrays: " << endl;

    for (int i = 0; i < 3; ++i) {
        cout << "&arr[" << i << "] = " << &arr[i] << endl; // Iteracion sobre los elementos del array
    }

    ptr = arr; // Se asigna la primera direccion de memoria del array (&arr[0]) a ptr 

    // Ahora, usando punteros directamente
    cout << "\nEnsenando direcciones usando punteros: " << endl;

    for (int i = 0; i < 3; ++i) {
        cout << "ptr + " << i << " = " << ptr + i << endl; // Se usa aritmetica de punteros
    }

    return 0;
}