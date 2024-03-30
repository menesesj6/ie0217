#include <iostream>
using namespace std;

// Crear una clase basica
class Molde{
    public: // Access Specifier
        // Definir atributos publicos
        double largo;
        double ancho;
        double alto;

        /* Constructor, de forma mas elegante, es el equivalente a esto:

        Molde(double largo_p, double ancho_p, double alto_p){
            largo = largo_p;
            ancho = ancho_p;
            alto = alto_p;
        }

        */

        Molde(double largo_p, double ancho_p, double alto_p) : largo(largo_p), ancho(ancho_p), alto(alto_p) {}

        // Destructor, elimina el objeto cuando termine main (cuando ya no se necesite)
        ~Molde(){
            cout << "Saludos desde el destructor de la clase Molde" << endl;
        }

    // Definir metodos
    double calcularArea(){
        return largo * ancho;
    }
    double calcularVolumen(){
        return largo * ancho * alto;
    }
};

int main(){
    int variable_entera;
    // Instanciacion de la clase, pared es un objeto, se le pasan los parametros
    Molde pared(10.0, 20.0, 35.0);

    cout << "El area es: " << pared.calcularArea() << endl;
    cout << "El volumen es: " << pared.calcularVolumen() << endl;


    return 0;
}