#include <iostream>
using namespace std;

int main(){
    // Inicializar variables y un array
    double numerator, denominator, arr[4] = {0.0, 0.0, 0.0, 0.0};
    int index;

    // Pedir al usuario un indice del array
    cout << "Enter array index: ";
    cin >> index;

    try{
        // Exception si esta fuera de rango
        if(index >= 4)
            throw "Error: Array out of bounds!";

        // Se ejecuta si el indice esta en el rango del array
        cout << "Enter numerator: ";
        cin >> numerator; 
        cout << "Enter denominator: ";
        cin >> denominator;

        // Excepcion por division entre cero
        if(denominator == 0)
            throw 0;

        // Se ejecuta si denominador != 0
        arr[index] = numerator / denominator; 
        cout << arr[index] << endl;
    }

    // Agarrar la excepcion de fuera de rango
    catch(const char* msg){
        cout << msg << endl;
    }

    // Agarrar la excepcion de denominador 0
    catch(int num){
        cout << "Error: Cannot divide by " << denominator << endl;
    }

    // Agarrar literal cualquier excepcion, usar operador ...
    catch(...){
        cout << "Unexpected exception!" << endl;
    }

    return 0;
}