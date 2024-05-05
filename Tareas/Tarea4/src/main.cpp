#include "Matrix.hpp"
#include "InputValidator.hpp"
int main(){
    int out, option, op, type, rand, _rows1, _cols1,  _rows2, _cols2;
    do{
        cout << "CALCULADORA DE MATRICES" << endl;
        cout << "-----------------------" << endl << endl;
        cout << "1. Creacion de las matrices" << endl;
        // Pedir tipo de datos
        cout << "1.1. Escoja el tipo de dato de las matrices." << endl;
        cout << "\t1. Integers" << endl;
        cout << "\t2. Floats" << endl;
        cout << "\t3. Complex" << endl;
        cout << "Seleccion: ";
        cin >> type;

        // Pedir dimensiones
        cout << "\n1.2. Escoja las dimensiones de la matriz 1." << endl;
        cout << "\tFilas: ";
        cin >> _rows1;
        cout << "\tColumnas: ";
        cin >> _cols1;
        
        cout << "1.3. Escoja las dimensiones de la matriz 2." << endl;
        cout << "\tFilas: ";
        cin >> _rows2;
        cout << "\tColumnas: ";
        cin >> _cols2;
        
        Matrix<int> m1(_rows1, _cols1);
        Matrix<int> m2(_rows2, _cols2);
    

        cout << "2. Escoja la operacion a realizar." << endl;
        cout << "\t1. +" << endl;
        cout << "\t2. -" << endl;
        cout << "\t3. *" << endl;
        cout << "Seleccion: ";
        cin >> op;

        do{
            cout << "\nMENU SECUNDARIO" << endl;
            cout << "---------------" << endl;
            cout << "Seleccione lo que desee hacer ahora." << endl << endl;
            cout << "\t1. Randomizar los valores de la matriz." << endl;
            cout << "\t2. Asignar valores manualmente." << endl;
            cout << "\t3. Mostrar las matrices generadas." << endl;
            cout << "\t4. Ejecutar la operacion deseada." << endl;
            cout << "\t5. Salir del programa" << endl;
            cout << "Seleccion: ";
            cin >> option;

            switch(option){
                case 1:
                    break;
                case 2: 
                    cout << "Ingrese valores de matriz 1: " << endl;
                    m1.fillMatrix();
                    cout << "Ingrese valores de matriz 2: " << endl;
                    m2.fillMatrix();
                    break;
                case 3:
                    cout << "Matriz 1: " << endl;
                    m1.display();
                    cout << "Matriz 2: " << endl;
                    m2.display();
                    break;
                case 4:
                    break;  
                case 5:
                    goto exit;
                    break;
                default:
                    cout << "Ingrese una opcion valida." << endl;
                    break;
            }
        } while(true);

    }while(true);

    exit:
    cout << "Saliendo del programa..." << endl;
    return 0;
}