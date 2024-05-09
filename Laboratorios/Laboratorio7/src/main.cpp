
#include <iostream>
#include "text_processor.hpp"

int main(int argc, char* argv[]){
    // Error si hay menos de 5 argumentos en linea de comandos
    if(argc < 5){
        // ESpecificar uso
        std::cerr << "Usage: " << argv[0] << "-f <filename> -o <outputfile> -search <search_pattern> -replace <replace_string>\n";
    }

    // Variables auxiliares
    std::string filename = argv[2];
    std::string outputfile = argv[4];
    std::string search_pattern = argv[6];
    std::string replace_string = argv[8];
    
    // Instanciar clase
    TextProcessor processor(filename, outputfile);
    // Empezar a iterar y hacer los reemplazos
    processor.replace(search_pattern, replace_string);

    return 0;
}