#include "EmailValidator.hpp"

bool EmailValidator::checkEmail(const string& inputEmail){ 
    // Formatos como regex
    regex nf(nameFormat); 
    regex df(domainFormat);
    regex ef(extensionFormat);

    // Analizar email
    cout << "Datos email ingresado:" << endl;
    cout << "----------------------" << endl;

    // Verificar la existencia del @
    int foundat = inputEmail.find_first_of('@');
    if (foundat == string::npos) 
        throw invalid_argument("ERROR: La direccion de correo debe incluir @.");

    // Extraer unicamente la parte del nombre
    string emailName = inputEmail.substr(0, foundat);
    cout << "\tNombre: " << emailName << endl;
    // Caso que el nombre sea invalido
    if(!regex_match(emailName, nf)){
        int namelen = 0;
        bool cont = false;
        bool inv = false;
        // Iterar nombre para buscar el fallo
        for(int i = 0; i < emailName.length(); i++){
            // Su extension no toma en cuenta puntos
            if(emailName[i] != '.')
                namelen++;

            // Verificar si hay caracteres especiales seguidos
            if(emailName[i] == '.' && emailName[i+1] == '.' ||
                emailName[i] == '-' && emailName[i+1] == '-' ||
                emailName[i] == '_' && emailName[i+1] == '_')
                cont = true;

            // Caracteres no permitidos
            if (emailName.find_first_not_of(nameFormat) != string::npos)
                inv = true;
        }

        // Excepcion en caso de 15+ caracteres
        if(namelen > 15) throw invalid_argument("ERROR: NOmbre debe tener 15 o menos caracteres.");

        // Excepcion en caso de empezar o terminar con ., - o _
        if(emailName[0] == '.' || emailName[0] == '-' || emailName[0] == '_' || emailName[emailName.length()] == '.' 
            || emailName[emailName.length()] == '-' || emailName[emailName.length()] == '_' )
            throw invalid_argument("ERROR: El nombre no debe comenzar ni terminar con un punto, guion o guion bajo.");

        // Excepcion en caso de tener dos caracteres especiales consecutivos 
        if(cont) throw invalid_argument("ERROR: En el nombre no deben haber caracteres especiales consecutivos.");

        // Excepcion en caso de haber caracteres invalidos
        if(inv) throw invalid_argument("ERROR: En el nombre no deben haber caracteres que no sean letras, numeros, puntos, guiones o guiones bajos.");
    };

    return true;
}