// Programa de anidacion de sentencias

#include <iostream> // Importar libreria basica de input - output
using namespace std; // Definir namespace para cout y cin

int main (){
    int num; // Inicializar variable
    
    cout << "Ingrese un integer: ";
    cin >> num; // GUardar valor del usuario

    if (num!=0){ // IF externo
        if(num > 0){ // IF interno
            cout << "El numero es positivo" << endl;
        }
        else{ // ELSE del IF interno
            cout << "El numero es negativo" << endl;
        }
    } else{ // ELSE del IF externo
        cout << "El numero es 0, no es positivo ni negativo." << endl;
    }

    cout << "Esto siempre se imprime." << endl; // Print final fijo

    return 0;
}