#include "Matrix.hpp"

int main(){
    try{
        Matrix<int> m1(2, 2);
        m1.setDimensiones(2, 2);
        m1.fillMatrix();
        Matrix<int> m2(2, 2);
        m2.setDimensiones(2, 2);
        m2.fillMatrix();
        Matrix<int> m3 = m1 - m2;
    } 
    
    catch(invalid_argument){
        cout << "Ha ingresado un dato de tipo distinto!" << endl;
    }

    catch(runtime_error){
        cout << "Ha ingresado dimensiones invalidas" << endl;
    }

    return 0;
}