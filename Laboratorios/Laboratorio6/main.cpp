#include<iostream>
#include<vector>
#include<cmath>
#include<stdexcept>

// Crear class template
template <typename T>
class Statistics{
    public:
        // Constructor parametrizado
        Statistics(const std::vector<T>& data) : data(data){
            // Tirar excepcion si el vector esta vacio
            if(data.empty()){
                throw std::invalid_argument("La lista de datos debe contener elementos");
            }
        }

        // Metodos, se pone 'const' porque no afectan los aributos de la clase
        // Calcular el promedio de los datos
        double mean() const{
            // Inicializar una variable de suma de los datos
            T sum = 0;
            // Iterar el vector y obtener la suma de todos sus elementos
            for(const T& value : data){
                // Sumar cada elemento
                sum += value;
            }
            // Retornar el promedio usando esa suma y el tamano del vector
            return static_cast<double>(sum) / data.size();
        }

        // Calcular desviacion estandar
        double standardDeviation() const{
            // Inicializar variables utiles
            double meanValue = mean();
            double sumSquares = 0;

            // Obtener la suma de los cuadrados de la diferencia de cada valor respecto al promedio
            for(const T& value : data){
                sumSquares += (value - meanValue) * (value - meanValue);
            }
            // Retornar desviacion estandar
            return std::sqrt(sumSquares / data.size());
        }

    private:
        // Datos de la clase
        std::vector<T> data;
};

int main(){
    try{
        /***********Prueba de ints***********/

        // Crear vector de ints
        std::vector<int> intData = {1, 2, 3, 4, 5};
        // Crear clase de analisis de ints
        Statistics<int> statsInt(intData);
        // Imprimir resultados
        std::cout << "Media de intData: " << statsInt.mean() << std::endl;
        std::cout << "Desviacion estandar de intData: " << statsInt.standardDeviation() << std::endl;

        /*********Prueba de doubles*********/

        // Crear vector de doubles
        std::vector<double> doubleData = {1.5, 2.5, 3.5, 4.5, 5.5};
        // Crear clase de analisis de doubles
        Statistics<double> statsDouble(doubleData);
        // Imprimir resultados
        std::cout << "Media de doubleData: " << statsDouble.mean() << std::endl;
        std::cout << "Desviacion estandar de doubleData: " << statsDouble.standardDeviation() << std::endl;
        
        /******Prueba de vector vacio******/
        std::vector<int>empyData;
        Statistics<int> statsEmpty(empyData);

    } // Manejar la excepcion de argumento invalido tirada por vector vacio
    catch(const std::invalid_argument& e){
        std::cerr << "Excepcion encontrada: " << e.what() <<std::endl;
    }
    
    return 0;
}