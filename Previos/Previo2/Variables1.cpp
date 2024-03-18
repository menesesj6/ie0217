// Programa para ver variables y scope
#include <iostream> // Importar libreria basica de input - output
using namespace std; // Definir namespace para cout y cin

int g; // Variable global

void test() {
    static int var = 0; // Inicializar variable estatica
    ++var; // Cambiar el valor de la variable estatica
    cout << var << endl;
}

int main (){
    // Variables locales
    int a, b, c;

    // Asignar valores a variables locales
    a = 10;
    b = 20;

    // Uso de variables locales en otra variable local
    c = a + b;
    // Asignacion valor a variable global con locales
    g = a + b;

    // Imprimir resultados
    cout << c << endl;
    cout << g << endl;

    // Pruebas de la variable estatica
    test();
    test();

    return 0;
}   
