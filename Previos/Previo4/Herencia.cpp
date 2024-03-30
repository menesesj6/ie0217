#include <iostream>
using namespace std;

// CLase base
class Animal {
    public:
        void eat(){
            cout << "I can eat!" << endl;
        }

        void sleep(){
            cout << "I can sleep!" << endl;
        }
};

// Clase derivada por herencia. Dog va a tner todos los metodos de animal
class Dog : public Animal {
    public:
        void bark() {
            cout << "I can bark! Woof woof!" << endl;
        }
};

int main() {
    // Instanciar perro
    Dog dog1;

    // INvocar metodos heredados
    dog1.eat();
    dog1.sleep();

    // Invocar metodo propio
    dog1.bark();

    return 0;
}