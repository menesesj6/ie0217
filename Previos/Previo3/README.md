# Previo 3
## Instrucciones de compilación y ejecución

Este instructivo para la compilación y ejecución de los archivos en esta carpeta está enfocado hacia una terminal _bash_ de Linux. Se debe tener en cuenta que aquello escrito entre los caracteres _<>_ depende del usuario, pues corresponde archivo fuente que desea compilar. Se debe destacar que el nombre del archivo en _<>_ debe ser exclusivamente el nombre, sin la extensión _.cpp_. A continuación se exponen las formas de compilar y ejecutar por medio de un Makefile al igual que de forma manual por medio de la terminal.

* En esta carpeta existe un único caso donde se necesita compilar dos archivos, por lo que estos comandos sí se especifican con los nombres exactos necesarios.

### Makefile
**Caso de un archivo .cpp fuente.**
 ```
 $ make compileOne FILE1=<nombre_archivo_fuente>
 ```
 **Caso de dos archivos .cpp fuente.**
 ```
 $ make compileTwo FILE1=sum FILE2=EncabezadoYFuente
 ```
### Forma general
 A continuación se muestran los dos comandos necesarios para esta tarea si se deseara hacer manualmente. En este caso, el usuario puede escoger cómo se llamará su archivo ejecutable.

**Caso de un archivo .cpp fuente.**
 ```
 $ g++ <archivo_fuente>.cpp -o <archivo_ejecutable>.exe
 $ ./<archivo_ejecutable>.exe
 ```
 **Caso de dos archivos .cpp fuente.**
 
 ```
 $ g++ sum.cpp EncabezadoYFuente.cpp -o <archivo_ejecutable>.exe
 $ ./<archivo_ejecutable>.exe
 ```