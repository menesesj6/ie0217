#ifndef PERSONA_H
#define PERSONA_H

#include <string>
using namespace std;

// Crear clase
class Persona {
    // Atributos privados
    private:
        string nombre;
        int edad;
    // Atributos y prototipos de funciones publicos
    public:
        Persona(string nombre, int edad);
        string getNombre();
        int getEdad();
        void setEdad(int edad);
};

#endif //PERSONA_H