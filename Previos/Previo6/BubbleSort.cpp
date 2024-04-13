#include <iostream>
using namespace std;

void bubbleSort(int array[], int size){
    // Acceder al array
    for(int step = 0; step < size; ++step){
        // Comparar el array
        for(int i = 0; i < size - step; ++i){
            // Ordenar orden ascendiente, cambiar > para descendiente
            if(array[i] > array[i + 1]){
                // FUncion swap 
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}

void printArray(int array[], int size){
    // Imprimir cada elemento del array
    for(int i = 0; i < size; ++i){
        cout << " " << array[i];
    }
    cout << "\n";
}

int main(){
    // Definir un array
    int data[] = {-2, 45, 0, 11, -9};

    // Definir tamano del array
    int size = sizeof(data)/sizeof(data[0]);

    // Ordenar array
    bubbleSort(data, size);

    // Imprimir array ordenado
    cout << "Sorted array in ascending orden: \n";
    printArray(data, size);

    return 0;
}