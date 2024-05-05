#include "Matrix.hpp"

int main(){
    try{
        Matrix<int> m1;
    } catch(invalid_argument){
        cout << "Ha habido un error de dimensiones!" << endl;
    }

    return 0;
}