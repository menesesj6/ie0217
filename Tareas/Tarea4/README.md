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
    
        - try: 
        Este representa un bloque de codigo que se pide que se intente ejecutar, pero que es probable que existan excepciones y errores. Entonces, dentro de este se ejecuta el programa, pero se codifica una forma de detectar errores y asi obtener excepciones.
        - throw: 
        Este bloque de codigo es el encargado de cuando exista un error que genere una excepcion de cualquier tipo, la avisa. Es decir, este levanta las alarmas de la existencia de un error que genera una excepcion, pero este no la procesa.
        - catch: 
        Este bloque va de la mano con el throw, pues es el bloque catch es el encargado de manejar las excepciones. Es decir, este se encarga de imprimir la excepcion, alertar de la misma, realizar alguna accion especifica, etc.
    
    2. Excepciones estándar:
    Estas estan definidas en la libreria ```stdexcept``` . Tres de las conocidas son las siguientes:
        - invalid_argument:
        Alerta de un argumento invalido. Un ejemplo puede ser que se tenga una funcion de operaciones aritmeticas que desea solo operar para numeros positivos, por lo que si se le pasa un numero negativo, se levantaria esta excepcion.
        - runtime_error:
        Alerta de casos erroneos y condiciones solo detectables en tiempo de ejecucion. UN ejemplo muy comun de este es el caso de division por cero.
        - out_of_range:
        Alerta cuando hay argumentos fuera de rango. Un ejemplo es cuando se esta trabajndo con un vector de tamano N y e intenta acceder a su indice N+5. ESto lanzara esta excepcion ya que el vector no posee ese rango.
    
    3. Política de manejo de excepciones:
        Estas politicas de manejo de excepciones a la hora de disenar software consiste en el set de reglas y lo considerado como buenas practicas para manejar las excepciones. La importancia de esto es poder crear un programa robusto, funcional y mantenible en el tiempo.

    4. Noexcept:
        Este operador de C++11 es un operador que actua en el tiempo de compilacion y se encarga de asegurar que una funcion no tire funciones. Su sintaxis es escribiendo el operador despues de la lista de parametros y antes de la definicion de la funcion, como se muestra:
        ```
        void func() noexcept {
            // Codigo de funcion
        }
        ``` 
    
    5. std::logic_error vs. std::runtime_error
    Los erroes logicos son dados por inspeccion y hacen referencia a errores en la logica de la programacion, como argumentos invalidos, fuera de rango, etc. Estos pueden, en teoria, ser detectados leyendo el codigo. Por otro lado, los errores en tiempo de ejecucion son aquellos que, teoricamente, no pueden ser detectados al leer el codigo y son detectables unicamente a la hora de compilar y ejecutar.
    
    6. ¿Qué pasa si no se captura una excepción?
    Si se lanza una excepcion y esta no es atrapada y manejada por un bloque catch, el programa se terminaria con un error. Esto porque si se alerta que hubo un error y en el _call stack_ no se encuentra un bloque _catch_ que pueda manejar dicha excepcion, se obtendra un error en el programa y se mata el proceso.

3. ***STL***
    
    1. Contenedore STL
    2. Iteradores STL
    3. Algoritmos STL
    4. Algoritmos personalizados
