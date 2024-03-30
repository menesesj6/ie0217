#include <iostream>
using namespace std;

class MyClass {
    private:
        int member1;
};

int main(){
    MyClass obj;
    obj.member1 = 5; // Error, member1 es inaccesible desde fuera de la clase
}