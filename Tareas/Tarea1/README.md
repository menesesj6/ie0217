# Tarea 1
## IE-0217: Estructuras Abstractas de Datos y Algoritmos para Ingeniería

Este instructivo para la compilación y ejecución de los archivos en esta carpeta está enfocado hacia una terminal _bash_ de Linux. Se debe tener en cuenta que aquello escrito entre los caracteres _<>_ depende del usuario, pues corresponde archivo fuente que desea compilar. Se debe destacar que el nombre del archivo en _<>_ debe ser exclusivamente el nombre, sin la extensión _.cpp_. A continuación se exponen las formas de compilar y ejecutar por medio de un Makefile al igual que de forma manual por medio de la terminal.

## Instrucciones de compilación y ejecución: Juego Ahorcado
### Makefile
```
$ make ahorcado
``` 

### Forma general

```
$ cd src
$ g++ main.cpp Header.cpp -o Ahorcado.exe
$ ./Ahorcado.exe
``` 

### Acceso a la documentacion Doxygen con FireFox
```
$ make doxygen
``` 

## Parte teórica

### Preguntas

1. La diferencia entre C y C++ gira en torno al hecho que C++ es un lenguaje orientado a objetos, mientras que C no lo es. Esto quiere decir que en C++ se pueden crear clases e instanciarla como objetos, al igual que en otros lenguajes como Python.
    
2. Comandos _git_
    - **git init:** Este comando se utiliza para crear un repositorio local; es decir, se hace primero el repositorio en la máquina para después enviarlo a remoto, contrario de lo que se acostumbra. 
    - **git add:** Con este comando se ponen en el stage todos los cambios hechos al branch del repertorio en el que se esté trabajando. Todo lo que esté staged, será incluido en el próximo commit. Se le debe especificar el archivo o directorio.
    - **git commit:** Genera un commit en el branch en el que se esté trabajando. Cada commit contiene cambios que se realizaron al repertorio local. Esto hace que dichos cambios ya sean parte del branch; aunque los commits son reversibles.
    - **git push:** Envía los commits que se realizaron en el repertorio local hacia el repertorio remoto y se incorporan esos cambios al _main branch_.
    - **git merge:** Este se encarga de juntar dos branches, con la intención de implementar cambios hechos en un branch paralelo. Lo que lo caracteriza es que respeta la línea temporal de los commits. Es más recomendable usarlo para mandar del repositorio local al remoto en un _pull request_.
    - **git pull:** Es como un ***git fetch*** y un ***git merge*** combinados. Lo que hace es que se "trae" lo que haya en el repositorio remoto al repositorio local y lo que no esté en el local lo implementa. Como tiene el efecto de un _merge_, esto respeta la línea temporal de los commits y los acomoda en orden.
    - **git clone:** Este comando s eusa para clonar, valga la redundancia, un repositorio remoto en la computadora local. Esto puede hacerse con protocolo HTTP o por SSH Key, donde lo más recomendable es usar SSH Key para evitar tener que estar ingresando los credenciales. También, se debe configurar el acceso a este repositorio de manera local con un correo y un nombre, usando ***git config --< type > user.email"< email >"*** y ***git config --< type > user.name"< name >"***, donde las cosas entre comillas dependen del ususario y el _type_ depende de si se desea configuración local o global
    - **git branch:** Sirve para crear o eliminar un branch sin pasarse a este. Para crearlo se le debe pasar el nombre que se desea que tenga, de la forma ***git branch < name >***. Ahora bien, si más bien se desea eliminar un branch, se debe añadir la bandera -D, de la forma ***git branch -D < name >***.

3. Git es una herramienta para versionamiento de código y es apoyada de Code Hosting Apps como lo son GitHub y GitLab, que son meramente para tener una GUI de Git mas no son lo mismo. Git es usado en proyectos de software para poder llevar paso a paso los cambios hechos en los archivos respectivos y donde estos se pueden manipular y revertir. De la misma forma, se pueden paralelizar las líneas de trabajo por medio de los branches para que grandes equipos de personas puedan estar todos trabajando y que se tenga un historial de los cambios (commits) y se puedan juntar las ramas de trabajo (merge, rebase, pull, push, etc.) y llevar una sincronía en el proyecto.

4. Un _merge conflict_ se da cuando existe un problema al intentar unir dos branches de trabajo. Esto puede darse gracias a que hubo cambios de distintas personas a las msimas líneas, alguien borró un archivo que alguien estaba usando, etc. Es cuando existe una contradicción entre las versiones que se están juntando, pues Git no tiene forma de saber qué es lo correcto y entonces levanta el conflicto, el cual afecta únicamente al que intentó hacer el _merge_. Para resolver esto, Git normalmente da opciones en la terminal y ayuda diciendo el tipo de error que se obtuvo, ya sea add/add, remove/add, entre otros. Se pueden tomar medidas temporales, como saltarse el commit que da problema, abortar el merge, eliminar el cambio y seguir el merge, etc. Sin embargo, si se desea revisar y solucionar del todo, sería revisar a mano los errores que resalta Git en los archivos con conflictos.

5. El archivo _.gitignore_ es un archivo "especial" del repositorio que tiene de función especificar las extensiones de los archivos que se deben ignorar. Es decir, este es un archivo editable pero que tiene contenido predeterminado dependiendo del lenguaje de programación base del repositorio y que a la hora de trabajar el repositorio y usar _git add_, _git status_ y demás, ignora los archivos con extensión que esté incluida en el .gitignore. Por ejemplo al trabajar con lenguaje compilado como C++, este archivo incluye la extensión ***.exe*** para que los archivos ejecutables, resultados de la compilación, sean ignorados y no estén tomados en cuenta en ninguna acción del repositorio.

6. Un _pull request_ en GitHub es una forma de juntar los cambios de un branch al _origin_ (_main_ remoto). Estas solicitudes de extracción funcionan para realizar una revisión de la branch que se dese implementar al _origin_. Dentro de un pull request se pueden ver si existen conflictos entre archivos, al igual que se puede dejar reatroalimentación respecto a lo que se quiere implementar, se puede aceptar, rechazar, cambiar y, por ende, también se puede aceptar la fusión del branch con el _origin_ luego de una revisión adecuada. Para esto, lo normal es que al hacer _git push_, se haga a un branch remoto que no sea el _main_, para así hacer el pull request desde la interfaz web de GitHub basado en las dos branches remotas. Posterior a esto, se acostumbra a eliminar el branch remoto auxiliar para no tener un branch que no se está utilizando.

7. Un lenguaje interpretado es ejecutado por medio de un intérprete, valga la redundancia. Este intérprete va leyendo el código línea por línea y ejecuta las líneas de código conforme va leyéndolas; es decir, ejecuta el código "en vivo" conforme va leyéndolo. Si existe un error, va a ejecutar todo de manera correcta hasta que llegue al punto donde hay un error. Por otro lado, los lenguajes compilados tienen más etapas, pues el compilador se encarga de leer el archivo, pasa por el pre-procesamiento, pasa a lenguaje de máquinas, _linking_ y crea el ejecutable. En todas estas etapas de compilación, se asegura que el código no tenga errores, que se cumpla la sintaxis, etc. Si se encuentra un error durante la lectura de este, la compilación levantará un error y parará. Para correr el código, se debe correr el archivo ejecutable obtenido como salida del compilador, por lo que al correr este ejecutable, se tiene la certeza que no saltará ningún error.Una aplicación para el lenguaje interprestado puede ser JS en WebDev, donde se necesita que el software está respondiendo de manera rápida sin atrasos por compilación para así no interrumpir conexiones de sockets o un lento funcionamiento de la página web; y por otro lado, un ejemplo de lenguaje compilado es cuando se desarrolla un software que se requiere que sea lo más optimizado y eficiente, como un sistema operativo o microcontrolador, pues el compilador se encarga de que la ejecución sea lo más rápida y optimizada posible gracias a todo el proceso de compilación.

8. Como se mencionó en la pregunta anterior, el proceso de compilación tiene una etapa de _linking_, la cual es realizada por medio de un _linker_. Este es un programa encargado de unir todos los programas y bibliotecas necesarios para la correcta compilación de un archivo fuente y así poder crear el archivo ejecutable correctamente. Este es el que s eencarga de asociar todos los programas necesarios por medio de los #include o de las variables externas, por ejemplo, para que se tenga todo lo necesario.

9. 

10.

11. El concepto de sobrecarga de funciones en C++ es, en palabras sencillas, que varias funciones pueden tener el mismo nombre pero se diferencian por el tipo y la cantidad de parámetros que reciben. Por ejemplo, se puede tener dos funciones llamadas **sum**, que una puede recibir integers y otra recibir floats y al invocar las funciones, el compilador identifica cuál de las funciones es la que debe usar basado en el tipo de los parámetros que se le pasen. Esto puede servir en caso de que se deseen programar funciones que tengan la misma funcionalidad pero para tipos de datos distintos.

12. Un puntero es una variable que contiene la dirección de memoria donde está almacenada otra variable. Por ejemplo, si se tiene una variable **var1 = 5**, se puede crear una variable tipo puntero que sea ***puntvar1 = &var1**; entonces el 5 de var1 está almacenado en una posición de memoria cualquiera 0xXXXXXXX y en la variable puntvar1 se almacena esa posición de memoria 0xXXXXXXX como un valor hexadecimal. Estos son usados para realizar operaciones de bajo nivel en la capa de memoria directamente, como lo puede ser cambiar el valor en memoria de una variable al pasarla como parámetro a una función.

13. El término branch es de los fundamentales de entender a la hora de trabajar con Git, pues un branch puede ser visto como una línea de trabajo o desarrollo en el repositorio. Entonces, cada repositorio tiene un branch _main_ y se puede ramificar, valga la redundancia, el trabajo al crear un branch y realizar los cambios que se deseen/necesiten; ya que lo que se haga en este branch creado, es ajeno al principal. Entonces, en este branch se realizan lso cambios necesarios y una vez que se verifique el correcto funcionamiento de las implementaciones, se puede realizar un merge con el main y que las nuevas implementaciones queden en main; caso contrario que no funcione, no habría problema, pues se podría arreglar en el mismo branch secundario y en ningún momento se impactaría el funcionamiento de main.

14. La diferencia primordial entre los bucles do-while y while, es que en el do-while la acción se realiza antes de comprobar si la condición se cumple, mientras que en el bucle while, primero se revisa la condición para saber si se ejecuta la acción.

15. La ventaja de dividir un proyecto en archivos _.hpp_, _.cpp_ y _main.cpp_ va muy orientado hacia el orden y la organización del mismo. Esto ya que en el header (.hpp) se encontrarán las declaraciones de las funciones, structs, entre otros, que se usarán; todo dentro de una definición condicional, que asegura que sólo se definirá su contenido una vez en toda la ejecución. Esto funcionará como los prototipos al incluirlo en el main.cpp y el que se incluirá en los .cpp para que se definan las funciones correctamente. Todo esto para que el main.cpp, que es el archivo fuente principal e incluye el funcionamiento básico, pueda operar de manera correcta sin indeficniciones de funciones ni variables. Sin embargo, el funcionamiento robusto del proyecto se alberga en los .cpp, pues es donde se definen las funciones en torno a las cuales funcionará el proyecto.

16.
17.
18.
19.
20.
21. El puntero _this_ sirve para referenciar un miembro de un objeto instanciado de una clase. Se usa dentro de los métodos de una msima clase para que cada objeto acceda a sus propios miembros.<sup>1</sup> Por ejemplo, si se tiene una clase Perro y se tiene un método donde se necesita hacer referencia a la característica de su color de pelaje, se puede usar este puntero como ***this->color*** para acceder a esa característica in tener que referenciar directamente al mismo objeto.


22.
23. Los _memory leaks_ son problemas que ocurren a la hora de trabajar con lenguajes de programación con manejo manual de la memoria, como lo son C y C++ cuando se trabaja con memoria dinámica. Esto ocurre cuando no se desocupa de manera correcta la memoria empleada que ya no se necesita, por lo que un programa empieza a abarcar más memoria de la que en serio necesita, ocupando grandes cantidades de RAM, ocasionando una caída de rendimiento y, eventualmente, el cierre total del progrm o el agotameinto de los recursos.

### Investigación Doxygen



### Investigación formato Markdown (.md)

## Referencias
<sup>1</sup> Microsoft, 15/12/2023. https://learn.microsoft.com/es-es/cpp/cpp/this-pointer?view=msvc-170
