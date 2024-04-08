#include <iostream>

// Variable global, se guarda en Data
int globalVariable = 42;

int main(){
    int stackVariable = 10; // Va en el stack
    int* heapVariable = new int(20); // Va en el heap

    std::cout << "Valor de globalVariable: " << globalVariable << std:: endl;
    std::cout << "Valor de stackVariable: " << stackVariable << std:: endl;
    std::cout << "Valor de heapVariable: " << heapVariable << std:: endl;

    delete heapVariable; // LImpiar memoria

    return 0;
}