#include <iostream>
using namespace std;

int main(){
    int* pointVar; // Entero puntero
    // El new da un espacio en memoria en el heap para guardar algo, por eso se usa un puntero para eso
    pointVar = new int; //
    *pointVar = 45; // Asignar valor
    cout << *pointVar;
    delete pointVar; // LImpiar memoria
}