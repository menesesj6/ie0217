#include <iostream>
using namespace std;

int main(){
    // INicializar variables necesarias
    double numerator, denominator, divide;

    // Pedir datos al usuario
    cout << "Enter numerator: ";
    cin >> numerator;

    cout << "Enter denominator: ";
    cin >> denominator;

    // INtentar
    try{
        // Caso de division entre cero
        if(denominator == 0){
            // Este cero es el argumento
            throw 0; // Del throw se brinca al bloque catch
        }

        // Pasa solo si denominator != 0, se ejecuta la division normal
        divide = numerator / denominator;
        cout << numerator << "/" << denominator << " = " << divide << endl;
    }

    // Manejo de excepcion, se ejecuta solo cuando se activa el throw
    // num_exception es el 0 que mando throw
    catch (int num_exception){
        cout << "Error: Cannot divide by " << num_exception << endl;
    }

    return 0;
}