#include "EmailValidator.hpp"

int main(){
    int option;
    string email;
    try{
        EmailValidator checker(R"([a-zA-Z0-9]+[\w.-]*[a-zA-Z0-9]+@[a-zA-Z]+(?:\.[a-zA-Z]+)+)");
        cout << "VALIDADOR DE EMAILS" << endl;
        cout << "-------------------" << endl << endl;
        cout << "MENU: " << endl;
        do{
            cout << "\t1. Verificar email." << endl;
            cout << "\t2. Salir del programa." << endl;
            cin >> option;
            switch (option){
                case 1:
                    cout << "Ingrese el email que desea verificar: ";
                    cin.ignore();
                    getline(cin, email);
                    checker.checkEmail(email);
                    break;
                default:
                    cout << "Saliendo del programa..." << endl;
                    break;
            } 
        }while(option != 2);
    }
    catch(const exception& e){
        cerr << e.what() << endl;
    }
}