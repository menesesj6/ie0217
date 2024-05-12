# Tarea 5
## IE-0217: Estructuras Abstractas de Datos y Algoritmos para Ingeniería

Este instructivo para la compilación y ejecución de los archivos en esta carpeta está enfocado hacia una terminal _bash_ de Linux.  A continuación se exponen las formas de compilar y ejecutar por medio de un Makefile al igual que de forma manual por medio de la terminal, desde el directorio de **Tareas/Tarea5**. Cabe destacar que este instructivo está pensado para abrir la documentación de Doxygen en FireFox.

## Instrucciones de compilación y ejecución: Validador de _emails_
### Makefile
```
$ make build    # Ejecucion del programa
$ make run      # Despliegue documentacion Doxygen
$ make all      # Limpiar archivos compilados
``` 

### Documentacion en Netlify

Si no se deseara abrir la documentacion por línea de comandos, también se alojó el HTML producido por Doxygen en Netlify, en [este enlace.]()

## Parte teórica

### Investigación formato Markdown (.md)

El Markdown es un estilo de escritura que funciona para darle formato al texto simple. Por medio de reglas de sintaxis especificas es posible darle formato a cualquier texto, que puede ser escrito en prosa. Por lo general, este formato es usado para los README en los repertorios de Git, donde se incluyen aclaraciones del repertorio, informacion ectra e instrucciones de funcionamiento. 

### Expresiones regulares
1. 
2. 
3. 
4. 
5. 
6. 
7. 
8. 
9. 
10. 
11. 
12. 
13. 
14. 
15. 
16. 
17. 
18. 
19. 
20. 

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
