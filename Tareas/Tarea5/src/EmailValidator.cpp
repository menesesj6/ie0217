#include "EmailValidator.hpp"

EmailValidator::EmailValidator(const string& _format) : format(_format){};

bool EmailValidator::checkEmail(const string& inputEmail){
    if(regex_search(inputEmail, this->format)){
        return true;
    } else{
        cout << "NO califica" << endl;
        return false;
    }
}