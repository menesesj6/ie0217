#include <iostream>
#include <stack>

using namespace std;

int main(){
    // Crear un stack
    stack<int> numbers;

    // Push
    numbers.push(1);
    numbers.push(100);
    numbers.push(10);

    // Imprimir resultados
    cout << "Numbers are: ";

    // Ir vaciando el stack e imprimiendo hasta que este vacio
    while(!numbers.empty()){
        // IMprimir el de arriba
        cout << numbers.top() << ", ";
        
        // Quitar el de arriba
        numbers.pop();
    }
}