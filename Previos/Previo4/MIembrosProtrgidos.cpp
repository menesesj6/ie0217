#include <iostream>
using namespace std;

// Clase base Animal
class Animal{
    private:
        string color; // NO accesible desde Dog
    protected:
        string type; // Accesible desde Dog
    public:
        void run() {cout << "I can run -- BASE!" << endl;}
        void eat() {cout << "I can eat!" << endl;}
        void sleep() {cout << "I can sleep!" << endl;}
        void setColor(string clr) {color = clr;}
        string getColor() {return color;} // Puede acceder a color, pues es la misma clase
};

// Definir clase perro por herencia de Animal. Perro es derivada de Animal
class Dog : public Animal{
    public:
        void run() {cout << "I can run -- DERIVED!" << endl;} // Sobreescribe el metodo de la herencia
        void setType(string tp) { type = tp;} // Derivada de Animal, tiene acceso a lo protegido
        void displayInfo(string c) {
            cout << "I am a " << type << endl;
            cout << "My color is " << c << endl;
        }
        void bark() {cout << "I can bark! Woof woof" << endl;}
};

int main() {
    // Instanciar la clase Dog
    Dog dog1;

    // Invocar todos los metodos
    dog1.run();
    dog1.eat();
    dog1.sleep();
    dog1.setColor("black");
    dog1.bark();
    dog1.setType("Doberman");
    dog1.displayInfo(dog1.getColor());

    return 0;
}