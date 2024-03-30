#include <iostream>
using namespace std;

class ClassB; // Prototipo de clase

class ClassA {
    public:
        // Constructor
        ClassA() : numA(12) {}
    private:
        int numA;
        friend int add(ClassA, ClassB); // Definir funcion amiga
};

class ClassB {
    public:
        // Constructor
        ClassB() : numB(1) {}
    private:
        int numB;
        friend int add(ClassA, ClassB); // Definir funcion amiga
};

// Definicion funcion amiga
int add(ClassA objectA, ClassB objectB){
    return (objectA.numA + objectB.numB);
}

int main() {
    // INstanciar clases
    ClassA objectA;
    ClassB objectB;

    // Usar funcion amiga
    cout << "Sum: " << add(objectA, objectB);
    return 0;
}