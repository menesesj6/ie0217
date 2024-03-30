#include <iostream>
using namespace std;

// CLase base
class Base {
   public:
    void print() {
        cout << "Base Function" << endl;
    }
};

// Clase derivada por herencia.
class Derived : public Base {
   public:
   // SObreescribir la funcion print que ya fue heredada
    void print() {
        cout << "Derived Function" << endl;
    }
};

int main() {
    // Instanciar dos veces la clase Derived
    Derived derived1, derived2;
    
    // Invocar metodo de Derived
    derived1.print(); // Usa la de Derived porque fue el ultimo metodo sobreescrito con ese nombre

    // Invocar el metodo pero de la clase base, usar esa sintaxis para acceder a los metodos de alto en la herencia
    derived2.Base::print();

    return 0;
}