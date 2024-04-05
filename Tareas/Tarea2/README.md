# Tarea 2
## IE-0217: Estructuras Abstractas de Datos y Algoritmos para Ingeniería

Este instructivo para la compilación y ejecución de los archivos en esta carpeta está enfocado hacia una terminal _bash_ de Linux.  A continuación se exponen las formas de compilar y ejecutar por medio de un Makefile al igual que de forma manual por medio de la terminal, desde el directorio de **Tarea2**. Cabe destacar que este instructivo está pensado para abrir la documentación de Doxygen en FireFox.

## Instrucciones de compilación y ejecución: Juego Ahorcado
### Makefile
```
$ make AdminMundial # Ejecucion del juego
$ make doxygen # Despliegue documentacion Doxygen
``` 

### Forma general

```
$ 
$ 
``` 
### Documentacion en Netlify

Si no se deseara abrir la documentacion por línea de comandos, también se alojó el HTML producido por Doxygen en Netlify, en [este enlace.]()

## Parte teórica

### Investigación formato Markdown (.md)

El Markdown es un estilo de escritura que funciona para darle formato al texto simple. Por medio de reglas de sintaxis especificas es posible darle formato a cualquier texto, que puede ser escrito en prosa. Por lo general, este formato es usado para los README en los repertorios de Git, donde se incluyen aclaraciones del repertorio, informacion ectra e instrucciones de funcionamiento. 

### Preguntas

1. La POO (Programación Orientada a Objetos) es un tipo de programación donde el principal énfasis es en los datos y objetos que se deben manipular. Para esto, se cuentan con las estructuras conocidas como clases, que permiten al programador aplicar lógica a sus instanciaciones (objetos) para lograr lo deseado. Su 4 principios centrales son:
    - **Polimorfismo** 
    - **Herencia**
    - **Encapsulamiento**
    - **Abstracción**

2. El tema de ocultamiento de datos va de la mano con el encapsulamiento, mencionado previamente. Esto pues, al crear una clase, uno puede definir cuáles atributos y métodos serán privados, público so protegidos. Si se limita el acceso de esotos, se puede asegurar que no habrán modificaciones no deseadas ni accidentales en los miembros de una clase y sus respectivas instanciaciones.

3. La clase es el "molde" que define todos los atributos y métodos de ese tipo de dato. Por el otro lado, un objeto es una instanciación de una clase, donde tendrá un valor específico para cada argumento y podrá acceder a cada método de su clase madre. Por ejemplo, si se tiene una clase Vehículo, se pueden tener objetos llamados Carro, Bicicleta, Avión, etc.

4. El polimorfismo hace referencia a cuanod un método miembro de una clase se comporta distinto dependienod del objeto que la invoque. Esto se puede lograr por medio de la sobreescritura de métodos en la herencia, o bien, por el uso de funciones virtuales en la clase madre y sobreescribiéndola en clases derivadas.

5. El encapsulamiento en C++ va de la mano con el ocultamiento de miembros de una clase. Esto se logra al limitar el scope de los atributos de una clase a privados o protegidos, cosa que los deja inaccesibles para funciones y clases fuera de la misma de la que son parte. Es así como se logra el encapsulamiento de la información para evitar el acceso externo. 

6. Propósitos del constructor y el destructor:
    - **Constructor:** Este es el encargado de inicializar la instanciación cuando se invoque un objeto del tipo de la clase. Se encarga de todo lo ocurrido a la hora de crear un objteto, como asignar los atributos, sea a mano o por parámetros, imprimir un mensaje que confirme la instanciación, etc.
    - **Destructor:** Es el opuesto del constructor, se encarga de eliminar la instanciación de dicha clase una vez que se acabe el _scope_ donde fue llamado.

7. Las clases abstractas son aquellas que no pueden ser instanciadas en un objeto, ya que contienen una función virtual pura y poseen solo generalidades para ser aplicados en clases derivadas de esta. Sirven para hacer un "molde" muy general y que clases más concretas hagan provecho d eus herencia y sobreescriban sus funciones virtuales.

8. Los constructores de copia es un constructor que permite inicializar un objeto con los valores de otro objeto del mismo tipo. El compilador tiene constructores de copia incluidos pero para inicializaciones sencillas, si se ocupa algo más complejo, sí se debe definir la funcion a mano en la clase.

9. Diferencia entre tipos de polimorfismo:
    - **Estático:** Este funciona con _early binding_, lo que significa qu ela memoria reservada para el polimorfismo es asignada durante la compilación; y es dado más que nada por la sobrecarga de los métodos, sobrecarga de operadores, etc.
    - **Dinámico:** Este funciona con _late binding_, lo que significa que la memoria que se le asignará al polimorfismo es asignada durante el tiempo de ejecución, de manera dinámica; y esto es dado por las funciones virtuales en la clase base, que son sobreescritos en sus clases derivadas respectivas.

10. Las clase sanidadas son clases que se definen y funcionan dentro del scope de otra clase. Esta clase no cuenta con características especiales de acceso, pues sigue las mismas reglas de acceso.

11. Los punteros en la POO son útiles para el acceso a los miembros (atributos o métodos) de una instanciación de una clase. Por ejemplo, emplear el puntero _this_ para la definición de los métodos miembro de la clase, para manioular directamente los atributos en memoria y qu ese cambie la instanciación. De la misma forma, si se deseara pasar un objeto como parámetro a una función para modificar sus atributos, s epuede pasar un puntero del tipo de la clase y de esta forma se usa el operador **->** para acceder, modificar y demás sus miembros.

12. El prototipo de una función es la declaración de la misma antes de definirla, donde se define su nombre, tipo y sus parámetros con sus tipos respectivos. De esta forma, el compilador ya sabe que esta función existe, aunque esta se defina despues de la función main. Esto es útil para lso _header files_ del programa, pues en el header se declaran los prototipos y en el archivo fuente, se deifnen.

13. Tipos de miembros de clase:
    - **Propiedades o campos:** Son las variables, representan la información que compone  aun objeto, tienen procedimientos de _get_ y de _set_, por lo general
    - **Métodos:** Acciones qu eel objeto puede realizar.
    - **Constructores:** Inicializan la instanciación de la clase. Es lo primero que se ejecuta al momento que se crea un objeto.
    - **Destructores:** Destruyen el objeto una vez qu eel scope donde se deifnió termina.
    - **Eventos:** Cuando algo ocurre, se le informa de esto a otras clases y objetos por meido de la habilitación de una clase u objeto. Lo qu einicia el evento es llamado publicador y quienes lo reciben son suscriptores.
    - **Clases anidadas:** Una clase definida dentro de otra clase

14. Los _memory leaks_ son problemas que ocurren a la hora de trabajar con lenguajes de programación con manejo manual de la memoria, como lo son C y C++ cuando se trabaja con memoria dinámica. Esto ocurre cuando no se desocupa de manera correcta la memoria empleada que ya no se necesita, por lo que un programa empieza a abarcar más memoria de la que en serio necesita, ocupando grandes cantidades de RAM, ocasionando una caída de rendimiento y, eventualmente, el cierre total del progrm o el agotameinto de los recursos.

15. Las herencias en C++ es cuando se toma una clase base y se crea otra clase, tomando como punto de inicio la primera base. Es decir, si se tiene una claseA y una claseB que hereda de A, claseB tendrá todo lo de A más lo que uno le añada, ya sea métodos o atributos. La gran ventaja de la herencia es que permite "reciclar código" y así no tener que definir varias veces lógicas iguales o comportamientos similares. Los tipos de herencia son Jerárquica, Multinivel y Múltiple. La primera es cuando una sola clase base le hereda a varias clases derivadas. Luego, la multinivel es cuando se lleva una escaler de herencias, como que se tenga claseA como la base y claseB hereda de claseA y claseC hereda de claseB. Por último, la múltiple es cuando una sola clase derivada hereda de varias clases madre.

16. La composición es cuando un objeto es construido por la unión de otros objetos. Esto se logra al definir un miembro de una clase como un dato o método del tipo de otra clase; de esta forma, una clase se compone de instanciaciones de otra clase. 

17. 
18. 
19. 
20.  
