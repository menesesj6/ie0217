#include <iostream>

int globalVariable = 42;

int main(){
    int stackVariable = 10;
    int* heapVariable = new int(20);

    std::cout << "Valor de globalVariable: " << globalVariable << std:: endl;
    std::cout << "Valor de stackVariable: " << stackVariable << std:: endl;
    std::cout << "Valor de heapVariable: " << heapVariable << std:: endl;

    delete heapVariable;

    return 0;
}