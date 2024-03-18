// Programa entendimiento argc y argv
#include <iostream> // Importar libreria basica de input - output
int main(int argc, char* argv[]){

    std::cout << "argc: " << argc << std::endl; // Imprimir cuantos argumentos se pasaron por linea de comandos 

    // Imprime los argumentos pasados a main hardcodeado
    std::cout << "argv[0]: " << argv[0] << std::endl;
    std::cout << "argv[1]: " << argv[1] << std::endl;
    std::cout << "argv[2]: " << argv[2] << std::endl;
    std::cout << "argv[3]: " << argv[3] << std::endl;

    // Imprime los argumentos pasados a main mas facilmente SOLO si hay adicionales
    if(argc > 1){ 
        std::cout << "Argumentos adicionales: \n" << std::endl;
        for (int i = 1; i < argc; ++i){
            std::cout << "argv[" << i << "]: " << argv[i] << std::endl; // Imprimir el parametro
        }
    }

    return 0; // Retorno codigo de error
}