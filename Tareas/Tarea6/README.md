# Tarea 5
## IE-0217: Estructuras Abstractas de Datos y Algoritmos para Ingeniería
## Parte teórica
1. Las bases de datos relacionales son aquellas que usan tablas para la organización de la información. Las tablas de este tipo de bases de datos incluyen _fields_ (columnas) y _registers_ (filas). Las tablas se interrelacionan por medio de _Foreign Keys_ y en cada tabla, existe una _Primary Key_ que permite identificar cada registro. Sus principales características o criterios son atomicidad, coherencia, aislamiento y durabilidad.

2. La clave primaria es aquella que identifica cada registro en una tabla, pues no se repite. Las claves candidatas son aquellas que podían ser la primaria pero no fueron seleccionadas para serlo.

3. Son aquellas que crean un vínculo entre tablas y permiten que estas se relacionen entre sí. Estas permiten que una tabla tenga un registro y este se asocie a un valor en otra tabla. Por ejemplo, si se tienen tablas CLIENTE y COMPRAS, el comprador se identifica por medio de una _foreign key_ que se asocia con los IDs de cada cliente.

4. 

5. 

6. 

7. 

8. 

9. 

10. 

## Parte práctica
### Creación de la base de datos y sus tablas

```
CREATE DATABASE IF NOT EXISTS TAREA6_IE0217;
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



### CRUD