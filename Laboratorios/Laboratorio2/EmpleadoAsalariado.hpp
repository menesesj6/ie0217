#ifndef EMPLEADOASALARIADO_HPP
#define EMPLEADOASALARIADO_HPP

#include "Empleado.hpp"

// CLase con herencia de Empleado
class EmpleadoAsalariado: public Empleado {
    public: // Accesible por quien sea
        EmpleadoAsalariado(std::string _nombre, int edad, double _salario);
        double calcularPago() const override; // Sobreescribir metood virtual
};


#endif //EMPLEADOASALARIADO_HPP