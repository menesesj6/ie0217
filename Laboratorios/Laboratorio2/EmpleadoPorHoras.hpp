#ifndef EMPLEADOPORHORAS_HPP
#define EMPLEADOPORHORAS_HPP

#include "Empleado.hpp"

// NUeva clase por herencia publica
class EmpleadoPorHoras : public Empleado {
    private: // Accesible solo por esta clase o funciones amigas
        int horasTrabajadas;
    
    public:
        // Constructor
        EmpleadoPorHoras(std::string _nombre, int _edad, double _salario, int _horasTrabajadas);
        // Metodo sobreescribiendo el virtual puro
        double calcularPago() const override;

};

#endif //EMPLEADOPORHORAS_HPP