#ifndef HEADER_H // Define condicional
#define HEADER_H

// Se define la clase
class Student{
    public:
        double marks;   
        Student(double m);
};

// Prototipo de funcion
void calculateAverage(Student s1, Student s2);

#endif