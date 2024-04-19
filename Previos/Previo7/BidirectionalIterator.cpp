#include <iostream>
#include <list>

using namespace std;

int main(){
    // Crear lista y su iterador
    list<int>  nums{1,2,3,4, 5};
    list<int>::iterator itr = nums.begin();

    cout << "MOving forward: " << endl;

    // Iterar del elemento 0 al 4
    while(itr != nums.end()){
        cout << *itr << ", ";

        itr++;
    }

    cout << "\nMoving backward: " << endl;

    // Iterar en reversa del elemento 4 al 1
    while(itr != nums.begin()){
        if(itr != nums.end()){
            cout << *itr << ", ";
        }
        itr--;
    }

    // Imprimir elemento 0
    cout << *itr << endl;

    return 0;
}