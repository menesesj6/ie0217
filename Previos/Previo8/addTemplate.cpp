#include <iostream>
using namespace std;

// Crear molde de funcion de suma
// Se ve que los tipos de parametros no son dados, se indican en T 
template <typename T>
T add(T num1, T num2){
    // Retorno
    return num1 + num2;
}

int main(){
    // Inicializar variables
    int result1;
    double result2;

    // Llamar la funcion add para ints
    result1 = add<int>(2, 3);
    cout << result1 << endl;

    // Llamar la funcion add para doubles
    result2 = add<double>(2.2, 3.3);
    cout << result2 << endl;

    return 0;
}