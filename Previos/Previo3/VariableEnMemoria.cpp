// Programa para ver posiciones de variables en memoria
#include <iostream>
using namespace std;

int main() {
    // Inicializacion de variables
    int var1 = 3;
    int var2 = 24;
    int var3 = 17;

    // Impresion de ubicaciones en memoria usando el operador &
    // Las ubicaciones de memoria son hexadecimales 0x...
    cout << "Direccion de memoria de var1: " << &var1 << endl;
    cout << "Direccion de memoria de var2: " << &var2 << endl;
    cout << "Direccion de memoria de var3: " << &var3 << endl;
    
    return 0;
}