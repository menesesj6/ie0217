#include <iostream>
#include <regex>

int main(){
    // Definir el regex
    auto const regex = std::regex("(my|your) regex");

    // Definir un string
    auto const myText = std::string("A piece of text that contains my regex.");
    // Retornar un bool si se encuentra el regex definido en el string
    bool const myTextContainsRegex = std::regex_search(myText, regex);

    // Repetir proceso de buscar regex
    auto const yourText = std::string("A piece of text that contains your regex.");
    bool const yourTextContainsRegex = std::regex_search(yourText, regex);

    // Repetir proceso de buscar regex
    auto const theirText = std::string("A piece of text that contains their regex.");
    bool const theirTextContainsRegex = std::regex_search(theirText, regex);

    // Imprimir los resultados
    std::cout << std::boolalpha
              << myTextContainsRegex << '\n'
              << yourTextContainsRegex << '\n'
              << theirTextContainsRegex << '\n';
    
    return 0;
}