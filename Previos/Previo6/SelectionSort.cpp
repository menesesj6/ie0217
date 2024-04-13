#include <iostream>
using namespace std;

// Swap
void swap( int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// IMprimir el array
void printArray(int array[], int size){
    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

// Definir el Selection Sort
void seleccionSort(int array[], int size){
    // Iterar por el array
    for(int step = 0; step < size - 1; step++){
        // Indice miimo inicial
        int min_idx = step;
        // Seguir iteradndo sin usar el actual
        for(int i = step + 1; i < size; i++){
            // Escoger el elemento menor en cada loop
            if(array[i] < array[min_idx])
                min_idx = i;
        }
        // Swap si es necesario, si no, quedara igual
        swap(&array[min_idx], &array[step]);
    }
}

int main(){
    // Definir array
    int data[] = {20, 12, 10, 15, 2};
    // Tmano del array
    int size = sizeof(data)/sizeof(data[0]);
    // Ordenar array
    seleccionSort(data, size);
    // IMprimir array ordenado
    cout << "Sorted array in Ascending order: \n";
    printArray(data, size);

    return 0;
}