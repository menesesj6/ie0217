/**
 * @file main.cpp
 * @author Jorge Meneses (j.menesesgarro@gmail.com)
 * @brief Implementacion principal del programa
 * @version 1.0
 * @date 2024-05-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "InputValidator.hpp"
#include "BasicOperations.hpp"


int main(){
    // Inicializar variables importantes del menu
    int option, op, type;
    // Inicializar variables de dimensiones
    int _rows1, _cols1,  _rows2, _cols2;
    // Instanciar los objetos encargados de las operaciones
    BasicOperations<int> intOp;
    BasicOperations<float> floatOp;
    BasicOperations<complex<float>> complexOP;
    do{
        cout << "CALCULADORA DE MATRICES" << endl;
        cout << "-----------------------" << endl << endl;
        cout << "1. Creacion de las matrices" << endl;
        
        do{
             // Pedir tipo de datos
            cout << "1.1. Escoja el tipo de dato de las matrices." << endl;
            cout << "\t1. Integers" << endl;
            cout << "\t2. Floats" << endl;
            cout << "\t3. Complex" << endl;
            cout << "Seleccion: ";
            cin >> type;
            switch (type){
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                default:
                    cout << "Seleccione un tipo valido." << endl;
                    break;
            }
        }while(type != 1 && type != 2 && type != 3);
       

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

        do{
            // Preguntar la operacion a realizar
            cout << "2. Escoja la operacion a realizar." << endl;
            cout << "\t1. +" << endl;
            cout << "\t2. -" << endl;
            cout << "\t3. *" << endl;
            cout << "Seleccion: ";
            cin >> op;
            switch (op){
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                default:
                    cout << "Seleccione una operacion valida." << endl;
                    break;
            }
        }while(op != 1 && op != 2 && op != 3);
        
        
        // Caso de integers
        if(type == 1){
            // Crear objetos matriz tipo int
            Matrix<int> m1(_rows1, _cols1);
            Matrix<int> m2(_rows2, _cols2);
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
                        // Randomizar valores e imprimir matrices
                        cout << "Rellenando la matriz 1..." << endl;
                        m1.randomFillMatrix();
                        cout << "\nMATRIZ 1" << endl;
                        cout << "--------" << endl;
                        m1.display();
                        cout << "Rellenando la matriz 2..." << endl;
                        m2.randomFillMatrix();
                        cout << "\nMATRIZ 2" << endl;
                        cout << "--------" << endl;
                        m2.display();
                        break;
                    case 2: 
                        // Ingresar valores manualmente e imprimir matrices
                        cout << "Ingrese valores de matriz 1: " << endl;
                        m1.fillMatrix();
                        cout << "\nMATRIZ 1" << endl;
                        cout << "--------" << endl;
                        m1.display();
                        cout << "Ingrese valores de matriz 2: " << endl;
                        m2.fillMatrix();
                        cout << "\nMATRIZ 2" << endl;
                        cout << "--------" << endl;
                        m2.display();
                        break;
                    case 3:
                        // Imprimir matrices
                        cout << "\nMATRIZ 1" << endl;
                        cout << "--------" << endl;
                        m1.display();
                        cout << "\nMATRIZ 2" << endl;
                        cout << "--------" << endl;
                        m2.display();
                        break;
                    case 4:
                        // Sentencia condicional para realizar operaciones
                        if (op == 1){
                            // Suma
                            try{
                                cout << "\nRESULTADO" << endl;
                                cout << "--------" << endl; 
                                // Validar y realizar la operacion
                                intOp.sum(m1, m2).display();
                            }
                            // Manejar excepcion en caso de operacion invalida, si hiciera falta
                            catch(const exception& e){
                                cerr << e.what() << endl;
                            }
                        } else if(op == 2){
                            // Resta
                            try{
                                cout << "\nRESULTADO" << endl;
                                cout << "--------" << endl; 
                                // Validar y realizar la operacion
                                intOp.sub(m1, m2);
                            }
                            // Manejar excepcion en caso de operacion invalida, si hiciera falta
                            catch(const exception& e){
                                cerr << e.what() << endl;
                            }
                        } else if(op == 3){
                            // Multiplicacion
                            try{
                                cout << "\nRESULTADO" << endl;
                                cout << "--------" << endl; 
                                // Validar y realizar la operacion
                                intOp.mult(m1, m2).display();
                            }
                            // Manejar excepcion en caso de operacion invalida, si hiciera falta
                            catch(const exception& e){
                                cerr << e.what() << endl;
                            }
                        }
                        break;  
                    case 5:
                        // Salir del programa
                        goto exit;
                        break;
                    default:
                        // Volver a pedir opcion
                        cout << "Ingrese una opcion valida." << endl;
                        break;
                }
            } while(true);
        } 
        // Caso de floats
        else if (type == 2){
            // Crear objetos matriz tipo float
            Matrix<float> m1(_rows1, _cols1);
            Matrix<float> m2(_rows2, _cols2);
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
                        // Randomizar valores e imprimir matrices
                        cout << "Rellenando la matriz 1..." << endl;
                        m1.randomFillMatrix();
                        cout << "MATRIZ 1" << endl;
                        cout << "--------" << endl;  
                        m1.display();
                        cout << "Rellenando la matriz 2..." << endl;
                        m2.randomFillMatrix();
                        cout << "MATRIZ 2" << endl;
                        cout << "--------" << endl;  
                        m2.display();
                        break;
                    case 2: 
                        // Ingresar valores manualmente e imprimir matrices
                        cout << "\nMATRIZ 1" << endl;
                        cout << "--------" << endl;
                        m1.fillMatrix();
                        m1.display();
                        cout << "\nMATRIZ 2" << endl;
                        cout << "--------" << endl;
                        m2.fillMatrix();
                        m2.display();
                        break;
                    case 3:
                        // Imprimir matrices
                        cout << "Matriz 1 " << endl;
                        cout << "---------" << endl;
                        m1.display();
                        cout << "Matriz 2 " << endl;
                        cout << "---------" << endl;
                        m2.display();
                        break;
                    case 4:
                        // Sentencia condicional para realizar operaciones
                       if (op == 1){
                        // Suma
                            try{
                                cout << "\nRESULTADO" << endl;
                                cout << "--------" << endl; 
                                floatOp.sum(m1, m2).display();
                            }
                            // Manejar excepcion en caso de operacion invalida, si hiciera falta
                            catch(const exception& e){
                                cerr << e.what() << endl;
                            }
                        } else if(op == 2){
                            // Resta
                            try{
                                cout << "\nRESULTADO" << endl;
                                cout << "--------" << endl; 
                                floatOp.sub(m1, m2).display();
                            }
                            // Manejar excepcion en caso de operacion invalida, si hiciera falta
                            catch(const exception& e){
                                cerr << e.what() << endl;
                            }
                        } else if(op == 3){
                            // Multiplicacion
                            try{
                                cout << "\nRESULTADO" << endl;
                                cout << "--------" << endl;  
                                floatOp.mult(m1, m2).display();
                            }
                            // Manejar excepcion en caso de operacion invalida, si hiciera falta
                            catch(const exception& e){
                                cerr << e.what() << endl;
                            }
                        }
                        break;  
                    case 5:
                        // Salir del programa
                        goto exit;
                        break;
                    default:
                        // Volver a pedir opcion
                        cout << "Ingrese una opcion valida." << endl;
                        break;
                }
            } while(true);
        }
        // Caso de complex
        else if (type == 3){
            cout << "NOTA: Los numeros complejos son mostrados de la forma (Re, Im)" << endl;
            // Crear objetos matriz tipo float
            Matrix<complex<float>> m1(_rows1, _cols1);
            Matrix<complex<float>> m2(_rows2, _cols2);
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
                        // Randomizar valores e imprimir matrices
                        cout << "Rellenando la matriz 1..." << endl;
                        m1.randomFillMatrix();
                        cout << "MATRIZ 1" << endl;
                        cout << "--------" << endl;  
                        m1.display();
                        cout << "Rellenando la matriz 2..." << endl;
                        m2.randomFillMatrix();
                        cout << "MATRIZ 2" << endl;
                        cout << "--------" << endl;  
                        m2.display();
                        break;
                    case 2: 
                        // Ingresar valores manualmente e imprimir matrices
                        cout << "\nMATRIZ 1" << endl;
                        cout << "--------" << endl;
                        m1.fillMatrix();
                        m1.display();
                        cout << "\nMATRIZ 2" << endl;
                        cout << "--------" << endl;
                        m2.fillMatrix();
                        m2.display();
                        break;
                    case 3:
                        // Imprimir matrices
                        cout << "Matriz 1 " << endl;
                        cout << "---------" << endl;
                        m1.display();
                        cout << "Matriz 2 " << endl;
                        cout << "---------" << endl;
                        m2.display();
                        break;
                    case 4:
                        // Sentencia condicional para realizar operaciones
                       if (op == 1){
                        // Suma
                            try{
                                cout << "\nRESULTADO" << endl;
                                cout << "--------" << endl; 
                                complexOP.sum(m1, m2).display();
                            }
                            // Manejar excepcion en caso de operacion invalida, si hiciera falta
                            catch(const exception& e){
                                cerr << e.what() << endl;
                            }
                        } else if(op == 2){
                            // Resta
                            try{
                                cout << "\nRESULTADO" << endl;
                                cout << "--------" << endl; 
                                complexOP.sub(m1, m2).display();
                            }
                            // Manejar excepcion en caso de operacion invalida, si hiciera falta
                            catch(const exception& e){
                                cerr << e.what() << endl;
                            }
                        } else if(op == 3){
                            // Multiplicacion
                            try{
                                cout << "\nRESULTADO" << endl;
                                cout << "--------" << endl;  
                                complexOP.mult(m1, m2).display();
                            }
                            // Manejar excepcion en caso de operacion invalida, si hiciera falta
                            catch(const exception& e){
                                cerr << e.what() << endl;
                            }
                        }
                        break;  
                    case 5:
                        // Salir del programa
                        goto exit;
                        break;
                    default:
                        // Volver a pedir opcion
                        cout << "Ingrese una opcion valida." << endl;
                        break;
                }
            } while(true);
        }
    }while(true);

    exit:
    cout << "Saliendo del programa..." << endl;
    return 0;
}