// Programa de anidacion de sentencias

#include <iostream> // Importar libreria basica de input - output
#include <cstring> // Libreria para strings
using namespace std; // Definir namespace para cout y cin

// Primer struct sobre libros
struct Books {
    // Definir atributos
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
};

// Segundo struct sobre personas
struct Person {
    // Definir atributos
    char name[50];
    int age;
    float salary;
};

int main (){
    // Instanciar libros Book1 y Book2
    struct Books Book1;
    struct Books Book2;

    // Specs Book1
    strcpy(Book1.title, "Learn C++ Programming");
    strcpy(Book1.author, "Chand Miyan");
    strcpy(Book1.subject, "C++ Programming");
    Book1.book_id = 6495707;

    // Specs Book2
    strcpy(Book2.title, "Telecom BIlling");
    strcpy(Book2.author, "Yakit SIngha");
    strcpy(Book2.subject, "Telecom");
    Book2.book_id = 6495700;

    // strcpy almacena el string que se le pase en una posicion de memoria deseada

    // Imprimir Book1
    cout << "Titulo libro 1: " << Book1.title << endl;
    cout << "Autor libro 1: " << Book1.author << endl;
    cout << "Tema libro 1: " << Book1.subject << endl;
    cout << "ID libro 1: " << Book1.book_id << endl;

    // Imprimir Book2
    cout << "Titulo libro 2: " << Book2.title << endl;
    cout << "Autor libro 2: " << Book2.author << endl;
    cout << "Tema libro 2: " << Book2.subject << endl;
    cout << "ID libro 2: " << Book2.book_id << endl;

    // Instanciar una persona
    Person p1;
        cout << "INgresar nombre: ";
        cin.get(p1.name, 50);
        cout << "Ingrese la edad: ";
        cin >> p1.age;
        cout << "Ingrese salario: ";
        cin >> p1.salary;

    // IMprimir p1
    cout << "\nMostrando informacion de p1." << endl;
    cout << "Nombre: " << p1.name << endl;
    cout << "Edad: " << p1.age << endl;
    cout << "Salario: " << p1.salary << endl;
    return 0;
}
