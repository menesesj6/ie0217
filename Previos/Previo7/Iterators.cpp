#include <iostream>
#include <vector>

using namespace std;

int main(){
    // Crear vector
    vector<string> languages = {"Python", "C++", "Java"};
    // Crear iterador
    vector<string>::iterator itr;

    // Recorrer vector
    for(itr = languages.begin(); itr != languages.end(); itr ++){
        // Acceder al elemento por de-referencia
        cout << *itr << ", ";
    }

    return 0;
}