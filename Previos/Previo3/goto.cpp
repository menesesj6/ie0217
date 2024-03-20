// Programa para usar el goto
#include <iostream>
using namespace std;

int main() {
    // Se inicializan variables
    float num, average, sum = 0.0;
    int i, n;

    // Se almacena la cantidad de inputs requeridos
    cout << "Ingrese la mayor cantidad de inputs: ";
    cin >> n;

    // Se piden los datos
    for (i = 1; i <= n; ++i){
        cout << "Ingrese n" << i << ": ";
        cin >> num;

        if (num < 0){
            goto jump; // Si se ingresa negativo, se salta al jump
        } 
        sum += num;
    }
    // Seccion donde se salta si se ingresa num negativo
    jump:
        average = sum / (i-1);
        cout << "\n Promedio = " << average; // Imprime resultado

    return 0;
}