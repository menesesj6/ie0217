// Programa para usar define y enum
#include <iostream>
using namespace std;

#define MI_PRIMER_DEFINE 925 // ES PRE - PROCESADO

// Se crean un enum de temporadas 
enum seasons{
    spring = 34,
    summer = 4,
    autumn = 9,
    winter = 32
};

enum enumcito{
    carro,
    casa,
    arbol,
    patio
};

int main() {
    seasons s;
    s = summer;
    cout << "Summer = " << s << endl; 
    cout << "Define: " << MI_PRIMER_DEFINE << endl; // Aca se llama solo al macro creado
    cout << "arbol = " << arbol << endl; 

    return 0;
}