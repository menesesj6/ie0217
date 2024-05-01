#include <iostream>
using namespace std;

// Crear molde de clase
template <class T>
class Number {
    private:
        // SU tipo sera definido cuando se instancie el template
        T num;
    public:
        // Constructor
        Number(T n) : num(n) {}

        // Metodo cuyo return type depende de la instanciacion del template
        T getNum() {
            return num;
        }
};

int main(){
    // Instanciar las clases para int y doubles
    Number<int> numberInt(7);
    Number<double> numberDouble(7.7);

    // Imprimir resultados
    cout << "int Number = " << numberInt.getNum() << endl;
    cout << "double Number = " << numberDouble.getNum() << endl;

    return 0;
}