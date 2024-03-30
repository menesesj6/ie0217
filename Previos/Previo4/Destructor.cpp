#include <iostream>
#include <fstream>

class Archivo {
    private:
        std::fstream archivo; // Se usara fstream para secuencias io de archivos externos

    public:
        // Constructor, abre el archivo
        Archivo(std::string nombre_archivo){
            archivo.open(nombre_archivo, std::ios::in | std::ios::out | std::ios::app);
            if(!archivo.is_open()){
                std::cout << "No se pudo abrir el archivo " << nombre_archivo << std::endl;
            }
        }

        // Cierra el archivo cuando haga falta
        ~Archivo(){
            if(archivo.is_open()) {
                archivo.close();
            }
        }
};

int main(){
    // Instanciar la clase
    Archivo mi_archivo("datos.txt");

    // Hacer algo con el archivo

    return 0;
}