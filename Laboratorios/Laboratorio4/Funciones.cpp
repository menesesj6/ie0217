#include "Funciones.hpp"

using namespace std;
using namespace std::chrono;

void bubbleSort(int arr[], int n) {
    // Itera la lista completa
    for (int i = 0; i < n - 1; ++i) {
        // Otro iterador dejando por fuera los ya ordenados
        for (int j = 0; j < n - i - 1; ++j) {
            // Hacer un wap si el siguiente elemento es menor
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    // Itera la lista
    for (int i = 0; i < n - 1; ++i) {
        // Define el indice minimo de cada iteracion
        int min_index = i;
        // Itera la lista desde el indice minimo
        for (int j = i + 1; j < n; ++j) {
            // Si el j-esimo elemento tiene un numero menor que el del minimo indice, cambiar el minimo indice a j 
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        // Hacer un swap
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

void insertionSort(int arr[], int n) {
    // Se itera a partir del segundo elemento
    for (int i = 1; i < n; ++i) {
        // Se guarda el key
        int key = arr[i];
        // Se obtiene el valor anterior
        int j = i - 1;
        // Se compara el key con el valor anterior
        while (j >= 0 && arr[j] > key) {
            // Se mueve el j-esimo un elemento para el frente porque habra swap
            arr[j + 1] = arr[j];
            --j;
        }
        // Puede ser que haya o no un swap
        arr[j + 1] = key;
    }
}

int partition(int arr[], int low, int high) {
    // Se elige pivote el ultimo de la lista
    int pivot = arr[high];
    int i = low - 1;
    // Iterar la lista
    for (int j = low; j < high; ++j) {
        // Los menores al pivote, van a su izquierda
        if (arr[j] < pivot) {
            ++i;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Los mayores que el pivote, van a la derecha
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    // Retorna el punto de particion
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    // Para la recursividad, cuando low >= high, ya se tiene ordenado
    if (low < high) {
        // Volver a particionar
        int pi = partition(arr, low, high);
        // Usar recursividad para ordenar todas las pequenas particiones
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void generateRandomArray(int arr[], int n){
    // Crear la semilla
    srand(time(0));
    for( int i = 0; i < n; i++){
        // Definir valores del array randoms entre 0-9999
        arr[i] = rand() % 10000;
    }
}

void measuringSortingTime(void (*sortingAlgorithm)(int[], int), int arr[], int n, string algorithmName){
    // Iniciar un reloj
    high_resolution_clock::time_point start = high_resolution_clock::now();

    // Invocar la funcion pasada como parametro
    sortingAlgorithm(arr, n);

    // Parar el reloj
    high_resolution_clock::time_point stop = high_resolution_clock::now();

    // Obtener tiempo total
    std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds> (stop - start);

    /* Version alterna de linea anterior:
        auto duration = duration_cast<microseconds>(stop - start)
    */

   // Imprimir resultado
   cout << "Tiempo de " << algorithmName << ": " << duration.count() << " microsegundos." << endl;
}

void measuringQuickSortTime(void (*sortingAlgorithm)(int[], int, int), int arr[], int low, int high, string algorithmName){
    // Iniciar un reloj
    high_resolution_clock::time_point start = high_resolution_clock::now();

    // Invocar la funcion pasada como parametro
    sortingAlgorithm(arr, low, high);

    // Parar el reloj
    high_resolution_clock::time_point stop = high_resolution_clock::now();

    // Obtener tiempo total
    std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds> (stop - start);

    /* Version alterna de linea anterior:
        auto duration = duration_cast<microseconds>(stop - start)
    */

   // Imprimir resultado
   cout << "Tiempo de " << algorithmName << ": " << duration.count() << " microsegundos." << endl;
}