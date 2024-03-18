// Programa de variabes o funcion externa

#include <iostream> // Importar libreria basica de input - output
using namespace std; // Definir namespace para cout y cin

extern int count; // Inicializa variable externa

void write_extern(void){
    cout << "Cuenta es: " << count << endl;
}