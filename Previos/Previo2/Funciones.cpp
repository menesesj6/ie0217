// Programa de funciones: Return, argumentos y prototipos

#include <iostream> // Importar libreria basica de input - output
using namespace std; // Definir namespace para cout y cin

int add(int, int); // Prototipo funcion add

void displayNum(int n1, float n2){
    cout << "El numero int es " << n1;
    cout << "El numero double es " << n2; // Hacer los displays
}

int main (){
    int sum; // Inicializar variable de suma

    sum = add(100, 78); // Invocar funcion para obtener su return
    cout << "100 + 78 = " << sum << endl; // Imprimir resultado
}

int add( int a, int b){ // Se define despues del main, por eso el prototipo
    return a + b;
}