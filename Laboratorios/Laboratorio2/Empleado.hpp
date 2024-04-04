#ifndef EMPLEADO_HPP
#define EMPLEADO_HPP

#include <string>

// Crear clase
class Empleado{
    protected: // Accesibles por esta clase y derivadas
        std::string nombre;
        int edad;
        double salario;
    
    public: // Accesibles por cualquiera
        // Constructor
        Empleado(std::string _string, int _edad, double _salario);
        // DEstructor
        virtual ~Empleado(){}
        //Metodos
        virtual double calcularPago() const = 0; // Metodo virtual puro, se tiene que sobreescribir si o si
        virtual void mostrarDetalles() const; // NO es metodo virtual puro
};

#endif //EMPLEADO_HPP