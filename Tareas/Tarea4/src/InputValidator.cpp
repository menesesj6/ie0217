#include "InputValidator.hpp"

template <class T>
void InputValidator<T>::validateData(string num){
    // Variables int y float auxiliares para comparar tipos
    int aux = 0;
    float aux1 = 0.0;

    // Inicializar variable para el tipo del input
    int type;
    
    // Inicializar en 0 cantidades de caracteres
    int nums = 0, dots = 0, minuses = 0;
    
    // Iterar el input para definir si es int, float o algo mas
    for(int i = 0; i < num.length(); i++){
        // Revisar si el caracter es es no-numero, no punto y no guion
        if(!isdigit(num[i]) && num[i] != '.' && num[i] != '-') throw runtime_error("Error de tipo.");
        // Revisar si es numero
        else if (isdigit(num[i])) nums ++;
        // Revisar si es punto, por los decimales
        else if (!isdigit(num[i]) && num[i] == '.') dots++;
        // Revisar si es guion, son los menos
        else if (num[i] == '-') minuses++;
    }

    // Revisar si el input es int
    if(nums + minuses == num.length()) type = 1;
    // Revisar si el input es float
    else if (nums + dots + minuses == num.length()) type = 2;
    
    // Revisar para el caso de complejos que tiene componentes floats
    if(typeid(T) == typeid(complex<float>)){
        if(type == 1){
            throw runtime_error("COmponente complejo de tipo erroneo.");
        } else if(type == 2){
            return;
        }
    }

    // Lanzar excepcion si el tipo de input es distinto del parametro T 
    if (typeid(T).name() == typeid(aux).name() && type == 2){
        throw runtime_error("Error de tipo.");
    } else if (typeid(T).name() == typeid(aux1).name() && type == 1){
        throw runtime_error("Error de tipo.");
    } 
}

template <class T>
void InputValidator<T>::validateDimensions(int r, int c){
    // Lanzar excepcion si las dimensiones son no-positivas
    if(c <= 0 || r <= 0){
        throw runtime_error("ERROR: Dimensiones invalidas.");
    }
}

// Solucion linking problems
template void InputValidator<int>::validateData(string num);
template void InputValidator<float>::validateData(string num);
template void InputValidator<complex<float>>::validateData(string num);
//template void InputValidator<complex<int>>::validateData(string num);

template void InputValidator<int>::validateDimensions(int r, int c);
template void InputValidator<float>::validateDimensions(int r, int c);
template void InputValidator<complex<float>>::validateDimensions(int r, int c);
//template void InputValidator<complex<int>>::validateDimensions(int r, int c);

