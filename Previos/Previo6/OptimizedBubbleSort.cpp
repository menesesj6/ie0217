#include <iostream>
using namespace std;

void bubbleSort(int array[], int size){
    // Acceder a todo el array
    for(int step = 0; step < (size - 1); ++step){
        // Revisar si hay swap
        int swapped = 0;
        // COmparar elementos
        for(int i = 0; i < size - step - 1; ++i){
            if(array[i] > array[i + 1]){
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                // Hubo swap
                swapped = 1;
            }
        }

        // NO hay swap, array ya esta listo
        if(swapped == 0){
            break;
        }
    }
}

void printArray(int array[], int size){
    // IMprimir array
    for(int i = 0; i < size; ++i){
        cout << " " << array[i];
    }
    cout << "\n";
}

int main(){
    int data[] = {-2, 45, 0, 11, -9};

    // Obtener el tamano del array
    int size = sizeof(data)/sizeof(data[0]);

    // Invocar bubbleSort
    bubbleSort(data, size);

    cout << "Sorted array in ascending orden: \n";
    printArray(data, size);

    return 0;
}