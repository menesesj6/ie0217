# Tarea 5
## IE-0217: Estructuras Abstractas de Datos y Algoritmos para Ingeniería
## Parte teórica
1. Las bases de datos relacionales son aquellas que usan tablas para la organización de la información. Las tablas de este tipo de bases de datos incluyen _fields_ (columnas) y _registers_ (filas). Las tablas se interrelacionan por medio de _Foreign Keys_ y en cada tabla, existe una _Primary Key_ que permite identificar cada registro. Sus principales características o criterios son atomicidad, coherencia, aislamiento y durabilidad.

2. La clave primaria es aquella que identifica cada registro en una tabla, pues no se repite. Las claves candidatas son aquellas que podían ser la primaria pero no fueron seleccionadas para serlo.

3. Son aquellas que crean un vínculo entre tablas y permiten que estas se relacionen entre sí. Estas permiten que una tabla tenga un registro y este se asocie a un valor en otra tabla. Por ejemplo, si se tienen tablas CLIENTE y COMPRAS, el comprador se identifica por medio de una _foreign key_ que se asocia con los IDs de cada cliente.

4. Una transacción en el contexto de las DBs corresponde a un conjunto de una o más instrucciones o comandos ejecutados; y que permiten mantener la integridad y coherencia de los datos en la DB. Los principios ACID que esta debe seguir son atomicidad, constancia, que sean aisladas y que sean duraderas.

5. Es una tabla virtual que no existe propiamente como un conjunto de datos per sé en la base de datos, por lo que no ocupa almacenamiento en el disco. Estas son producto de una consulta a la base de datos que esté en uso. Los beneficios de estas incluyen el aumento de seguridad para los datos, simplicidad en los _queries_, simplicidad para observar el _schema_ y tener información estable aunque las tablas madre cambien. Por otro lado, las _views_ pueden degradar el rendimiento del análisis de datos dado que estos son objetos dentro del DB, y esto hace que el procesador tenga que traducir _queries_ y en aplicaciones complejas podría afectar severamente la eficacia.

6.  La normalización es el proceso de organizar los datos de un DB, explicado de manera sencilla. En este proceso está la creación de tablas y la relación entre estas para crear una base de datos robusta pero flexible al eliminar la redundancia de las relaciones entre tablas. Las _normal forms_ son las siguientes:

    - ***First Normal Form***: Cada celda tiene un valor sencillo y las columnas deben tener un único nombre. Se eliminan datos duplicados y simplifica los _queries_.
    
    - ***Second Normal Form***: Cada columna está relacionada a la _primary key_. Se elimina redundancia en los datos.
    
    - ***Third Normal Form***: Basada en la anterior, todas las columnas son independientes, relacionándolo al _primary key_ y no a las otras columnas de la tabla.
    
    - ***Boyce-Codd Normal Form***: Todo lo que no sea un _key_ está relacinoado y es dependiente del _candidate key_.
    
    - ***Fourth Normal Form***: No hay dependencias multi-valor.
    
    - ***Fifth Normal Form***: Descomponer cada tabla en pequeñas tablas para minimizar riesgo de redundancia y mejorar la integridad de los datos.

7. 

8. 

9. 

10. 

## Parte práctica
### Creación de la base de datos y sus tablas

```
-- Crear la base de datos
CREATE DATABASE IF NOT EXISTS TAREA6_IE0217;
-- Seleccionar la base de datos para usarla
USE TAREA6_IE0217;

```

```
-- Crear tabla de Cursos
CREATE TABLE Cursos (
    CursoID INT AUTO_INCREMENT PRIMARY KEY NOT NULL,
    Sigla VARCHAR(8) UNIQUE KEY NOT NULL,
    Nombre VARCHAR(100) UNIQUE KEY NOT NULL,
    Semestre VARCHAR(8) NOT NULL,
    Creditos TINYINT NOT NULL);
    
-- Crear tabla de Requisitos
CREATE TABLE Requisitos(
    RequisitoID INT AUTO_INCREMENT PRIMARY KEY NOT NULL,
    CursoID INT NOT NULL,
    RequisitoCursoID INT NOT NULL,
    FOREIGN KEY (CursoID) REFERENCES Cursos(CursoID),
    FOREIGN KEY (RequisitoCursoID) REFERENCES Cursos(CursoID));
    
-- Crear tabla de Descripciones
CREATE TABLE Descripciones(
    DescripcionID INT AUTO_INCREMENT PRIMARY KEY NOT NULL,
    CursoID INT NOT NULL,
    Descripcion TEXT NOT NULL,
    Dificultad VARCHAR(8) NOT NULL,
    FOREIGN KEY (CursoID) REFERENCES Cursos(CursoID));
```

### Inserción de datos
Cursos
```

```

Requisitos

```

```

Descripciones

```
```
### Consultas


### Actualizaciones


### Eliminaciones