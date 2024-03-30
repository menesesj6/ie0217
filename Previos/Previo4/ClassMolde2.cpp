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

};

int main(){
    int variable_entera;
    // Instanciacion de la clase, pared es un objeto, se le pasan los parametros
    Molde pared(10.0, 20.0, 35.0);

    // Se accede a los atributos publicos
    cout << pared.largo << endl;

    // Se le cae encima al valor predeterminado
    pared.largo = 20;
    
    // IMprimir nuevo valor de largo
    cout << pared.largo << endl;
    pared.ancho = 13.2;
    pared.alto = 23.4;


    return 0;
}