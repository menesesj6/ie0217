#include "Matrix.hpp"
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

        if(type == 1){
            Matrix<int> m1(_rows1, _cols1);
            Matrix<int> m2(_rows2, _cols2);
        } else if (type == 2){
            Matrix<float> m1(_rows1, _cols2);
            Matrix<float> m2(_rows2, _rows2);
        }

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
            cout << "\t2. Mostrar las matrices generadas." << endl;
            cout << "\t3. Ejecutar la operacion deseada." << endl;
            cout << "\t4. Salir del programa" << endl;
            cout << "Seleccion: ";
            cin >> option;
            switch(option){
                case 1:

                case 2:

                case 3:

                case 4:
                    goto exit;
                default:
                    cout << "Ingrese una opcion valida." << endl;
            }
        } while(true);
    }while(true);

    exit:
    cout << "Saliendo del programa..." << endl;
    return 0;
}