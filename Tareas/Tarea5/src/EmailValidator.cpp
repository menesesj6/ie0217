/**
 * @file EmailValidator.cpp
 * @author Jorge Meneses (j.menesesgarro@gmail.com)
 * @brief Definicion de la clase que se encarga de verificar los emails (EmailValidator)
 * @version 1.0
 * @date 2024-05-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "EmailValidator.hpp"

bool EmailValidator::checkEmail(const string& inputEmail, const char complex){ 
    cout << "RESULTADO:" << endl;
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
    cout << "\nNombre: " << emailName << endl;

    int countN = 0;
    for(int i = 0; i < emailName.length(); i++){
        if(emailName[i] != '.')
            countN++;
    }

    if(countN < 1 || countN > 15){
        throw invalid_argument("ERROR: El nombre del email debe tener entre 1 y 15 caracteres.");
    }

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
        }

        // Caracteres no permitidos
        if (emailName.find_first_not_of(nameFormat) != string::npos)
            inv = true;

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

        // Imprimir que el correo es invalido
        cout << "Correo invalido por nombre invalido." << endl;
        return false;
    } else cout << "Nombre valido!" << endl;

    // Obtener el ultimo y penultimo punto del email
    string restEmail = inputEmail.substr(foundat + 1, inputEmail.length());

    // Posiciones dle ultimo y penultimo punto
    int lastPoint = restEmail.rfind('.');
    int secondLastPoint = restEmail.rfind('.', lastPoint - 1);

    // Strings que definen dominio y extension del email
    string emailDomain, emailExtension;  
    
    // Caso para extension compuesta
    if(complex == 'Y' || complex == 'y'){
        emailDomain = restEmail.substr(0, secondLastPoint);
        emailExtension = restEmail.substr(secondLastPoint + 1, restEmail.length());
    } // Caso para extension sencilla 
    else if (complex == 'N' || complex == 'n'){
        emailDomain = restEmail.substr(0, lastPoint);
        emailExtension = restEmail.substr(lastPoint + 1, restEmail.length());
    }

    // Imprimir dominio
    cout << "\nDominio: " << emailDomain << endl;

    int countD = 0;
    for(int i = 0; i < emailDomain.length(); i++){
        if(emailDomain[i] != '.')
            countD++;
    }

    if(countD < 3 || countD > 30){
        throw invalid_argument("ERROR: El dominio del email debe tener entre 3 y 30 caracteres.");
    }

    // Verificacion inicial de si hay al menos un punto
    if(emailDomain.find('.') == string::npos) 
            throw invalid_argument("ERROR: El dominio debe tener al menos un punto, y no empezar ni terminar con punto.");
    
    // Verificar si el dominio es valido
    if(!regex_match(emailDomain, df)){
        // Variable que indica si hay consecutivos
        bool cons = false;

        // Expecion por dimension del dominio
        if(emailDomain.length() < 3 || emailDomain.length() > 31) 
            throw invalid_argument("ERROR: El dominio del email debe tener entre 3 y 30 caracteres.");

        // Caso de que no haya punto, inicie o termine en punto
        if(emailDomain[0] == '.' || emailDomain[emailDomain.length()] == '.' || emailDomain.find('.') == string::npos) 
            throw invalid_argument("ERROR: El dominio debe tener al menos un punto, y no empezar ni terminar con punto.");

        // Iterar dominio para revisar si hay puntos consecutivos
        for (int i = 0; i < emailDomain.length(); i++){
            // Indicar con un booleano que hay puntos consecutivos
            if(emailDomain[i] == '.' && emailDomain[i+1] == '.')
                cons = true;
        }

        // Excepcion si hay puntos seguidos
        if(cons) 
            throw invalid_argument("ERROR: El dominio no puede tener dos puntos seguidos.");

        // Excepcion si hay caracteres no permitidos
        if(emailDomain.find_first_not_of(domainFormat) != string::npos) 
            throw invalid_argument("ERROR: El dominio no puede tener dos puntos seguidos.");

        // Imprimir que el correo es invalido
        cout << "Correo invalido por dominio invalido." << endl;
        return false;
    } else cout << "Dominio valido!" << endl;

    // Imprimir extension
    cout << "\nExtension: " << emailExtension << endl;

    int countE = 0;
    for(int i = 0; i < emailExtension.length(); i++){
        if(emailExtension[i] != '.')
            countE++;
    }

    if(countE < 2 || countE > 6){
        throw invalid_argument("ERROR: La extension debe ser entre 2 y 6 letras.");
    }

    // Verificar si la extension es valida
    if(!regex_match(emailExtension, ef)){
        // Excepcion por dimension de extension
        if(emailExtension.length() < 2 || emailExtension.length() > 7)
            throw invalid_argument("ERROR: La extension debe ser entre 2 y 6 caracteres.");

        // Excepcion si hay caracteres no permitidos
        if(emailExtension.find_first_not_of(extensionFormat) != string::npos)
            throw invalid_argument("ERROR: En la extension solo deben haber letras o un punto (compuestas).");

        // Imprimir que el correo es invalido
        cout << "Correo invalido por extension invalida." << endl;
        return false;
    } else cout << "Extension valida!" << endl;

    return true;
}