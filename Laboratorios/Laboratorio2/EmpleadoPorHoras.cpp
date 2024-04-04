#include "EmpleadoPorHoras.hpp"

// Constructor, hereda datos de EMpleado y usa un privado (horasTrabajadas)
EmpleadoPorHoras::EmpleadoPorHoras(std::string _nombre, int _edad, double _salario, int _horasTrabajadas) :
        Empleado(_nombre, _edad, _salario), horasTrabajadas(_horasTrabajadas) {}
        
// Sobreescribir metodo virtual puro
double EmpleadoPorHoras::calcularPago() const {
    return salario * horasTrabajadas;
}