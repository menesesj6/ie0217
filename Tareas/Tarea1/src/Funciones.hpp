#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "Ahorcado.hpp"

void SetDifficulty(int* dif);
void Initialize(int currWords, int* dif, string dict[], Ahorcado* ahorcado);
void Guessing();
void GuessCheck();
void AddWords(int* currWords, string dict[]);
void PrintDictionary(int currWords, string dict[]);
#endif