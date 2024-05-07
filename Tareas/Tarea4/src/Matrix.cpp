#include "Matrix.hpp"

template <class T>
Matrix<T>::Matrix(int r, int c) : rows(r), cols(c){
    try{
        // EStablecer las caracteristicas de la matriz y verificar
        this->setDimensiones(r, c);
    }
    // Capturar y manejar excepcion de dimensiones invalidas, si fuera necesario
    catch (const exception& e){
        cerr << e.what() << endl;
        exit(0);
    }
    
}


template <class T>
Matrix<T>::~Matrix(){}

template <class T>
void Matrix<T>::setDimensiones(int rows, int columns){
    // Asignar los atributos de dimension de la matriz
    this->rows = rows;
    this->cols = columns;
    // Validar dimensiones
    this->checker.validateDimensions(rows, columns);
    // Inicializar la matriz en cero
    vector<T> init (this->cols, 0);
    for(int i = 0; i < this->rows; i++){
        this->data.push_back(init);
    }
}


template <class T>
void Matrix<T>::fillMatrix(){
    // Input como string para despues convertirlo
    string num;
    // NUevo elemento del tipo T, depende de la matriz
    T newel;
    // Vector donde se cargan lso nuevos valores y luego se carga a la matriz
    vector<T> aux;
    // Limpiar los valores que esten
    this->data.clear();
    try{
        // Iterar la matriz para asignar valores
        for(int i = 0; i < this->rows; i++){
            for(int j = 0; j < this->cols; j++){
                // Solicitar elementos
                cout << "Ingrese el valor [" << i << "][" << j << "] de la matriz: ";
                cin >> num;
                // Verificar cada elemento
                this->checker.validateData(num);
                // Procesar el string y castearlo
                istringstream ss(num);
                ss >> newel;
                // Agregar a vector auiliar
                aux.push_back(newel);
            }
            // Agregar vector auxiliar a la matriz
            this->data.push_back(aux);
            // LImpiar el vector auxiliar
            aux.clear();
        }
    }
    // Capturar y manejar excepcion por tipo de dato erroneo, de ser necesario
    catch (const exception& e){
        cerr << e.what() << endl;
        exit(0);
    }
   
}


template <class T>
void Matrix<T>::randomFillMatrix(){
    // Caso de ints
    if(typeid(T) == typeid(int)){
        // Vector auxiliar para agregar datos
    vector<T> aux; 
        // Mecanismo de int aleatorios no deterministicos
        random_device rd;
        // Obtener un numero en [-100, 100] de una distribucion uniforme de ints
        uniform_int_distribution<int> dis(-100, 100);
        // Limpiar la matriz
        this->data.clear();
        // Iterar la matriz
        for(int i = 0; i < this->rows; i++){
            for(int j = 0; j < this->cols; j++){
                // Obtener el nuevo elemento aleatoria usando el random engine
                T newel = dis(rd);
                // INgresar el valor random al vector auxiliar
                aux.push_back(newel);
            }
            // AGregar vector auxiliar a la matriz
            this->data.push_back(aux);
            // Limpiar el vector auxiliar
            aux.clear();
        }
    }  
    // Caso de floats
    else if (typeid(T) == typeid(float)){
        // Vector auxiliar para agregar datos
    vector<T> aux; 
        // Mecanismo de floats aleatorios no deterministicos
        random_device rd;
        // Obtener un numero en [-100, 100] de una distribucion uniforme de floats
        uniform_real_distribution<float> dis(-100, 100);
        // Limpiar la matriz
        this->data.clear();
        // Iterar la matriz
        for(int i = 0; i < this->rows; i++){
            for(int j = 0; j < this->cols; j++){
                // Obtener el nuevo elemento aleatorio usando el random engine
                T newel = dis(rd);
                // Ingresar el valor random al vector auxiliar
                aux.push_back(newel);
            }
            // Agregar vector auxiliar a la matriz
            this->data.push_back(aux);
            // Limpiar el vector auxiliar
            aux.clear();
        }
    }
    // Caso de complex
    else if (typeid(T) == typeid(complex<float>)){
        // Vector auxiliar para agregar datos
        vector<T> aux; 
        // Mecanismo de floats aleatorios no deterministicos
        random_device rd;
        // Obtener un numero en [-100, 100] de una distribucion uniforme de floats
        uniform_real_distribution<float> dis(-100, 100);
        // Componentes aleatorios
        float compR, compI;
        // Iterar la matriz
        for(int i = 0; i < this->rows; i++){
            for(int j = 0; j < this->cols; j++){
                compR = dis(rd);
                compI = dis(rd);
                // this->data[i][j] = complex<float> (compR, compI);
            }
        }
    }
};


template <class T>
void Matrix<T>::display(){
    // Iterar la matriz e imprimir sus valores
    for (int i = 0; i < this->data.size(); i++) { 
        for (int j = 0; j < this->data[i].size(); j++) 
            cout << this->data[i][j] << "  "; 
        cout << endl; 
    }
}


template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other){
    // Vector auxiliar para agregar datos
    vector<T> aux;
    // Instanciar la matriz resultado con las dimensiones correctas
    Matrix<T> result(this->rows, this->cols);
    // Limpiar la matriz
    result.data.clear();
    // Iterar las matriz argumentos
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            // INgresar suma de los dos elementos [i][j] en el vector auxiliar
            aux.push_back(this->data[i][j]+other.data[i][j]);
        }
        // Agregar el vector auxiliar a la matriz resultado 
        result.data.push_back(aux);
        // LImpiar el vector auxiliar
        aux.clear();
    }
    // IMprimir el resultado
    result.display();
    // Retornar la matriz resultado
    return result;
}


template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& other){
    // Vector auxiliar para agregar datos
    vector<T> aux;
    // Instanciar la matriz resultado con las dimensiones correctas
    Matrix<T> result(this->rows, this->cols);
    // Limpiar la matriz
    result.data.clear();
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            // Ingresar resta de los dos elementos [i][j] en el vector auxiliar
            aux.push_back(this->data[i][j] - other.data[i][j]);
        }
        // Agregar el vector auxiliar a la matriz resultado 
        result.data.push_back(aux);
        // Limpiar el vector auxiliar
        aux.clear();
    }
    // Imprimir el resultado
    result.display();
    // Retornar la matriz resultado
    return result;
}

template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other){
    // Vector auxiliar para agregar datos
    vector<T> aux;
    // Instanciar la matriz resultado con las dimensiones correctas
    Matrix<T> result(this->rows, other.cols);
    // Iterar las columnas de la primer matriz
    for (int i = 0; i < this->data.size(); i++){
        // Iterar las columnas de la segunda matriz
        for (int j = 0; j < other.data.size(); j++){
            // Iterar las columnas de la primera matriz de nuevo
            for (int k = 0; k < this->data.size();k++)
                // Ir sumando al elemento [i][j] del resultado la multiplicacion de los elementos [i][j] y [j][i]
                result.data[i][j] += this->data[i][k] * other.data[k][j];
        }
    }
    // Retornar la matriz resultado
    return result;
}

// Solucion linking problems
template Matrix<int>::Matrix(int r, int c);
template Matrix<float>::Matrix(int r, int c);
template Matrix<complex<float>>::Matrix(int r, int c);
//template Matrix<complex<int>>::Matrix(int r, int c);

template Matrix<int>::~Matrix();
template Matrix<float>::~Matrix();
template Matrix<complex<float>>::~Matrix();
//template Matrix<complex<int>>::~Matrix();

template void Matrix<int>::fillMatrix();
template void Matrix<float>::fillMatrix();
template void Matrix<complex<float>>::fillMatrix();
//template void Matrix<complex<int>>::fillMatrix();


template void Matrix<int>::randomFillMatrix();
template void Matrix<float>::randomFillMatrix();
template void Matrix<complex<float>>::randomFillMatrix();
//template void Matrix<complex<int>>::randomFillMatrix();

template void Matrix<int>::display();
template void Matrix<float>::display();
template void Matrix<complex<float>>::display();
//template void Matrix<complex<int>>::display();

template Matrix<int> Matrix<int>::operator+(const Matrix<int>& other);
template Matrix<float> Matrix<float>::operator+(const Matrix<float>& other);
template Matrix<complex<float>> Matrix<complex<float>>::operator+(const Matrix<complex<float>>& other);
//template Matrix<complex<int>> Matrix<complex<int>>::operator+(const Matrix<complex<int>>& other);

template Matrix<int> Matrix<int>::operator-(const Matrix<int>& other);
template Matrix<float>  Matrix<float>::operator-(const Matrix<float>& other);
template Matrix<complex<float>> Matrix<complex<float>>::operator-(const Matrix<complex<float>>& other);
//template Matrix<complex<int>> Matrix<complex<int>>::operator-(const Matrix<complex<int>>& other);

template Matrix<int> Matrix<int>::operator*(const Matrix<int>& other);
template Matrix<float>  Matrix<float>::operator*(const Matrix<float>& other);
template Matrix<complex<float>> Matrix<complex<float>>::operator*(const Matrix<complex<float>>& other);
//template Matrix<complex<int>> Matrix<complex<int>>::operator+(const Matrix<complex<int>>& other);


