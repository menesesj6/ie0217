#include <iostream>
using namespace std;

// Funcion de intercambio de elementos
void swap(int *a, int *b) {
  int t = *a; // Variable temporal
  *a = *b;
  *b = t;
}

// Imprimir array
void printArray(int array[], int size) {
  int i;
  // Iterar e imprimir
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

// Funcion de acomodar array y encontrar el punto de particion
int partition(int array[], int low, int high) {
    
  // Elegir el elemento de mas a la derecha como pivote
  int pivot = array[high];
  
  // Apuntar al elemento mas grande adyacente
  int i = (low - 1);

  // Atravesar el array y compararlo con el pivote
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
        // SI hay un elemento mas pequeno que el pivote, hacer swap con el elemento 
        // mas grande adyacente
        i++;
        swap(&array[i], &array[j]);
    }
  }
  
  // INtercambiar pivote con el elemento mas grande adyacente en i
  swap(&array[i + 1], &array[high]);
  
  // Volver al punto de partida
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
      
    // Encontrar pivote con los mas pequenos a la izquierda y los mas grandes a la derecha
    int pi = partition(array, low, high);

    // Recursividad a la izquierda del pivote
    quickSort(array, low, pi - 1);

    // Recursividad a la izquierda del pivote
    quickSort(array, pi + 1, high);
  }
}

// FUncion principal
int main() {
    // Array a acomodar
    int data[] = {8, 7, 6, 1, 0, 9, 2};
    // Tamano del array
    int n = sizeof(data) / sizeof(data[0]);
    
    // Ejecutar el algoritmo e imprimir resultados
    cout << "Unsorted Array: \n";
    printArray(data, n);
    
    quickSort(data, 0, n - 1);
    
    cout << "Sorted array in ascending order: \n";
    printArray(data, n);
}