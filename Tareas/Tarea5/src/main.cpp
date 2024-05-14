/**
 * @file main.cpp
 * @author Jorge Meneses (j.menesesgarro@gmail.com)
 * @brief Implementacion principal del programa.
 * @version 1.0
 * @date 2024-05-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "EmailValidator.hpp"

int main(){
    // Variable de seleccion del menu
    int option;
    // Email de input
    string email;
    // Define si es extension compleja o no
    char complex;
    try{
        // Instanciar el validador de correos
        EmailValidator checker;
        cout << "VALIDADOR DE EMAILS" << endl;
        cout << "-------------------" << endl << endl;
        do{
            cout << "\nMENU: " << endl;
            cout << "1. Verificar email." << endl;
            cout << "2. Salir del programa." << endl;
            cout << "Seleccion: ";
            cin >> option;
            switch (option){
                // Caso para verificar un mail
                case 1:
                    cout << "\nSu email tiene extension compuesta? (Y/N): ";
                    cin >> complex;
                    // Pedir al ususario el correo a verificar
                    cout << "Ingrese el email que desea verificar: ";
                    cin.ignore();
                    getline(cin, email);
                    // Revisar si el correo es valido
                    if(checker.checkEmail(email, complex))
                        cout << "Correo valido!" << endl;
                    break;
                default:
                    cout << "Saliendo del programa..." << endl;
                    break;
            } 
        }while(option != 2);
    }
    // Atrapar las excepciones estandar lanzadas de la revision
    catch(const exception& e){
        cerr << e.what() << endl;
    }

    return 0;
}