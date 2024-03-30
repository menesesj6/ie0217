#include <iostream>
using namespace std;

class Animal{
    // Parte publica, accesible por esta clase, las derivadas y externas
    public:
        // Definir metodos publicos
        void setEdad(int age){
            edad = age;
        }

        int getEdad(){
            return edad;
        }

    // Parte protegida, accesible por esta clase, clases derivadas pero no por clases externas
    protected:
        string nombre;

    // Parte privasa, unicamente accesible por esta clase
    private:
        int edad;
};

// Definir clase perro por herencia de Animal. Perro es derivada de Animal
class Perro : public Animal{
    public:
        // Metodos publicos
        void setNombre(string n){
            nombre = n;
        }
        string getNombre(){
            return nombre;
        }
};

int main() {
    // SE instancia la clase Perro
    Perro miPerro;

    // Se usan los metodos
    miPerro.setNombre("Toby");
    miPerro.setEdad(3);

    cout << "Mi perro se llama " << miPerro.getNombre() << endl;
    cout << "y tiene " << miPerro.getEdad() << " anios." << endl;
    return 0;
}