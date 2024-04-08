#include "Planeta.hpp"

Planeta::Planeta(string _name, Continente _c1, Continente _c2, Continente _c3, Continente _c4, Continente _c5) : 
        name(_name), c1(_c1), c2(_c2), c3(_c3), c4(_c4), c5(_c5){}

void Planeta::getInfo(){
    // Imprimir continentes
    cout << "El planeta " << this->name << " tiene 5 continentes: " << endl;
    for(int i = 0; i < 5; i++){
        cout << i + 1 << ". " << this->continentes[i]->name << endl;
    };

    // Imprimir continentes por los que pasa el avion
    cout << "\nEn el planeta " << this->name << " los aviones pasan por los continentes: " << endl;
    for(int i = 0; i < 5; i++){
        if (this->continentes[i]->plane){
            cout << this->continentes[i]->name << endl;
        };
    };

    cout << " " << endl;

    // Imprimir informacion de los continentes
    for(int i = 0; i < 5; i++){
        cout << this->continentes[i]->name << ": " << this->continentes[i]-> ped << " paises en desarrollo y " << this->continentes[i]->ppm << " paises de primer mundo." << endl;
    };

    
    
}