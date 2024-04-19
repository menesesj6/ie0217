#include <iostream>
#include <map>

using namespace std;

int main(){
    // Crear un mapa de tipo int y stuudent
    map<int, string> student;

    // Agregar elementos
    student[1] = "Jacqueline";
    student[2] = "Blake";

    // Usar insert para agregar
    student.insert(make_pair(3, "Denise"));
    student.insert(make_pair(4, "Blake"));

    // Elementos con el mismo key, se sobreescribe y queda el ultimo
    student[5] = "Timothy";
    student[5] = "Aaron";

    // Imprimir el map
    for(int i = 1; i <= student.size(); ++i){
        cout << "Student[" << i << "]: " << student[i] << endl;
    }

    return 0;
}