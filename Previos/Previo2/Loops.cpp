// Programa de loops for, while, do-while

#include <iostream> // Importar libreria basica de input - output
using namespace std; // Definir namespace para cout y cin

int main (){
    // Loop for
    cout << "LOOP FOR:" << endl;
    for(int i = 1; i <= 5; ++i){ // Itera bajo una condicion
        cout << i << " ";
    }
    cout << "\n";

    // Loop for sobre un array
    cout << "LOOP FOR SOBRE UN ARRAY:" << endl;
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Inicializar array
    for (int n : array) { // Itera sobre el array
        cout << n << " ";
    }
    cout << "\n";

    // Loop while
    cout << "LOOP WHILE:" << endl;
    int i = 1;
    while (i <= 5){ // Funciona hasta que no se cumpla la condicion
        cout << i << " ";
        ++i;
    }
    cout << "\n";

    // Loop do-while
    cout << "LOOP DO-WHILE:" << endl;
    int m = 1;
    do {
        cout << m << " ";
        ++m;
    } while (m <= 5); // Hace la accion primero y despues revisa si se cumple la condicion
    return 0;
}