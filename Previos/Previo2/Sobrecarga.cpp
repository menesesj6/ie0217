// Programa para sobrecarga de funciones con valor absoluto

#include <iostream> // Importar libreria basica de input - output
using namespace std; // Definir namespace para cout y cin

// Funcion para floats
float absolute(float var){
    if (var < 0.0){
        var = -var;
    }
    return var;
}

// Funcion para integers
int absolute(int var){
    if (var < 0){
        var = -var;
    }
    return var;
}

int main(){

    // Imprimir resultados
    cout << "Valor absoluto de -5: " << absolute(-5) << endl;
    cout << "Valor absoluto de 5.5: " << absolute(5.5f) << endl;

    return 0;
}