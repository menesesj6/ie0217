# Laboratorio 6
## IE-0217: Estructuras Abstractas de Datos y Algoritmos para Ingeniería

Este instructivo para la compilación y ejecución de los archivos en esta carpeta está enfocado hacia una terminal _bash_ de Linux.  A continuación se exponen las formas de compilar y ejecutar por medio de un Makefile al igual que de forma manual por medio de la terminal, desde el directorio de **Laboratorios/Labratorio7**. 

## Especificaciones y aspectos importantes

- Se hizo uso de un Makefile para la optimizacion de la compilacion
- El programa recibe argumentos por linea de comandos, por lo que se ejecuta por medio del Makefile pero se ejecuta con un comando aparte. En este, el usuario ingresa <search_pattern>, que es lo que se busca en el input file (data/input.txt) y <replace_string>, que es con lo que se reemplazara el patron buscado en el output file (data/output.txt). 
- El directorio _bin_ contiene los archivos .exe empleados por el programa.
- El directorio _data_ contiene los archivos input y output.
- EL programa no imprime nada en terminal, su funcionamiento es corroborado al comparar los archivos en _data_.
- Es esencial verificar la existencia de los directorios _data_ y _bin_ para la correcta compilacion por medio del Makefile. Si se fuera a trabajar sin estos directorios, se deberian hacer cambios en el Makefile y en el comando de ejecucion, por lo que es preferible tenerlos.
- Existe un archivo bin/textprocessor que es el que asegura la existencia de este directorio, pero es el ejecutable del programa y no se debe abrir, pues es un binario.

## Instrucciones de compilación y ejecución: 

### Makefile
```
$ make # Compilacion del programa
$ ./bin/textprocessor -f data/input.txt -o data/output.txt -search <search_pattern> -replace <replace_string> #Ejecucion del programa
``` 
