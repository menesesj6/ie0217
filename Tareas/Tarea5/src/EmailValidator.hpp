/**
 * @file EmailValidator.hpp
 * @author Jorge Meneses (j.menesesgarro@gmail.com)
 * @brief Clase que se encarga de verificar los emails ingresados por el usuario
 * @version 1.0
 * @date 2024-05-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef EMAILVALIDATOR_HPP
#define EMAILVALIDATOR_HPP

#include <iostream>
#include <string>
#include <regex>

using namespace std;

/**
 * @brief Clase cuyos objetos sirven como validador de emails para ciertas especificaciones.
 * 
 * Especificaciones
 * ----------------
 * Formato email: nombre@dominio.extension
 * 
 * nombre:
 *      - Letras (mayusculas o minusculas), numeros, puntos, guiones o guiones bajos.
 *      - 15 o menos caracteres, sin contar puntos.
 *      - No comienza ni termina con punto, guion o guion bajo 
 *      - No tener caracteres especiales seguidos ('..', '--', '__') 
 * 
 * dominio:
 *      - SOlo etras.
 *      - AL menos un punto, pero no al inicio ni al final.
 *      - Entre 3 y 30 caracteres, sin contar los puntos.
 *      - NO tener dos puntos seguidos.
 * 
 * extension:
 *      - Entre 2 y 6 letras.
 *      - No numeros ni caracteres especiales.
 *      - Puede ser compuesta. (Se le pregunta al usuario)
 * 
 */
class EmailValidator{
    private:
        string nameFormat =  "^[^.-_](?!.*[-._]{2})([a-zA-Z0-9.-_]{1,15})+[^.-_]$"; /**<- Patron para el regex del nombre del email.*/
        string domainFormat = R"(^[^.-_](?!.*[-._]{2})[\w.\w]([a-zA-Z0-9.-_]{3,30})+[^.-_]$)"; /**<- Patron para el regex del dominio del email.*/
        string extensionFormat = "^(?!.*[.]{2})([a-zA-Z]{2,6})$"; /**<- Patron para el regex de la estension del email.*/
    public:
        /**
         * @brief Metodo que verifica el email en base a los regex miembros de la clase.
         * 
         * Divide el email en tres partes: nombre, dominio y extension, usando la informacion de posicion del @ y el tipo de extension.
         * Usa la funcion regex_match  para verificar si cada parte del correo ingresado calza con el formato definido en la clase. Lanzar excepciones que especifican el problema especifico.
         * 
         * @param inputEmail Correo ingresado por el usuario que se desea verificar.
         * @param complex Parametro que indica si la extension del correo es compuesta o no.
         * @return true Todas las partes del correo son validas, por ende, el correo es valido.
         * @return false Alguna o varias de las partes del correo no son validas, por ende, el correo no es valido.
         */
        bool checkEmail(const string& inputEmail, const char complex);
};

#endif