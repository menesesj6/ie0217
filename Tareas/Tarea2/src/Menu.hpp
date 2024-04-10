/**
 * @file Menu.hpp
 * @author Jorge Meneses Garro
 * @brief Se definen los enums empleados para menus
 * @version 1.0
 * @date 2024-04-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef MENU_HPP
#define MENU_HPP

/**
 * @brief Enum de las opciones para el menu principal del sistema
 * 
 */
enum Opciones {
    INFO = 1,
    COMPARAR,
    AGREGAR,
    QUITAR,
    SALIR
};

/**
 * @brief Enum de los continentes disponibles en el sistema
 * 
 */
enum Continentes{
    AMERICA = 1,
    ASIA,
    AFRICA,
    EUROPA,
    OCEANIA
};

#endif