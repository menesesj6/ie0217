#include <iostream>
#include <set>

using namespace std;

int main(){
    // Inicializar y definir un set int
    set<int> numbers = {1, 100, 10, 70, 100};

    // Imprimir el set
    cout << "Numbers are: ";
    for(auto &num: numbers){
        cout << num << ", ";
    }

    return 0;
}