#ifndef EMAILVALIDATOR_HPP
#define EMAILVALIDATOR_HPP

#include <iostream>
#include <string>
#include <regex>

using namespace std;

class EmailValidator{
    private:
        regex format;
    public:
        EmailValidator(const string& _format);
        bool checkEmail(const string& inputEmail);
};

#endif