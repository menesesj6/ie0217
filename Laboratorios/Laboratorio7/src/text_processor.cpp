#include "text_processor.hpp"
#include <fstream>
#include <regex>

// Definir constructor parametrizado
TextProcessor::TextProcessor(const std::string& input_filename, const std::string& output_filename)
    : input_filename(input_filename), output_filename(output_filename){}


void TextProcessor::replace(const std::string& search_pattern, const std::string& replace_string){
    // ifstream : input file stream -> Procesar input file
    std::ifstream input_file(input_filename);
    // ofstream : output file stream -> Procesar output file
    std::ofstream output_file(output_filename);
    // Variable para ir definiendo la linea
    std::string line;

    // Definir el patron que se quiere reemplazar
    std::regex pattern(search_pattern);

    // Cuando haya input file y output file
    if(input_file && output_file){
        // Ir obteniendo las lineas del input file
        while(getline(input_file, line)){
            // SUstituir el patron regex con el string deseado en la linea actual
            std::string replaced = std::regex_replace(line, pattern, replace_string);
            // Echo del nuevo string al archivo output con los remplazos hechos
            output_file << replaced << "\n";
        }
    }
}