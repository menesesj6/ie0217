#ifndef TEXTPROCESSOR_HPP
#define TEXTPROCESSOR_HPP
#include <string>

// Crear clase
class TextProcessor{
    private:
        // Atributos
        std::string input_filename;
        std::string output_filename;
    public:
        // Constructor paramtrizado
        TextProcessor(const std::string& input_filename, const std::string& output_filename);
        // Metodo de remplazo de patrones
        void replace(const std::string& search_pattern, const std::string& replace_string);
};

#endif