#include <iostream>
#include <forward_list>

using namespace std;

int main(){
    // Crear foward list y su iterador
    forward_list<int> numbers{1, 2, 3, 4};
    forward_list<int>::iterator itr = numbers.begin();

    // REasignar valores de la lista y cambiar el iterador
    while(itr != numbers.end()){
        int original_value = *itr;
        *itr = original_value * 2;
        itr++;
    }

    // Imprimir lista
    for(int num: numbers){
        cout << num << ", ";
    }

    return 0;
}