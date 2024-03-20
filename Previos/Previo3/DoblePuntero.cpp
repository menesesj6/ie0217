// Programa para ver punteros dobles
#include <iostream>
using namespace std;

int main() {
    int var = 2050; // Inicializar variable de numero entero
    int* ptr_var; // Inicializar puntero simple

    ptr_var = &var; // Direccion de var 

    cout << "var: " << var << ", ptr_var: " << ptr_var << endl;

    int** ptr_ptr_var; // Inicializar doble puntero

    ptr_ptr_var = &ptr_var; // Direccion de la direccion de var

    cout << "ptr_ptr_var: " << ptr_ptr_var << endl;
    cout << "&ptr_var: " << &ptr_var << endl;

    return 0;
}