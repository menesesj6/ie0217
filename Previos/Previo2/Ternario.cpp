// Programa mas basico posible de C++
#include <iostream> // Importar libreria basica de input - output
int main(){
    std::cout << "Hola Mundo, estudiantes de IE0217! \n"; // Imprime string Hola mundo

    // Declaracion de variables
    int var1 = 0;
    int var2;

    var2 = (var1 == 3) ? 15 : 27; // Condicional con operador ternario

    std::cout << "var2: \n" << var2 << ""; // Imprimir resultado de la condicional

    return 0; // Retorno codigo de error
}