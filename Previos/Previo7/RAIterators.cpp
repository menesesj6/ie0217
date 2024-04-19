#include <iostream>
#include <vector>

using namespace std;

int main(){
    // Crear vector
    vector<int> vec{1,2,3,4,5};
    // DEfinir dos iteradores de vectores
    vector<int>::iterator itr_first = vec.begin();
    vector<int>::iterator itr_last = vec.end() - 1;

    // Imprimir elementos
    cout << "First element: " << *itr_first << endl;
    cout << "SEcond element: " << itr_first[1] << endl;

    cout << "Second last element: " << *(itr_last - 1) << endl;
    cout << "Last element: " << *itr_first << endl;

    return 0;
}
