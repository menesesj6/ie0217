#include <iostream>
using namespace std;

int main() {
    int choice;
    int exit = 0;
    // Definir el menu principal
    do{
        cout << "\nBIENVENIDO A LA CALCULADORA DE MATRICES" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "1. Ingresar dimensiones y valores de matrices." << endl;
        cout << "2. Ingresar el tipo de datos de la matriz." << endl;
        
        cout << "3. Ingrese la operacion que desea hacer." << endl;
        
        cout << "4. Desea asignar valores aleatorios a alguna de las matrices?" << endl;
        
        cout << "5. Estas son las matrices ingresadas:" << endl;
        
        cout << "6. Desea ejecutar la operacion?" << endl;
        cout << "0. NO" << endl;
        cout << "1. SI" << endl;
        if(choice == 1){
            // Funcion de operacion
        }

        cout << "Desea salir ya?" << endl;
        cout << "Ingrese 0 para continuar y cualquier numero para salir." << endl;
        cin >> exit;

    }while(exit == 0);

    cout << "\nSaliendo del programa..." << endl;
    return 0;
}