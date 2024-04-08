#include <iostream>
using namespace std;

int main(){
    int* pointVar;
    pointVar = new int;
    *pointVar = 45;
    cout << *pointVar;
    delete pointVar;
}