#include "Funciones.hpp"

// Menu de dificultad
void SetDifficulty(int* dif){
    do{
        cout << "\nMENU DE DIFICULTAD" << endl;
        cout << "1. Facil. Tendra 7 intentos. " << endl;
        cout << "2. Intermedio. Tendra 5 intentos. " << endl;
        cout << "3. Dificil. Tendra 3 intentos. " << endl;
        cout << "Ingrese el numero de su eleccion: ";
        cin >> *dif;
        // Acomodar el maximo de intentos dependiendo de dificultad seleccionada
    }while(*dif != EASY & *dif != MEDIUM & *dif != HARD);
}

// Funcion de inicializacion del juego
void Initialize(int currWords, int* dif, string dict[], Ahorcado* ahorcado){
    cout << "COMIENZA EL JUEGO!!" << endl;

    int wordIndex = rand()%currWords - 1; // Generar indice aleatorio del diccionario
    ahorcado->word = dict[wordIndex]; // Asignar palabra aleatoria a adivinar

    // Inicializar la palabra como guiones bajos
    int length = ahorcado->word.length();
    for (int i = 0; i <= 2 * length - 2; i++){
        if(i % 2 == 0){
            ahorcado->wordStatus[i] = '_';
        } else{
            ahorcado->wordStatus[i] = ' ';
        }
        
    };

    // Sentencia switch para acomodar intentos maximos de juego
    switch (*dif){
        case EASY:
            ahorcado->maxTries = 7;
            ahorcado->remainingTries = 7;
            break;
        case MEDIUM:
            ahorcado->maxTries = 5;
            ahorcado->remainingTries = 5;
            break;
        case HARD:
            ahorcado->maxTries = 3;
            ahorcado->remainingTries = 3;
            break;
        default:
            ahorcado->maxTries = ahorcado->maxTries;
            ahorcado->remainingTries = ahorcado->remainingTries;
            break;
    }


    cout << "\nIntentos maximos: " << ahorcado->maxTries << endl;
    cout << "Intentos restantes: " << ahorcado->remainingTries << endl;
    cout << "Palabra: ";
    for (int i = 0; i < 2*length-1; i++){
        cout << ahorcado->wordStatus[i];
    }
}

// Agregarle palabras al diccionario
void AddWords(int* currWords, string dict[]){
    int choice;
    string newWord;
    cout << "Ingrese la palabra que desea agregar al diccionario: ";
    cin >> newWord;
    *(dict + *currWords) = newWord;
    *currWords += 1;
}

// Imprimir el diccionario
void PrintDictionary(int currWords, string dict[]){
    cout << "\nDICCIONARIO\n" << endl; // Titulo
    // Se itera por el diccionario y se imprime cada elemento
    for(int i = 0; i < currWords; i++){
        cout << i + 1 << ". " << dict[i] << endl;
    }
}