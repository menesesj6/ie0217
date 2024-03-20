// Programa para usar recursividad
#include <iostream>
using namespace std;

int factorial(int); // Prototipo

int main() {
    // Inicializar variables
    int n, result;

    cout << "Ingrese un numero no negativo: ";
    cin >> n; // Se obtiene el numero

    result = factorial(n); // Invocar la funcion recursiva
    cout << "EL factorial de " << n << " es: " << result << endl;

    return 0;
}

int factorial(int n){
    // n * (n-1) * ... * 2 * 1
    if (n > 1){
        return n * factorial(n-1); // La funcion se llama a si misma
    } else {
        return 1; // Caso hasta el que llega que se va reemplazando
    }
}
