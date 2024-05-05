#ifndef INPUTVALIDATOR_HPP
#define INPUTVALIDATOR_HPP

#include <iostream>  
#include <string>
using namespace std;

template <class T>
class InputValidator{
    public:
        void validateData(string num);
        void validateDimensions(int r, int c);
};

#endif