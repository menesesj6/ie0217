#include "EmailValidator.hpp"

int main(){
    // Variable de seleccion del menu
    int option;
    // Email de input
    string email;
    try{
        // Instanciar el validador de correos
        EmailValidator checker;
        cout << "VALIDADOR DE EMAILS" << endl;
        cout << "-------------------" << endl << endl;
        cout << "MENU: " << endl;
        do{
            cout << "1. Verificar email." << endl;
            cout << "2. Salir del programa." << endl;
            cout << "Seleccion: ";
            cin >> option;
            switch (option){
                // Caso para verificar un mail
                case 1:
                    // Pedir al ususario el correo a verificar
                    cout << "\n\nIngrese el email que desea verificar: ";
                    cin.ignore();
                    getline(cin, email);
                    // Revisar si el correo es valido
                    if(checker.checkEmail(email))
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
}