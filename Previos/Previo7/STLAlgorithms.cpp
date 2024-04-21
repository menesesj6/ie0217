#include <iostream>
#include <algorithm>
#include <vector>

// Compara logicamente
bool myfunction(int i, int j){ return (i < j); }

// Clase necesaria
struct myclass{
    // Sobrecarga de operador
    bool operator() (int i, int j){return ( i < j);}
} myobject;

int main(){
    // Definir el vector basado en un array
    int myints[] = {32, 71, 12, 45, 26, 80, 53, 33};
    
    // myints es puntero al primer elemento
    // myints+8 es puntero al ultimo elemento
    std::vector<int> myvector (myints, myints+8);

    // Ordena del primero al tercer elemento
    std::sort (myvector.begin(), myvector.begin());

    // Ordena los ultimos 4 elementos
    // Usa myfunction como auxiliar
    std::sort (myvector.begin()+4, myvector.end(), myfunction);

    // Ordena todo usando la sobrecarga del struct
    std::sort (myvector.begin(), myvector.end(), myobject);

    // Imprimir resultado
    std::cout << "myvector contains: ";

    for(std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    return 0;
}
