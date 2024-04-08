#include <iostream>
using namespace std;

int main() {
    // Definir punteros
    int* pointInt;
    float* pointFloat;

    // Obtener espacios de memoria donde se guardara
    pointInt = new int;
    pointFloat = new float;

    // ASignar valor al puntero usando de-referencia
    *pointInt = 45;
    *pointFloat = 45.45f;

    // IMprimir
    cout << *pointInt << endl;
    cout << *pointFloat << endl;

    // Liberar memoria
    delete pointInt;
    delete pointFloat;

    return 0;
}