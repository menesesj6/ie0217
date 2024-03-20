// Programa para usar enums
#include <iostream>
using namespace std;

// Se crean las enumeraciones 
enum seasons{
    spring = 34,
    summer = 4,
    autumn = 9,
    winter = 32
};

enum week{
    Sunday, // 0
    Monday, // 1
    Tuesday, // 2
    Wednesday, // 3
    Thursday, // 4
    Friday, // 5 
    Saturday // 6
};

enum suit{
    club = 0,
    hearts = 20,
    spades = 3,
    diamonds = 10
} card; // Instanciacion se va a llamar card

int main() {
    seasons s; // Crear s es una season
    s = winter;
    cout << "Summer = " << s << endl;

    week today; // Crear today
    today = Wednesday;
    cout << "Day " << today + 1 << endl;

    card = club; // Se asigna valor a card
    cout << "Tamano de la variable del enum " << sizeof(card) << " bytes.";

    return 0;
}