# Tarea 3
## IE-0217: Estructuras Abstractas de Datos y Algoritmos para Ingeniería

Este instructivo para la compilación y ejecución de los archivos en esta carpeta está enfocado hacia una terminal _bash_ de Linux.  A continuación se exponen las formas de compilar y ejecutar por medio de un Makefile al igual que de forma manual por medio de la terminal, desde el directorio de **Tareas/Tarea3**. Cabe destacar que este instructivo está pensado para abrir la documentación de Doxygen en FireFox.

- Cabe destacar que es recomendable ejecutar por medio de Makefile, dada la gran cantidad de archivos .cpp

## Instrucciones de compilación y ejecución: Gestion de contactos
### Makefile
```
$ make contactos # Ejecucion del programa
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

1. Un algoritmo es un conjunot de instrucciones que pemriten solucionar un problema. Esta serie de pasos o instrucciones debe cumplir ocn 3 caracteristicas esenciales, que son el ser secuenciales, completos y finitos; aunado al hecho que deben ser lo mas rapidos y eficientes posibles.

2.  Algoritmo eficiente vs. algoritmo ineficiente:
    - **Eficiente:** 
        - Tienen un tiempo de ejecucion rapido o razonable sin importar si son tareas robustas. EN terminos de la Big O, tienden a ser O(log n), O(1), O(n) u O(n log n).
        - Ocupan la menor cantidad de recursos y los usan de manera optimizada.
        - NO les afecta el aumento de las entradas y sus tamanos.
        - Se basan en la optimizacion de la solucion al emplear estructuras de datos y tecnicas para lograr esto.
    - **Ineficiente:**
        - Tienen un tiempo de ejecucion lento qu eaumenta incluso mas dependiendo del tamano de las tareas y los datos. EN Big O pueden ser O(n^2) u O(2^n).
        - Hacen uso de demasiados recursos y pueden lentizar el proceso o incluso generar bloqueos.
        - SI les afecta el aumento de las entradas y sus tamanos.
        - NO son basados en la optimizacion pues podrian usar estructuras u operaciones qu eno colaboran y solo aumentan el tiempo de ejecucion.
3. Las estructuras de datos son tecnicas por medio de las cuales se manejan grandes cantidades de informacion. Estas son esenciales para la optimizacion de soluciones de problemas, pues ayudan a que el manejo de la misma informacionn sea mucho mas eficiente.

4. La diferencia entre estructuras de datos estaticas y dinamicas es en torno al espacio ocupado en memoria por la misma. La estatica, se le debe especificar su tamano antes de la compilacion y la ejecucion; mientras que las dinamicas su tamano puede ser redefinido en tiempo de ejecucion de acuerdo  alo necesario. 
5. La memoria dinámica es la característica de lenguajes de programación como C o C++ donde el tamaño del espacio en memoria que ocnsume algo puede ser definido con tiempo de ejecución. Para la gestión de esto, se tienen comandos como lo son ***new***, ***malloc***, ***calloc*** o ***realloc***, con los que se deifne el tamaño del espacio de memoria a reservar y otros comandos como ***delete*** o ***free*** que sirven para liberar esa memoria y evitar _memory leaks_. Respecto a los primeros, ***new*** asigna memoria a una variable específica; ***malloc*** sirve para reservar un bloque de memoria en el heap, ***calloc*** permite reservar un bloque de memoria en el heap e inicializarlo a cero; y ***realloc*** se encarga de redimensionar un bloque de memoria del heap. Por otro lado, ***fre*** libera la memoria reservada con malloc, calloc y realloc, mientras que ***delete*** libera la memoria reservada con new.

6. La mayor ventaja de la memoria dinámica es que permite trabajar con datos cambiantes y que el programa se adapte en tiempo de ejecución, sin tener que hardcodear para tamaños distintos. Sin embargo, al trabajr con esta propiedad, existe la posibilidad de que ocurra un _memory leak_, que es perjudicial para el funcionamiento de los programas de la computadora. 

7.  Un árbol binario es una estructura de datos similar al árbol normal, con la diferencia de que en esta cada nodo puede tener únicamente dos nodos hijos. Cada nodo cuenta con datos, dirección del nodo hijo izquierdo y dirección del nodo hijo derecho. Hay lleno, perfecto y completo.

8. El queue es una estructura de datos que funciona como una fila de un establecimiento, donde el primero en entrar  ala fila es el primero en ser atendido. Esto puede usado para aplicaciones de flujos de datos grandes como sistemas operativos, protocolos de red, y demás donde se ocupa un flujo FIFO (First In First Out).

9. La diferencia entre queue y stack es el flujo de datos, pues el queue es FIFO y el stack es LIFO.

10. Dependiendo de una llave específica, se tiene una función llamada _hash function_ que se encarga de computar un índice de la tabla para esa llave y su respectivo resultado. Una vez esto se haga, se almacena la llave con su resultado en el índice computado. Si varios elementos fueran direccionados a un mismo índice, habría una colisión que puede ser resuelta por varios métodos pero el más común es el de _chaining_ usando listas enlazadas.

11. La _hash function_ son las encargadas de computar el índice de la tabla que ocupará una pareja de llave y valor, basado en la llave. Son esenciales porque son las encargadas de asignar cada dato a un índice y así organizar óptimamente los datos.

12. Si el Hash Table tiene una muy buena hash function, su complejidad temporal es de O(1).

13. Para agregar un elemento a la pila, se debe aumentar el contador _top_ del stack y en ese espacio libre que queda, se inserta el nuevo elemento. Esta operación es hecha por medio de punteros para que el acomodo quede hecho correctamente en memoria.

14. Estas acciones son de complejidad O(1).

15. Una lista enlazada consiste en un conjunto de nodos que cada uno contiene datos y la dirección del siguiente nodo en la lista, por lo que no es una lista como un array o vector pero sí se puede iterar sobre sus elementos nada más cambiando el nodo. Sus mayor ventaja es respecto al no despedicio de memoria de esta estuctura de datos respecto a otras, al igual que son considerablemente más dinámicas y su escalabilidad. Por otro lado, su mayor desventaja es la utilización de memoria dinámica y el hecho que no hay acceso aleatorio y es muy difícil de compartir la información.

16. Un nodo en el contexto de las linked lists son los elementos de la lista. Estos contienen únicamente el set de información que caracteriza cada nodo y la dirección del nodo al que apunta.

17. Las listas enlazadas simples tienen la característica de que solo cuentan con la posición del próximo nodo, no la del anterior. En las doblemente enlazadas ocurre lo contrario, pues en estas cada nodo sí cuenta con las direcciones de los nodos anterior y próximo.

18. Para eliminar un nodo de una lista enlazada, depende de si creó el nodo con malloc o con new, pues se debe usar ***free*** o ***delete***, respectivamente. Además de eso, se debe revisar que no queden huecos en la cadena de conexión de la lista, por lo que se debe cambiar la dirección del próximo nodo en el nodo anterior al que se va a eliminar. Una vez hecho esto, se libera el espacio de memoria del nodo que se va a eliminar.

19. El algoritmo de traversal en un árbol binario consiste en visitar todos los nodos del árbol sin repetir ninguno. Esto puede hacerse preorden, inorden o postorden.

20. La complejidad temporal de búsqueda en un árbol binario balanceado es de O(log n).

21. 
