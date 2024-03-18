// Segundo programa para switch case

#include <iostream> // Importar libreria basica de input - output
using namespace std; // Definir namespace para cout y cin

int main (){
    char oper; // Inicializar el operador
    float num1, num2; // Inicializar los numeros
    cout << "Indique el operador (+, -, *, /)";
    cin >> oper; 
    cout << "Ingrese dos numeros: " << endl;
    cin >> num1 >> num2; // Guardar los valores dados por el usuario

    // Sentencia switch dependiendo del operador ingresado
    switch (oper){
        case '+': // Caso suma
            cout << num1 << " + " << num2 << " = " << num1 + num2;
            break;
        case '-': // Caso resta
            cout << num1 << " - " << num2 << " = " << num1 - num2;
            break;
        case '*': // Caso multiplicacion
            cout << num1 << " * " << num2 << " = " << num1 * num2;
            break;
        case '/': // Caso division
            cout << num1 << " / " << num2 << " = " << num1 / num2;
            break;
    }

    return 0;
}