# Tarea 5
## IE-0217: Estructuras Abstractas de Datos y Algoritmos para Ingeniería

Este instructivo para la compilación y ejecución de los archivos en esta carpeta está enfocado hacia una terminal _bash_ de Linux.  A continuación se exponen las formas de compilar y ejecutar por medio de un Makefile al igual que de forma manual por medio de la terminal, desde el directorio de **Tareas/Tarea5**. Cabe destacar que este instructivo está pensado para abrir la documentación de Doxygen en FireFox.

## Instrucciones de compilación y ejecución: Validador de emails

### Makefile
```
$ make build    # Compilacion de archivos fuente
$ make run      # Ejecucion del programa
$ make all      # Compilar y ejecutar programa
$ make clean    # Limpiar archivos ejecutables creados
$ make doxygen  # Despliegue de documentacion Doxygen
``` 

### Documentacion en Netlify

Si no se deseara abrir la documentacion por línea de comandos, también se alojó el HTML producido por Doxygen en Netlify, en [este enlace.]()

## Parte teórica

### Investigación formato Markdown (.md)

El Markdown es un estilo de escritura que funciona para darle formato al texto simple. Por medio de reglas de sintaxis especificas es posible darle formato a cualquier texto, que puede ser escrito en prosa. Por lo general, este formato es usado para los README en los repertorios de Git, donde se incluyen aclaraciones del repertorio, informacion ectra e instrucciones de funcionamiento. 

### Expresiones regulares
1. Son patrones de texto que permiten comparar y manipular cadenas de texto. A nivel de programación son útiles para verificar que una cadena de texto cumpla con condiciones específicas deseadas sin tener que verificar caracter por caracter a mano y, por ende, simplifica los tiempos de computación de los algoritmos al analizar y manipular strings.
2. El punto (.) representa que cualquier caracter hará match, excepto un salto de línea. El asterisco (*) representa cero o más repeticiones del elemento anterior.
3. Por medio de los paréntesis, se agrupan elementos en subexpresiones y después estas se pueden concatenar usando caracteres especiales como un @, \., etc.
4. El escape o \\, sirve para marcar caracteres literales en el texto. Por ejemplo, el \\. se marcará un punto literal en el texto.
5. Aplicando cuantificadores a la subexpresión dentro de los paréntesis. Por ejemplo (ab)+ coincidirá con ab o abab, etc.
6. En regex, un \\d hace match a dígitos (números), mientras que \\D hace match a los no-dígitos (letras, caracteres especiales, etc.).
7. Las clases de caracteres, también referidas como conjuntos de caracteres, son especificados al usar paréntesis cuadrados, por ejemplo [a-zA-Z] es una clase de letras minúsculas y mayúsculas.
8. El $ sirve para indicar que la coincidencia debe estar al final de la línea.
9. Depende mucho de las especificaciones de nombre, domino y extensión, pero una forma básica de hacer esto sería con la siguiente regex. Esto es para un nombre sin límite de caracteres y sin restricciones de primer o último caracter y que tiene letras, números y los caracteres .,-,+, _. Las mismas especificaciones van para el dominio pero este sin el + ni _. Y por último la extensión, que permite únicamente letras pero sin límite de caracteres.
    ```
    ^([a-zA-Z0-9._+-]+)@[a-zA-Z0-9.-]+\.[a-zA-Z]$
    ```
10. Las expresiones regulares pueden ser un arma de doble filo, pues podrían optimizar o empeorar el rendimiento del software en cuestión. Esto dado que puede ser que el proceso de análisis de un string en tiempo de ejecución sea más complejo de lo necesario, cuando escribiendo diferente la regex, se podrían obtener mejores resultados. se recomienda evitar anidaciones redundantes en subexpresiones, al igual que entender bein los usos de ^ y $, para poder hacer revisiones puntuales y no revisiones innecesarias de más. Ahora bien, todo depende de la aplicación, donde todo se resume en entender bien el funcionameinto de estas y cómo aplicarlas en lo deseado.
11. Un Makefile es un archivo de un elemento llamados reglas. Estos funcionan en la programación, generalmente de C o C++, para automatizar el proceso de compilación y ejecución de un programa con base en sus archivos fuente. Entonces, en lugar de compilar todo a mano invocando g++ o gcc cada vez que se desea hacer una prueba, con un Makefile bien hecho, solo se debe ingresar un único comando que compila únicamente los archivos que fueron alterados y ejecuta el programa. La aplicaciones de un Makefile son demasiadas, pues permiten evitar tener que hacer muchos comandos a mano y sólo usar un único.
12. Las reglas explícitas son reglas para específicos archivos con comandos definidos propiamente por el desarrollador. Las implícitas son reglas generales que se aplica Make para resolver la actualización de archivos sin tener que escribir los comando so instrucciones propiamente.
13. Sirven para parametrizar el Makefile y facilitar el proceso de modificación de este mismo. Por ejemplo, si se tuviera un Makefile que ocupa source files de un directorio src, pero este directorio cambia por X o Y razón, al tener todo parametrizado por variables, solo basta cambiar el valor de esta variable en lugar de tener que cambiar el nombre del directorio en cada parte que se necesite.
14. Los targets son los resultados que se desean obtener al ejecutar el Makefile. Estos pueden ser un archivo o una acción.
15. Modularizar el código de C++ en distintos archivos fuente permite tener un proyecto más ordenado y, por ende, más sencillo de implementar y debuggear. El uso de un Makefile para esto permite simplificar la compilación y ejecución, pues si se hace a mano se estaría constantemente escribiendo g++ <archivos>.cpp-o <ejecutable> una y otra vez, lo que resulta contraproducente, pero al tener un buen Makefile creado, se automiza este proceso con un solo comando que, a su vez, re-compila solo lo necesario o que fue modificado, no compila todo de nuevo, optimizando el consumo de tiempo.
16. Por medio de las LDFLAGS, pues son las banderas que se le pasan al compilador para que invoque al linker con instrucciones específicas.
17. Para esto, se puede usar el OSFLAG. De esta forma, el Makefile puede identificar en cuál sistema operativo está operando y así definir los rules dependiendo de eso y así tratar debidamente los paths, comandos, etc. Un ejemplo de Makefile detector de OS es el mostrado en [este enlace.](https://gist.github.com/sighingnow/deee806603ec9274fd47)
18. Es un target que se encarga de ejecutar las otras rules que se tengan. Al ser el primero definido, este será el que se invoque si se corre el comando ***make*** por sí solo. Clean es el target usado normalmente para eliminar lo generado por otros targets del Makefile. En el contexto de C++, el clean se encargará de borrar los archivos ejecutables. Un ejemplo es mostrado a continuación.

    ```
    all: one two three

    one:
	    touch one
    two:
	    touch two
    three:
	    touch three

    clean:  
	    rm -f one two three
    ``` 
19. Esto es logrado por medio de un _override_ de variables, pues si se tiene el Makefile mostrado, se puede usar ```make file=main.cpp``` y así el comando que ejecutaría el target mostrado es ```g++ -Wall main.cpp -o Exe.exe```.
    ```
    file = empty.cpp
    
    Exe.exe: $(file)
        $(CXX) $(CXXFLAGS) $< -o ^@
    ```
20. 
    ``` 
    archivo.o: archivo.cpp
        $(CXX) $(CXXFLAGS) $< -o $@
    ```

### Makefile
1. La variable CC contiene el compilador que se desea usar; que seria gcc para C; y, por convencion, si se desea C++, se usa CXX. Luego, en CFLAGS se pasan las _flags_ o directivas extra que se le deseen dar al compilador de C. Analogamente, CXXFLAGS se usa para pasar _flags_ al compilador de C++. Por ultimo, LDFLAGS sirve para pasar _flags_ al compilador cuando ocupe invocar al _linker_ del programa.
2. Partes regla Makefile:
    - _Target_: Nombre de un archivo o accion
    - _Commands_: Son la lista de pasos que se siguen para el target definido. Deben ser identados por un _tab_.
    - _Prerrequisites_: Tambien conocidos como dependencias, son nombres de archivos que deben existir para que el target sea realizable.
3. Un target es un nombre de archivo o la accion que se desea hacer, pero los comandos bajo este se ejecutaran si y solo si los archivos de sus prerrequsiitos existen.
4. El flag _-c_ se usa para compilar los archivos fuente pero se salta la etapa de _linking_. Luego, la bandera _-o file_ se usa para especificar el output del proceso de compilacion. Por ultimo, el flag _-I_ es usado para que el compilador busque los header files que hagan falta.
5. Las variables en Makefile son asignadas usando ':=', o bien, '=', y son strings. SU invocacion para hacer uso de estas es con '\$()' o '\${}'.
6. @ es una variable automatica que contiene los nombres de los _targets_. Esto es usado para llamar distintos _targets_ en una sola regla.
7. Al agregar la directiva .PHONY, se asegura que el target phony se distinga del archivo que tenga el mismo nombre. ES decir, si se declara '.PHONY: clean' y existe un archivo clean, todo funcionara correctamente con 'make clean'. Sin embargo, si no se agrega el .PHONY, el target clean no correria correctamente, pues el compilador se confunde.
