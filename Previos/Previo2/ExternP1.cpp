// Programa de variabes o funcion externa

#include <iostream> // Importar libreria basica de input - output
using namespace std; // Definir namespace para cout y cin

int count; // Inicializar variable global
extern void write_extern(); // Inicializar funcion externa

int main (){
    count = 5; // Asignar valor
    write_extern(); // Invocar funcion externa
    
    return 0;
}