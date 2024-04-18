#include "Funciones.hpp"

using namespace std;
using namespace std::chrono;

int main(){
    // Datos del array
    const int SIZE = 10000;
    int arr[SIZE];

    // Generar el array
    generateRandomArray(arr, SIZE);
    // Probar todos los algoritmos y obtener sus tiempos
    measuringSortingTime(bubbleSort, arr, SIZE, "Bubble Sort");

    // Desordenar el array y probar el Selection
    generateRandomArray(arr, SIZE);
    measuringSortingTime(selectionSort, arr, SIZE, "Selection Sort");

    // Desordenar el array y probar el Insertion
    generateRandomArray(arr, SIZE);
    measuringSortingTime(insertionSort, arr, SIZE, "Insertion Sort");

    // Desordenar el array y probar el Quick
    generateRandomArray(arr, SIZE);
    measuringQuickSortTime(quickSort, arr, 0, SIZE - 1, "Quick Sort");

    return 0;
}