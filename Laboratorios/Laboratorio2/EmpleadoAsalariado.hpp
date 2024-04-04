#ifndef EMPLEADOASALARIADO_HPP
#define EMPLEADOASALARIADO_HPP

#include "Empleado.hpp"

class EmpleadoAsalariado: public Empleado {
    public:
        EmpleadoAsalariado(std::string _nombre, int edad, double _salario);
        double calcularPago() const override; // SObreescribir metood virtual
};


#endif //EMPLEADOASALARIADO_HPP