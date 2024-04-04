#include  "Empleado.hpp"
#include <iostream>

// Constructor, asignar atributos por parametros
Empleado::Empleado(std::string _nombre, int _edad, double _salario):
    nombre(_nombre), edad(_edad), salario(_salario) {}

// Definir metodo virtual de impresion
void Empleado::mostrarDetalles() const{
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Edad: " << edad << std::endl;
    std::cout << "Salario: " << salario << std::endl;
}