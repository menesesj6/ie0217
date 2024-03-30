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
            cout << "Esto se ejecuta en cada instanciacion." << endl;
            cout << "Iniciando un objeto de la clase Molde." << endl;
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
    // Instanciacion de la clase, pared es un objeto
    Molde pared;
    
    // Se accede a los atributos publicos
    pared.largo = 400.5;
    pared.ancho = 20.8;
    pared.alto = 315.2;

    cout << "Area = " << pared.calcularArea() << endl;
    cout << "Volumen = " << pared.calcularVolumen() << endl;

    return 0;
}