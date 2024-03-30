#include <iostream>
using namespace std;

// Crear clase
class Student{
    public:
        // Argumento publico
        double marks;

        // Constructor
        Student(double m){
            marks = m;
        }
};

// Funcion que recibe parametros de tipo Student (la clase)
void calculateAverage(Student s1, Student s2){
    // Accede a marks de cada student, pues es publico
    double average = (s1.marks + s2.marks) / 2;

    // Imprime el average
    cout << "Average marks: " << average << endl;
}

int main(){
    // INstanciar dos veces la clase Student con parametros
    Student student1(88.0), student2(56.0);

    // INvicar la funcion y usar las instanciaciones de parametros
    calculateAverage(student1, student2);

    return 0;
}