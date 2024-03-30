#include <iostream>
#include "persona.hpp"
using namespace std;

int main(){
    // Se instancia el objeto con los parametros
    Persona p("Juan", 25);

    cout << "Nombre: " << p.getNombre() << endl;
    cout << "Edad: " << p.getEdad() << endl;

    // Se usa un metodo
    p.setEdad(26);

    cout << "Nueva edad: " << p.getEdad() << endl;

    return 0;
}