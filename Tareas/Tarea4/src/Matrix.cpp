#include "Matrix.hpp"

template <class T>
Matrix<T>::Matrix(int r, int c) : rows(r), cols(c){
    try{
        // EStablecer las caracteristicas de la matriz y verificar
        this->setDimensiones(this->rows, this->cols);
        // Imprimir la matriz
        cout << "\nMatriz creada exitosamente!" << endl;
    }
    catch (const exception& e){
        cerr << e.what() << endl;
        exit(0);
    }
    
}
// Arreglar linking problems
template Matrix<int>::Matrix(int r, int c);
template Matrix<float>::Matrix(int r, int c);
//template Matrix<complex>::Matrix();

template <class T>
Matrix<T>::~Matrix(){
    
}
template Matrix<int>::~Matrix();

template <class T>
void Matrix<T>::setDimensiones(int rows, int columns){
    this->rows = rows;
    this->cols = columns;
    // Inicializar la matriz en cero
    vector<T> init (this->cols, 0);
    for(int i = 0; i < this->rows; i++){
        this->data.push_back(init);
    }
    this->checker.validateDimensions(rows, columns);
}

template <class T>
void Matrix<T>::fillMatrix(){
    string num;
    vector<T> aux;
    this->data.clear();
    try{
        for(int i = 0; i < this->rows; i++){
            for(int j = 0; j < this->cols; j++){
                cout << "Ingrese el valor [" << i << "][" << j << "] de la matriz: ";
                cin >> num;
                this->checker.validateData(num);
            }
            this->data.push_back(aux);
            aux.clear();
        }
    }
    catch (const exception& e){
        cerr << e.what() << endl;
        exit(0);
    }
    
}
template void Matrix<int>::fillMatrix();
template void Matrix<float>::fillMatrix();

template <class T>
void Matrix<T>::display(){
    for (int i = 0; i < this->data.size(); i++) { 
        for (int j = 0; j < this->data[i].size(); j++) 
            cout << this->data[i][j] << " "; 
        cout << endl; 
    }
}

template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other){
    vector<T> aux;
    Matrix<T> result(this->rows, this->cols);
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            aux.push_back(this->data[i][j]+other.data[i][j]);
        }
        result.data.push_back(aux);
        aux.clear();
    }
    result.display();
    return result;
}
template Matrix<int> Matrix<int>::operator+(const Matrix<int>& other);
template Matrix<float>  Matrix<float>::operator+(const Matrix<float>& other);

template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& other){
    vector<T> aux;
    Matrix<T> result(this->rows, this->cols);
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            aux.push_back(this->data[i][j] - other.data[i][j]);
        }
        result.data.push_back(aux);
        aux.clear();
    }
    result.display();
    return result;
}
template Matrix<int> Matrix<int>::operator-(const Matrix<int>& other);
template Matrix<float>  Matrix<float>::operator-(const Matrix<float>& other);

