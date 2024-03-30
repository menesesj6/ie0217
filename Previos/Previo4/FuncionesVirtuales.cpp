#include <iostream>
using namespace std;

// Clase base
class Base {
    public:
        // Metodo virtual, debe ser reescrito en derivadas
        virtual void print() {
            cout << "Base Function" << endl;
        }
};

// Clase derivada
class Derived : public Base {
    public:
        void print() {
            cout << "Derived Function" << endl;
        }
};

int main() {
    // Instanciar clase derivada
    Derived derived1;

    // Clase puntero, guarda la posicion de memoria del objeto de clase derivada
    Base* base1 = &derived1;
    
    // Acceder a metodo
    base1 -> print();
}