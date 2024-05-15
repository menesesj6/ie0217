# Previo 10
## Instrucciones de compilación y ejecución

Este instructivo para la compilación y ejecución de los archivos en esta carpeta está enfocado hacia una terminal _bash_ de Linux. Se debe tener en cuenta que aquello escrito entre los caracteres _<>_ depende del usuario. A continuación se exponen las formas de compilar y ejecutar los tres programas incluidos en este directorio y en sus respectivos subdirectorios. ESte directorio consta de diversas carpetas, donde cada una contiene un ejemplo distinto sobre usos y manejo de WxWidgets haciendo uso de C++ para la creacion de GUIs (Graphic User Interfaces). Para estos ejemplos, se tienen diversos subdirectorios donde cada uno cuenta con su propio Makefile sencillo. A continuacion se detalla la infromacion de compilacion y ejecucion.
- ***IMPORTANTE:*** Debe asegurarse que tiene compilada e instalada la libreria que permite uso e inclusion de WxWidgets. Sin esto, los programas no funcionaran, pues estos hacen uso de los _header files_ dados por esta libreria, como <wx/wx.h>, siendo el mas utilizado.

***Listado de subdirectorios***
- Controles
- Estilos
- ManejoDinamicoEventos
- ManejoEstaticoEventos
- Propagacion de eventos (1, 2 y 3)
- VentanaBasica
- VerificarFuncionamiento

### Instrucciones de compilacion y ejecucion
Se debe destacar que, las instrucciones de compilacion son las mismas para todos los subdirectorios de ejemplos, por lo que basta con trasladarse al directorio deseado y aplicar las instrucciones indicadas a continuacion. Esto haciendo uso del comando ```cd <destiny>```, donde _destiny_ es el directorio al que se quiere ir. Tambien, ademas de la lista provista en esta guia, para saber los temas respecto a los que se realizaron ejemplos, se puede usar el comando ```ls``` desde la direccion ***Previos/Previo10***, lo que dara una lista en terminal de los subdirectorios existentes. 

```
make        # Compila y ejecuta el programa
make clean  # Elimina los archivos creados de la compilacion
```

