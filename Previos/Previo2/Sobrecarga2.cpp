// Programa para sobrecarga de funciones
#include <iostream> // Importar libreria basica de input - output
using namespace std; // Definir namespace para cout y cin

// Primera funcion
void display(int var1, double var2){
    cout << "Integer number: " << var1 << "\n";
    cout << "Double number: " << var2 << "\n";
}

// Segunda funcion
void display(double var){
    cout << "Double number: " << var<< "\n";
}

// Tercera funcion
void display(int var){
    cout << "Integer number: " << var << "\n";
}

int main(){

    // Declarar variables
    int a = 5;
    double b = 5.5;

    // Invocar funciones
    display(a);
    display(b);
    display(a, b);

    return 0;
}