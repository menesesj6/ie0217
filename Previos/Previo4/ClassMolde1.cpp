#include <iostream>
using namespace std;

// Crear una clase basica
class Molde{
    public: // Access Specifier
        // Definir atributos publicos
        double largo;
        double ancho;
        double alto;

        Molde(){ // Constructor del objeto
            cout << "Instanciando Molde." << endl;
            largo = 15;
            ancho = 12;
            alto = 21;
        }

};

int main(){
    int variable_entera;

    // Instanciacion de la clase, pared es un objeto
    Molde pared;

    // Se accede a los atributos publicos
    cout << pared.largo << endl;

    // Se le cae encima al valor predeterminado
    pared.largo = 20;

    // Imprimir nuevo valor de largo
    cout << pared.largo << endl;
    pared.ancho = 13.2;
    pared.alto = 23.4;


    return 0;
}