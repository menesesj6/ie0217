#include "EmpleadoAsalariado.hpp"

// Constructor
EmpleadoAsalariado::EmpleadoAsalariado(std::string _nombre, int _edad, double _salario) :
        Empleado (_nombre, _edad, _salario) {}

// Sobreescribir el metodo virtual
double EmpleadoAsalariado::calcularPago() const {
    return salario;
}