#include <iostream>
using namespace std;

// Clases de herencia multinivel

// Clase base A
class A {
    public:
        void display(){
            cout << "Base class content." << endl;
        }
};

// B hereda de A
class B : public A {};

// C hereda de B
class C : public B {};


//Clases de herencia multiple
class Mammal{
    public:
        Mammal(){
            cout << "Mammals can give direct birth." << endl;
        }
};

class WingedAnimal{
    public:
        WingedAnimal(){
            cout << "WInged animal can flap." << endl;
        }
};

// Bat hereda de dos, Mammal y WingedAnimal
class Bat : public Mammal, public WingedAnimal {};

// Clases de herencia jerarquica
class Animal {
    public:
        void info() {cout << " I am an animal." << endl;}
};

// DOg hereda de Animal
class Dog : public Animal {
    public:
        void bark() {cout << " I am an a dog. Woof woof." << endl;}
};

// Cat tambien hereda de Animal
class Cat : public Animal {
    public:
        void meow() {cout << " I am an a cat. Meow." << endl;}
};

int main() {
    // Herencia multinivel
    C obj;
    obj.display();

    // Herencia multiple
    Bat b1;

    // Herencia jerarquica
    Dog dog1;
    cout << "Dog Class: " << endl;
    dog1.info();
    dog1.bark();

    Cat cat1;
    cout << "Cat Class: " << endl;
    cat1.info();
    cat1.meow();


    return 0;
}
