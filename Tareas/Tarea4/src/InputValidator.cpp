#include "InputValidator.hpp"

template <class T>
void InputValidator<T>::validateData(string num){
    int aux = 0;
    float aux1 = 0.0;
    int type;
    int nums = 0, dots = 0, minuses = 0;
    for(int i = 0; i < num.length(); i++){
        if(!isdigit(num[i]) && num[i] != '.' && num[i] != '-') throw runtime_error("Error de tipo.");
        else if (isdigit(num[i])) nums ++;
        else if (!isdigit(num[i]) && num[i] == '.') dots++;
        else if (num[i] == '-') minuses;
    }

    if(nums + minuses == num.length()) type = 1;
    else if (nums + dots + minuses == num.length()) type = 2;
    
    if (typeid(T).name() == typeid(aux).name() && type == 2){
        throw runtime_error("Error de tipo.");
    } else if (typeid(T).name() == typeid(aux1).name() && type == 1){
        throw runtime_error("Error de tipo.");
    }
}

template <class T>
void InputValidator<T>::validateDimensions(int r, int c){
    if(c <= 0 || r <= 0){
        throw runtime_error("ERROR: Dimensiones invalidas.");
    }
}

// SOlucion linking problems
template void InputValidator<int>::validateData(string num);
template void InputValidator<float>::validateData(string num);
template void InputValidator<int>::validateDimensions(int r, int c);
template void InputValidator<float>::validateDimensions(int r, int c);