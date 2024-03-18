// Programa de sentencia switch case
#include <iostream> // Importar libreria basica de input - output
int main(){
    std::cout << "Hola Mundo, estudiantes de IE0217! \n"; // Imprime string Hola mundo

    // Declaracion de variables
    int var1 = 9;
    // int var2 = 2;
    // int var3 = 2;

    // SE inicializa el switch case
    switch (var1){
        case 1:
            std::cout << "Case 1!\n";
            break;

        case 2:
            std::cout << "Case 2!\n";
            break;
        
        case 3:
            std::cout << "Case 3!\n";
            break;
        
        default: // Caso default, se ejecuta si no cae en ninguno de los casos
            std::cout << "Case Default!\n";
            break;
        }

    return 0; // Retorno codigo de error
}