#include "Header.hpp" // IMportar header con prototipo y clase

int main (){
    // Instanciar clase
    Student student1(88.0), student2(56.0);
    
    // Invocar funcion
    calculateAverage(student1, student2);

    return 0;
}