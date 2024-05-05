#include "Matrix.hpp"

template <class T>
Matrix<T>::Matrix(){
    cout << "Ingrese la cantidad de filas: ";
    cin >> this->rows;
    cout << "Ingrese la cantidad de columnas: ";
    cin >> this->cols;
    this->setDimensiones(this->rows, this->cols);
    this->fillMatrix();
    cout << "Matriz creada exitosamente!" << endl;
    this->display();
}
template Matrix<int>::Matrix();

template <class T>
Matrix<T>::~Matrix(){
    
}
template Matrix<int>::~Matrix();

template <class T>
void Matrix<T>::setDimensiones(int rows, int columns){
    if (rows <= 0 || columns <= 0){
        throw invalid_argument("Dimensiones invalidas, revise que no sea 0 o negativas.");
    }
}

template <class T>
void Matrix<T>::fillMatrix(){
    int num;
    vector<T> aux;
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            cout << "Ingrese el valor [" << i << "][" << j << "] de la matriz: ";
            cin >> num;
            aux.push_back(num);
        }
        this->data.push_back(aux);
        aux.clear();
    }
}

template <class T>
void Matrix<T>::display(){
    for (int i = 0; i < this->data.size(); i++) { 
        for (int j = 0; j < this->data[i].size(); j++) 
            cout << this->data[i][j] << " "; 
        cout << endl; 
    }
}