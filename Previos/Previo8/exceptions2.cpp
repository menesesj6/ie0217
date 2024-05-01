#include<iostream>
#include<stdexcept>

using namespace std;

int main(){
    // Inicializar variables
    int numerador, denominador, resultado;

    // Pedir datos al usuario
    cout << "Ingrese el numerador: ";
    cin >> numerador;

    cout << "Ingrese el denominador: ";
    cin >> denominador;

    try{
        // Caso de division por cero
        if(denominador == 0)
            // TIrar una excepcion de las 'estandar' de C++
            throw runtime_error("Error: El denominador no puede ser cero.");
        
        // Se ejecuta si denominador != 0
        resultado = numerador / denominador;
        cout << "El resultado es: " << resultado << endl;
    }

    // Agarra la excepcion runtime_error, esta nomenclatura es justamente para eso, obtener la direccion de una excepcion
    catch(const exception& e){
        // IMprimir el error indicador por la excepcion
        cerr << e.what() << endl;
    }

    return 0;
}