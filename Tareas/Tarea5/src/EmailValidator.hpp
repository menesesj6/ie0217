#ifndef EMAILVALIDATOR_HPP
#define EMAILVALIDATOR_HPP

#include <iostream>
#include <string>
#include <regex>

using namespace std;

class EmailValidator{
    private:
        string nameFormat =  "^(?![-._])(?!.*[-._]{2})[a-zA-Z0-9.-]{1,15}$";
        string domainFormat = R"([a-zA-Z0-9][\w.-]{0,13}[a-zA-Z0-9])";
        string extensionFormat = R"([a-zA-Z0-9][\w.-]{0,13}[a-zA-Z0-9])";
    public:
        bool checkEmail(const string& inputEmail);
};

#endif