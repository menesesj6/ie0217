#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    // malloc: Reservar espacio en el heap. Devuelve un void*, pero se castea con (int*)
    int* ptr = (int*) malloc(sizeof(int));

    // Asignar valor en la memoria asignada
    *ptr = 5;

    // Imprimir
    cout << *ptr;

    return 0;
}