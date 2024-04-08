#include <iostream>
using namespace std;

class Student{
    private:
        int age;
    public:
        // Constructor
        Student() : age(12) {};
        // Metodo publico
        void getAge() {
            cout << "Age = " << age << endl;
        }
};

int main() {
    // Almacenar un objeto en el heap
    Student* ptr = new Student();

    // Obtener edad
    ptr->getAge();

    // Liberar memoria
    delete ptr;
    return 0;
}