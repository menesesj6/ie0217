# Tarea 4
## IE-0217: Estructuras Abstractas de Datos y Algoritmos para Ingeniería

Este instructivo para la compilación y ejecución de los archivos en esta carpeta está enfocado hacia una terminal _bash_ de Linux.  A continuación se exponen las formas de compilar y ejecutar por medio de un Makefile al igual que de forma manual por medio de la terminal, desde el directorio de **Tareas/Tarea3**. Cabe destacar que este instructivo está pensado para abrir la documentación de Doxygen en FireFox.

- Cabe destacar que es recomendable ejecutar por medio de Makefile, dada la gran cantidad de archivos .cpp

## Instrucciones de compilación y ejecución: Calculadora de matrices
### Makefile
```
$ make matrix # Ejecucion del programa
$ make doxygen # Despliegue documentacion Doxygen
``` 

### Forma general

```
$ g++  -o Exe.exe
$ ./Exe.exe
``` 
### Documentacion en Netlify

Si no se deseara abrir la documentacion por línea de comandos, también se alojó el HTML producido por Doxygen en Netlify, en [este enlace.]()

## Parte teórica

### Investigación formato Markdown (.md)

El Markdown es un estilo de escritura que funciona para darle formato al texto simple. Por medio de reglas de sintaxis especificas es posible darle formato a cualquier texto, que puede ser escrito en prosa. Por lo general, este formato es usado para los README en los repertorios de Git, donde se incluyen aclaraciones del repertorio, informacion ectra e instrucciones de funcionamiento. 

### Preguntas

1. ***Templates***
    1. Definición de _templates_:
    
    Los _templates_ son estructuras sumamente útiles en la programación de C++, pues permiten pasar el tipo de datos como un parámetro para así no escribir varias veces la msima función o clase para los distintos tipos de dato. Por ejemplo, la función add a continuación obtendrá un parámetro T que es el tipo de dato manejado por la función.

    ```
    template <typename T>
    T add(T num1, T num2){
        return num1 + num2
    }
    ```

    2. Sobrecarga de plantillas:
    
    Los _function templates_ pueden ser sobrecargados ya sea por otro _function templates_ o por una función ordinaria. Esta sobrecarga funciona de la misma manera que sobrecargar funciones, donde se diferencia por los parámetros. Ahora bien, si es un poco más ambiguo si existen dos _function templates_ con dos argumentos, pero puede ser que uno tenga dos _typenames_ y el otro tenga solo uno; donde se generaría una diferencia para identificar cuál invocar. También, la cantidad de parámetros juega un papel importante, pues eso también definiría cuál invocar. Por ejemplo, todas las funciones a continuación serían distinguibles.
    ```
    template <typename T> add(T num1, T num2);
    template <typename T, typename U> add (T num1. U num2);
    template <typename T> add (T num1, T num2, T num3); 
    ```
    
    3. Plantillas de clases:
    
    Los _class templates_ funcionan similar a los _function templates_, pues permiten parametrizar los tipos de datos que posee, ya sea el tipo de datos de atributos, los retornos de los métodos, los parámetros a los métodos, etc. Si bien crear una clase es crear un tipo de objeto, al hacer una plantilla permite manipular más eficientemente los tipos de datos que emplea internamente y así reciclar el código para variar esos tipos de datos.
    
2. ***Excepciones***

    1. Manejo de excepciones:
    
    
    2. Excepciones estándar:
    
    3. Política de manejo de excepciones:
    
    4. Noexcept:
    
    5. std::logic_error vs. std::runtime_error
    
    6. ¿Qué pasa si no se captura una ecepción?

3. ***STL***
    
    1. Contenedore STL
    2. Iteradores STL
    3. Algoritmos STL
    4. Algoritmos personalizados
