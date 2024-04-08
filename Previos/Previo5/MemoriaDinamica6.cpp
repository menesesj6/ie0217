#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    int *ptr; // Se define el puntero a usar
    // calloc: Reserva espacio en el heap, inicializado en 0. Devuelve void* pero se castea con (int*)
    // calloc es mas lento computacionalmente que malloc por inicializar en cero
    ptr = (int*) calloc(5, sizeof(int));
    // Revisar si el puntero es NULL
    if (!ptr){
        cout << "Memory Allocation Failed";
        exit(1);
    }

    // Inicializar valores
    cout << "Initializing values..." << endl << endl;

    for( int i = 0; i < 5; i++) {
        // ptr[i] es lo mismo a *(ptr + i)
        ptr[i] = i * 2 + 1;
    }

    cout << "Initialized values" << endl;
    for(int i = 0; i < 5; i++){
        cout << *(ptr + i) << endl;
    }

    // Liberar memoria con malloc, calloc o realloc
    free(ptr);

    return 0;
}