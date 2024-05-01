# Previo 8
## Instrucciones de compilación y ejecución

Este instructivo para la compilación y ejecución de los archivos en esta carpeta está enfocado hacia una terminal _bash_ de Linux. Se debe tener en cuenta que aquello escrito entre los caracteres _<>_ depende del usuario, pues corresponde archivo fuente que desea compilar. Se debe destacar que el nombre del archivo en _<>_ debe ser exclusivamente el nombre, sin la extensión _.cpp_. A continuación se exponen las formas de compilar y ejecutar por medio de un Makefile al igual que de forma manual por medio de la terminal.

### Makefile
 ```
 $ make TemplateExceptions FILE1=<nombre_archivo_fuente>
 ```

### Forma general
 A continuación se muestran los dos comandos necesarios para esta tarea si se deseara hacer manualmente. En este caso, el usuario puede escoger cómo se llamará su archivo ejecutable.

 ```
 $ g++ <archivo_fuente>.cpp -o <archivo_ejecutable>.exe
 $ ./<archivo_ejecutable>.exe
 ```
