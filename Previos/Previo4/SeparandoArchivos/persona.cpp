#include "persona.hpp"
using namespace std;

// Se definen los metodos y el contructor de la clase Persona

// Constructor
Persona::Persona(string nombre, int edad) {
    // Se usa el puntero _this_, que solo dice que es a esta clase
    this -> nombre = nombre;
    this -> edad = edad;
}

// Metodos
string Persona::getNombre(){
    return nombre;
}

int Persona::getEdad(){
    return edad;
}
void Persona::setEdad(int edad){
    this -> edad = edad;
}