// Programa de casting en C++
#include <iostream>
using namespace std;

int main() {
    // Se inicializan variables
    int num_i = 9;
    double num_d;
    num_d = num_i; // Conversion implicita
    cout << "num_i = " << num_i << endl;
    cout << "num_d = " << num_d << endl;
    
    // Hay dos formas de casting explicito
    double num_d2 = 3.56;
    cout << "num_d2 = " << num_d2 << endl;
    int num_i2 = (int) num_d2; // Forma #1
    cout << "num_i2 = " << num_i2 << endl;
    int num_i3 = int(num_d2); // Forma #2
    cout << "num_i3 = " << num_i3 << endl;
}