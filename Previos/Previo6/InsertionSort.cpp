#include <iostream>
using namespace std;

void printArray(int array[], int size){
    // Imrpimir array
    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

void insertionSort(int array[], int size){
    // Iterar el array
    for(int step = 1; step < size; step++){
        // Key funciona como una variable temp
        int key = array[step];
        // Elemento anterior
        int j = step - 1;

        // Hace el switch siempre que detecte que key sea mayor al elemento actual del array 
        while(key < array[j] && j >= 0){
            array[j + 1] = array[j];
            --j;
        }
        // Se asigna key para no perderlo
        array[j + 1] = key;
    }
}

int main(){
    // Definir array
    int data[] = {9, 5, 1 , 4, 3};
    // Tmano del array
    int size = sizeof(data)/sizeof(data[0]);
    // Ordenar array
    insertionSort(data, size);
    // IMprimir array ordenado
    cout << "Sorted array in Ascending order: \n";
    printArray(data, size);

    return 0;
}