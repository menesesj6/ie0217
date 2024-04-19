#include <iostream>
#include <unordered_set>

using namespace std;

int main(){
    // Inicializar y definir un set desordenado
    unordered_set<int> numbers = {1, 100, 10, 70, 100};

    // Imprimir el set
    cout << "Numbers are: ";
    for(auto &num: numbers){
        cout << num << ", ";
    }

    return 0;
}