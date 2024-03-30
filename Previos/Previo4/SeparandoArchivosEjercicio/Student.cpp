#include <iostream>
#include "Header.hpp" // Importar archivo con prototipo y clase
using namespace std;

// Definir funcion
void calculateAverage(Student s1, Student s2){
    double average = (s1.marks + s2.marks) / 2;
    cout << "Average Marks = " << average << endl;
}

// Definir constructor de la clase
Student::Student(double m){
    marks = m;
}