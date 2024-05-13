#ifndef EMAILVALIDATOR_HPP
#define EMAILVALIDATOR_HPP

#include <iostream>
#include <string>
#include <regex>

using namespace std;

class EmailValidator{
    private:
        string nameFormat =  "^[^.-_](?!.*[-._]{2})([a-zA-Z0-9.-_]{1,15})+[^.-_]$";
        string domainFormat = R"(^[^.-_](?!.*[-._]{2})(\w.\w)([a-zA-Z0-9.-_]{3,30})+[^.-_]$)";
        string extensionFormat = "^(?!.*[.]{2})([a-zA-Z]{2,6})$";
    public:
        bool checkEmail(const string& inputEmail, char complex);
};

#endif