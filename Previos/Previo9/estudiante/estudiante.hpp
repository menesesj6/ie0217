#ifndef ESTUDIANTE_HPP
#define ESTUDIANTE_HPP

#include<string>

// Crear clase estudiante
class Estudiante{
    public:
        // Constructor parametrizado
        Estudiante(const std::string& nombre, int edad);
        // Metodo de ensenar datos
        void mostrarDatos();
    private:
        // Atributos
        std::string nombre;
        int edad;
        int edad2;
};

#endif