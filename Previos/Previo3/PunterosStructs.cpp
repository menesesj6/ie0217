// Programa para ver punteros y structs
#include <iostream>
using namespace std;

// Crear un struct de prueba
struct Distance{
    int feet;
    float inch;
};

int main() {
    Distance *ptr, d; // Se instancia el struct

    ptr = &d; // Almacenar la posicion de memoria de d
    
    // Usando de-referencia
    cout << "Ingrese los pies: " << endl;
    cin >> (*ptr).feet; // Asignar los atributos de la instanciacion
    cout << "Ingrese las pulgadas: " << endl;
    cin >> (*ptr).inch;

    // EL . tiene precedencia mayor al operador *, entonces los parentesis son esenciales

    cout << "Mostrando datos usando (*ptr): " << endl;
    cout << "Distancia = " << (*ptr).feet << " pies " << (*ptr).inch << " pulgadas" << endl;

    // Usando operador flechita
    cout << "Ingrese los pies: " << endl;
    cin >> ptr -> feet; // Asignar los atributos de la instanciacion
    cout << "Ingrese las pulgadas: " << endl;
    cin >> ptr -> inch; // Menos posibilidad de error al no usar (*ptr)

    cout << "Mostrando datos usando ->: " << endl;
    cout << "Distancia = " << ptr->feet << " pies " << ptr->inch << " pulgadas" << endl;

    return 0;
}