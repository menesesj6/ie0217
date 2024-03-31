#ifndef AHORCADO_H
#define AHORCADO_H

#define MAX_LENGTH_WORD 30

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

enum Options {
    DIFICULTAD = 1,
    INICIAR,
    AGREGAR,
    DICCIONARIO,
    SALIR
};

enum Difficulties {
    EASY = 1,
    MEDIUM,
    HARD,
    VOLVER
};

struct Ahorcado{
    string word;
    char wordStatus[30];
    int maxTries;
    int remainingTries;
};

#endif // HEADER_H