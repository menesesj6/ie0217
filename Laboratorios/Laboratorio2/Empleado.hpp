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
        // Destructor, no hace nada en este caso
        virtual ~Empleado(){}
        //Metodos

        // Metodo virtual puro: se tiene que sobreescribir si o si, o da error de compilacion
        virtual double calcularPago() const = 0;
        // NO es metodo virtual puro, "const" porque no afecta atributos 
        virtual void mostrarDetalles() const; 
};

#endif //EMPLEADO_HPP