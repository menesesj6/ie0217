#include "Funciones.hpp"

// Menu de dificultad
void SetDifficulty(int* dif){
    do{
        cout << "\nMENU DE DIFICULTAD" << endl;
        cout << "1. Facil. Tendra 7 intentos. " << endl;
        cout << "2. Intermedio. Tendra 5 intentos. " << endl;
        cout << "3. Dificil. Tendra 3 intentos. " << endl;
        cout << "Ingrese el numero de su eleccion: ";
        // Almacenamiento de la dificultad escogida
        cin >> *dif; 
    }while(*dif != EASY & *dif != MEDIUM & *dif != HARD); // Menu se sale cuando se escoge una dificultad
}

// Funcion de inicializacion del juego
void Initialize(int currWords, int* dif, string dict[], Ahorcado* ahorcado){
    // Mensaje inicial
    cout << "COMIENZA EL JUEGO!!" << endl;

    // Generar indice aleatorio del diccionario
    int wordIndex = rand()%currWords - 1; 
    // Asignar palabra aleatoria a adivinar
    ahorcado->word = dict[wordIndex];

    // Inicializar la palabra como guiones bajos
    int length = ahorcado->word.length(); // Saber el largo
    for (int i = 0; i <= 2 * length - 2; i++){
        // IMprimir guines bajos separados por espacios
        if(i % 2 == 0){
            ahorcado->wordStatus[i] = '_';
        } else{
            ahorcado->wordStatus[i] = ' ';
        }
        
    };

    // Sentencia switch para acomodar intentos maximos y restantes de juego segun la dificultad
    // TRabaja a nivel de punteros en el juego y la variable dif
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
    // Impresion inicial de stats
    cout << "\nIntentos maximos: " << ahorcado->maxTries << endl;
    cout << "Intentos restantes: " << ahorcado->remainingTries << endl;
    cout << "Palabra: ";
    // Imprimir guinoes bajos de la palabra
    for (int i = 0; i < 2*length-1; i++){
        cout << ahorcado->wordStatus[i];
    }
}

// Agregarle palabras al diccionario
void AddWords(int* currWords, string dict[]){
    string newWord;// Palabra ingresada por el usuario
    cout << "Ingrese la palabra que desea agregar al diccionario: ";
    cin >> newWord; // Guardarla
    *(dict + *currWords) = newWord; // Ingresarla al diccionario por medio de punteros
    *currWords += 1; // Aumentar el conteo de palabras en el diccionario
}

// Imprimir el diccionario
void PrintDictionary(int currWords, string dict[]){
    cout << "\nDICCIONARIO\n" << endl; // Titulo
    // Se itera por el diccionario y se imprime cada elemento
    for(int i = 0; i < currWords; i++){
        cout << i + 1 << ". " << dict[i] << endl;
    }
}