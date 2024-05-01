#include <iostream>
using namespace std;

// Function template con dos parametros de tipo
template <typename T, typename U>
T multiply(T a, U b){ // Parametros de tipo distinto
    return a * b;
}

// Class template con un parametro predeterminado, es opcional ponerlo al instanciar
template<class T, class U, class V = char>
class classTemplate {
    private:
        // Atributos todos de tipos distintos
        T var1;
        U var2;
        V var3;
    public:
        // Constructor parametrizado
        classTemplate(T v1, U v2, V v3) : var1(v1), var2(v2), var3(v3) {}

        // Metodo de imprimir atributos
        void printVar(){
            cout << "var1 = " << var1 << endl;
            cout << "var2 = " << var2 << endl;
            cout << "var3 = " << var3 << endl; 
        }
};

int main(){
    // Instanciar haciendo provecho del tipo predefinido
    classTemplate<int, double> obj1(7, 7.7, 'c');
    cout << "obj1 values: " << endl;
    obj1.printVar();

    // Instanciar cambiando todos los tipos
    classTemplate<double, char, bool> obj2(8.8, 'a',false);
    cout << "obj2 values: " << endl;
    obj2.printVar();

    // Probando funcion con varios parametros
    cout << "Testing multiply function..." << endl;
    double res = multiply<double, int>(8.93, 9);
    cout << "8.93 * 9 = " << res << endl;

    return 0;
}