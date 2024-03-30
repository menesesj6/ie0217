#include <iostream>
using namespace std;

class ClassB; // Prototipo de clase

class ClassA {
    public:
        // Constructor
        ClassA() : numA(12) {}
    private:
        int numA; // Variable privada
        friend class ClassB; // ESpecificar clase amiga
};

class ClassB {
    public:
        // Constructor
        ClassB() : numB(1) {}

        // Metodo publico, amigo de ClassA
        int add(){
            ClassA objectA;
            return objectA.numA + numB;
        }
    private: 
        int numB; // Variable privada
};

int main() {
    // INstanciar clases
    ClassB objectB;

    // Usar funcion amiga
    cout << "Sum: " << objectB.add();
    return 0;
}