#include <iostream>
using namespace std;

int main() {
    // Definir cantidad de estudiantes
    int num;
    cout << "Enter total numbe rof students: ";
    cin >> num;
    float* ptr; // Definir punteros

    // Array dinamico de floats
    ptr =new float[num];

    // Ingresar GPAs
    cout << "Enter GPA of students." << endl;
    for(int i = 0; i < num; i++){
        cout << "Student " << i + 1 << ": ";
        cin >> *(ptr + i); // Aritmetica de punteros
    }

    // Imprimir GPA
    cout << "\nDisplaying GPA of students." << endl;
    for(int i = 0; i < num; i++){
        cout << "Student " << i + 1 << ": " << *(ptr + i) << endl; 
    }

    // Liberar espacio de memoria del array
    delete[] ptr;

    return 0;
}