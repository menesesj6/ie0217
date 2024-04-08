#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    float *ptr, *new_ptr; // Crear punteros a usar

    // ASignar un espacio de heap para tipo float
    ptr = (float*) malloc(5 * sizeof(float));

    // Caso que el puntero sea NULL
    if(ptr == NULL){
        cout << "Memory Allocation Failed";
        exit(1);
    }

    // Inicializar valores
    for(int i = 0; i < 5; i++){
        ptr[i] = i * 1.5;
    }

    // realloc: cambia el bloque de memoria asignado; puede redimensionarlo o cambiarlo. Devuelve un puntero al nuevo espacio de memoria
    new_ptr = (float*) realloc(ptr, 10 * sizeof(float));
    
    // Caso fallido
    if(new_ptr == NULL){
        cout << "Memory re-allocation Failed";
        exit(1);
    }

    for( int i = 0; i < 10; i++){
        new_ptr[i] = i * 2.5;
    }

    cout << "Printing values " << endl;

    for(int i = 0; i < 10; i++){
        cout << new_ptr[i] << endl;
    }

    // Liberar la memoria abarcada
    free(new_ptr);

    return 0;
}