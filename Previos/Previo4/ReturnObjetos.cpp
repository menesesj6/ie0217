#include <iostream>
using namespace std;

// Crear clase
class Student{
    public:
        // Argumentos publicos
        double marks1, marks2;
};

// Funcion que retorna un objeto
Student createStudent() {
    // Instanciar la clase
    Student student;

    // Asignar atributos
    student.marks1 = 96.5;
    student.marks2 = 75.0;

    cout << "Marks 1: " << student.marks1 << endl;
    cout << "Marks 2: " << student.marks2 << endl;

    // Retornar objeto
    return student;
}

int main(){
    // Instanciar la clase Student
    Student student1;

    // Invocar la funcion que retorna un objeto
    student1 = createStudent();

    return 0;
}