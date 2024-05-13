#include "EmailValidator.hpp"

bool EmailValidator::checkEmail(const string& inputEmail, char complex){ 
    // Formatos como regex
    regex nf(nameFormat);
    regex df(domainFormat);
    regex ef(extensionFormat); 

    // Verificar la existencia del @
    int foundat = inputEmail.find_first_of('@');
    if (foundat == string::npos) 
        throw invalid_argument("ERROR: La direccion de correo debe incluir @.");

    // Extraer unicamente la parte del nombre
    string emailName = inputEmail.substr(0, foundat);
    cout << "Nombre: " << emailName << endl;
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
    } else cout << "Nombre valido!" << endl;

    // Obtener el ultimo y penultimo punto del email
    string restEmail = inputEmail.substr(foundat + 1, inputEmail.length());
    int lastPoint = restEmail.rfind('.');
    int secondLastPoint = restEmail.rfind('.', lastPoint - 1);
    string emailDomain, emailExtension;  
    
    if(complex == 'Y' || complex == 'y'){
        emailDomain = restEmail.substr(0, secondLastPoint);
        emailExtension = restEmail.substr(secondLastPoint + 1, restEmail.length());
    } else if (complex == 'N' || complex == 'n'){
        emailDomain = restEmail.substr(0, lastPoint);
        emailExtension = restEmail.substr(lastPoint + 1, restEmail.length());
    }

    cout << "Dominio: " << emailDomain << endl;
    cout << "Extension: " << emailExtension << endl;

    if(!regex_match(emailDomain, df)){
        cout << "El dominio no entro en el regex" << endl;
        bool cons = false;
        if(emailDomain.length() < 3 || emailDomain.length() > 30) 
            throw invalid_argument("ERROR: El dominio del email debe tener entre 3 y 30 caracteres.");

        if(emailDomain[0] == '.' || emailDomain[emailDomain.length()] == '.' || emailDomain.find('.') == string::npos) 
            throw invalid_argument("ERROR: El dominio debe tener al menos un punto, y no empezar ni terminar con punto.");

        for (int i = 0; i < emailDomain.length(); i++){
            if(emailDomain[i] == '.' && emailDomain[i+1] == '.')
                cons = true;
        }

        if(cons) throw invalid_argument("ERROR: El dominio no puede tener dos puntos seguidos.");
    } else cout << "Dominio valido!" << endl;


    return true;
}