#include <iostream>
using namespace std;

class Distance {
    private:
        // INicializar variable privada
        int meter;

        // Definir funcion amiga, puede acceder a meter desde fuera
        friend int addFive(Distance);
    public:
        // Constructor
        Distance() : meter(0) {}
};

// Definir funcion amiga
int addFive(Distance d) {
    d.meter += 5;
    return d.meter;
}

int main() {
    // Instanciar clase
    Distance D;

    // Imprimir resultados
    cout << "Distance: " << addFive(D);

    return 0;
}