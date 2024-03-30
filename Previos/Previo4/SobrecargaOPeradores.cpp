#include <iostream>
using namespace std;

class Fraccion {
    // Inicializar variables
    int numerador, denominador;

    public:
        // Constructor
        Fraccion(int n, int d) : numerador(n), denominador(d){}

        // Aca se deine el operador que se va a sobrecargar, en este caso el +
        Fraccion operator+ (const Fraccion &f){
            // Es una instanciacion, con parametros definidos por una operacion
            Fraccion resultado( 
                numerador * f.denominador + f.numerador * denominador, denominador * f.denominador
            );
            return resultado;
        }

        // Definir metodo de impresion
        void imprimir() {
            cout << numerador << "/" << denominador << endl;
        }
};

int main() {
    // Se instancian dos fracciones
    Fraccion f1(1, 2);
    Fraccion f2(3, 4);

    // Se instancia una tercera fraccion usando la sobrecarga del +
    Fraccion f3 = f1 + f2;

    // Se invoca un metodo de f3, el de imprimirla
    f3.imprimir();

    return 0; 
}