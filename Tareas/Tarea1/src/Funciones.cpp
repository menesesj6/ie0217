#include "Funciones.hpp"

// Funcion de configuracion de la dificultad
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

//*****************************************************************************

// Funcion de inicializacion del juego
void Initialize(int currWords, int* dif, string dict[], Ahorcado* ahorcado){
    // Mensaje inicial
    cout << "COMIENZA EL JUEGO!!" << endl;

    // Generar indice aleatorio del diccionario
    /*Se usa el random_device de la libreria random

    Este es un generador de numeros aleatorios real, sin necesidad de un seed, para evitar resultados
    deterministicos, como los obtenidos al usar rand()%currWords

    https://www.enseignement.polytechnique.fr/informatique/INF478/docs/Cpp/en/cpp/numeric/random/random_device/random_device.html
    */
    random_device rd;
    uniform_int_distribution<int> dis(0, currWords-1);
    int wordIndex = dis(rd);
    
    // Asignar palabra aleatoria a adivinar
    ahorcado->word = *(dict + wordIndex);

    //cout << ahorcado->word << endl;

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
    // Trabaja a nivel de punteros en el juego y la variable dif
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
}

//*****************************************************************************

// Funcion de adivinar
void Guessing(Ahorcado* ahorcado){
    int length = ahorcado->word.length();
    char guess;
    // Bucle siempre que hayan mas de 0 intentos
    while(Verification(ahorcado)){
        bool found = false; // Si la letra esta en la palabra o no
        cout << "Intentos restantes: " << ahorcado->remainingTries << endl;
        cout << "Palabra: ";
        // Imprimir guinoes bajos de la palabra
        for (int i = 0; i < 2*length-1; i++){
            cout << ahorcado->wordStatus[i];
        }
        // Pedir al usuario letra
        cout << "\n\nIngrese una letra: "<< endl;
        cin >> guess;
        guess = tolower(guess); // Pasarla a minuscula
        cout << "\n" << endl;

        // Actualizar word Status y ver si la palabra si esta
        for(int i = 0; i < length; i++){
            if(guess == ahorcado->word[i]){
                ahorcado->wordStatus[2 * i] = guess;
                found = true;
            }
        }
        // Controla la cantidad de intentos restantes
        if(found == false){
            ahorcado->remainingTries -= 1;
        }
    }
}

//*****************************************************************************

// Funcion de verificacion
bool Verification(Ahorcado* ahorcado){
    // INicializar string de ultimo intento
    string lastTry;

    // Inicializar contador de caracteres iguales
    int count = 0;
    for(int i = 0; i < ahorcado->word.length(); i++){
        if(ahorcado->word[i] == ahorcado->wordStatus[2 * i]){
            count ++;
        }
    }

    // Casos
    // 1er caso: estado de la palabra es igual a la palabra
    if (count==ahorcado->word.length()){
        cout << "Intentos restantes: " << ahorcado->remainingTries << endl;
        cout << "Palabra: ";
        for (int i = 0; i < 2*ahorcado->word.length()-1; i++){
            cout << ahorcado->wordStatus[i];
        }
        cout << "\n\nFELICIDADES!! GANASTE!!" << endl;
        cout << "-------------------------------------"<< endl;
        return false;
    // 2do caso: Se gastaron los intentos
    }else if(ahorcado->remainingTries == 0){
        cout << "\nULTIMA OPORTIUNIDAD!!" << endl << "Ingrese la palabra completa: ";
        cin >> lastTry;
        if(lastTry == ahorcado->word){
            cout << "\n\nFELICIDADES!! GANASTE!!" << endl;
            cout << "-------------------------------------"<< endl;
            return false; // Juego termina
        }else{
            cout << "\n\nGAME OVER" << endl << "La palabra correcta era: " << ahorcado->word << endl;
            cout << "-------------------------------------"<< endl;
            return false; // JUego termina
        }
    // 3er caso: La palabra aun no es igual y aun quedan intentos
    }else{
        return true; // JUego sigue
    }
}

//*****************************************************************************

// Agregarle palabras al diccionario
void AddWords(int* currWords, string dict[]){
    string newWord;// Palabra ingresada por el usuario
    cout << "Ingrese la palabra que desea agregar al diccionario: ";
    cin >> newWord; // Guardarla

    // Pasar palabra a minusculas
    for(int i=0; i < newWord.length(); i++){
        newWord[i] = tolower(newWord[i]);
    }
    
    // Asignar la nueva palabra por medio de punteros
    *(dict + *currWords) = newWord; // Ingresarla al diccionario por medio de punteros
    *currWords += 1; // Aumentar el conteo de palabras en el diccionario
}

//*****************************************************************************

// Imprimir el diccionario
void PrintDictionary(int currWords, string dict[]){
    cout << "\nDICCIONARIO\n" << endl; // Titulo
    // Se itera por el diccionario y se imprime cada elemento
    for(int i = 0; i < currWords; i++){
        cout << i + 1 << ". " << dict[i] << endl;
    }
}
