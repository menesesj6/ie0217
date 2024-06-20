# Tarea 6
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

7. Los índices en SQL son un objeto a nivel del _Schema_ qu eoperan por medio de punteros. Estos son usados para optimizar el tiempo de respuesta de una consulta a la base de datos. Esto permite ahorrar capacidad de procesamiento y exigir menos el esfuerzo I/O del disco al usar un método de acceso a datos más veloz. Esto permite optimizar las directivas SELECT y WHERE, optimizando las consultas pero degradando el rendimiento en los UPDATE e INSERT. Dado esto, los índices pueden ser creados y eliminados en un _query_ sin afectar los datos almacenados.

8. El SQL Injection es una técnica usada por _hackers_ donde se ingresan comandos SQL mal intencionados a través de páginas web para obtener acceso no autorizado a una base de datos. Entre las medidas de prevención pueden estar:
    - Implementar autenticación de usuario.
    - Limitar el acceso de los usuarios autorizados. Es decir, aquellos que sí tienen acceso autorizado a la DB tendrán un límite de datos a los que pueden acceder.
    - No tener usuarios con permisos de administrador.

9. Como las funciones en los lenguajes de programación "normales", los _stored procedures_ en SQL son _queries_ guardados que se pueden reusar. Estos son sumamente útiles para evitar reescribir los mismos comandos SQL una y otra vez, lo que permite optimizar el _query_ y aumentar la eficiencia.

10. Para esta pregunta, se estudian los 3 casos solicitados
    - Uno a uno:
    
    Esto se puede lograr definiendo los _constraints_ FOREIGN KEY y un UNIQUE KEY en una misma columna. Acá se debe tomar en cuenta y diseñar correctamente cuál será la tabla padre hacia la que se referenciará el FOREIGN KEY. Podría necesitarse claves compuestas si se quisiera aumentar la robustez de relación e identificación entre las tablas.

    - Uno a muchos:
    
    Para este caso, se logra únicamente con el _constraint_ de FOREIGN KEY. Para este caso es similar al anterior, pues se debe definir cuál serpa la tabla y la columna hacia la que se referenciará.
    
    - Muchos a muchos:
    
    Una forma de lograr esto, puede ser haciendo uso de una _join table_, donde se junten todos los valores de dos tablas para lograr dar el resultado de relación muchos a muchos deseada. Acá la tabla intermedia debe tener un _primary key_ compuesto por foráneas de las dos tablas madre. Al igual que con las otras, definir correctamente los FOREIGN KEYs es crucial para la integridad de la relación entre tablas.

## Parte práctica
### Creación de la base de datos y sus tablas

Para el desarrollo de la parte práctica, se debe iniciar creando una base de datos sobre la cual se realziarán las directivas SQL solicitadas. Para esta asignación, se escogió el nombre ***TAREA6_IE0217***, que es creada y seleccionada para usar como se muestra a continuación. 

```
-- Crear la base de datos
CREATE DATABASE IF NOT EXISTS TAREA6_IE0217;
-- Seleccionar la base de datos para usarla
USE TAREA6_IE0217;
```
Sin embargo, con solo crear la base de datos no se logra mucho, sino que se deben crear las tablas que componen el _Schema_ de la base de datos y darle sus respectivas especificaciones para los datos que va a contener cada tabla. Esto es logrado por medio de la siguiente sección del _query_ haciendo uso de la directiva CREATE TABLE para la creación de las tablas. Las características de cada tabla son especificadas por medio de el tipo de dato y especificando si esta es un tipo de _key_ por medio de las directivas PRIMARY KEY, UNIQUE KEY o FOREIGN KEY. Cabe destacar que en las definiciones de FOREIGN KEY se agregó la directiva ON DELETE CASCADE, que fue investigada por aparte y su utilidad es eliminar todos los registros hijos si se elimina la llave foránea a la que están referenciadas.

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

Al hacer esto, se puede verificar la creación de las tablas, haciendo uso de las siguientes directivas. Ahora bien, como solo se crearon peor no se han ingresado datos, no deben haber registros en las tablas. Únicamente debe haber un registro especial que tenga todo en NULL y su ROWID es un *, lo que indica que no es un registro de datos como tal. Esto se expone en las imágenes mostradas.
```
SELECT * FROM Cursos;
SELECT * FROM Requisitos;
SELECT * FROM Descripciones;
```
![Imgur](https://i.imgur.com/s50ejaH.png)

![Imgur](https://i.imgur.com/GlO8lCG.png)

![Imgur](https://i.imgur.com/iNu7XOy.png)



### Inserción de datos
Para esta sección, se debe hacer uso de las directivas INSERT INTO seguida de VALUES para poder ingresar registros nuevos a las tablas con las que se está trabajando. Se podrá ver que el proceso es repetitivo, dado que solo se necesitan ingresar los valores de cada columna para cada registro que se debe crear. Los únicos que no se escriben en estas sentencias son los PRIMARY KEY de naturaleza AUTO_INCREMENT, pues esos se manejan por sí solos. También, posterior a cada sentencia INSERT INTO, se usa una directiva SELECT * para observar las tablas resultantes después de ingresar todos los datos deseados. También, se debe destacar el hecho que para pasar un valor al CursoID en las tablas Requisitos y Descripciones, se usó una sentencia SELECT para poder extraer el CursoID basado en el nombre del curso y no sea necesario saber el CursoID de lo que se desea ingresar al registo. 

Primero, se tienen los cambios en la tabla de Cursos.
```
-- Insertar el plan de estudios con optativas y requisitos
INSERT INTO Cursos (Sigla, Nombre, Semestre, Creditos) VALUES

-- Requisitos del plan													
('IE-0479', 'Ingeniería Económica', 'I-II', 3),														
('IE-0413', 'Electrónica II', 'I-II', 3),																
('IE-0315', 'Máquinas Eléctricas I', 'I-II', 4), 														
('IE-0499', 'Proyecto Eléctrico', 'I-II', 3), 														
('IE-0405', 'Modelos Probabilísticos de Señales y Sistemas', 'I-II', 3), 								 
('IE-0501', 'Responsabilidades en el Ejercicio Profesional de la Ingeniería Eléctrica', 'I-II', 1), 

-- Requisitos de los cursos inventados
('IE-0217', 'Estructuras Abstractas de Datos y Algoritmos', 'I-II', 3), 								
('IE-0411', 'Microelectrónica: Sistemas en Silicio', 'II', 3), 								
('IE-0523', 'Circuitos Digitales II', 'I-II', 3), 

-- Plan de estudios
('IE-0579', 'Administración de sistemas', 'I', 4), 												
('IE-0613', 'Electrónica industrial', 'I', 4), 													
('IE-0679', 'Ciencia de datos para la est. y pron. de eventos', 'II', 3), 							
('IE-0541', 'Seguridad Ocupacional', 'II', 3), 														
('IE-0599', 'Anteproyecto de TFG', 'I', 4), 														
('IE-mmmm', 'Optativa I', '-', 0), 																		
('IE-xxxx', 'Optativa II', '-', 0), 																	
('IE-yyyy', 'Optativa III', '-', 0), 																	
('IE-zzzz', 'Optativa IV', '-', 0),
('', 'Trabajo final de graduación', 'I-II', 4), 		

-- Cursos inventados
('IE-0628', 'Diseño Lógico Avanzado', 'I-II', 4), 						
('IE-0475', 'Sistemas Embebidos', 'I-II', 4);

-- Verificar la correcta insercion
SELECT * FROM Cursos;
```
![Imgur](https://i.imgur.com/vXmdV0M.png)

Luego, se tienen las inserciones de registros para la tabla de Requisitos, lo cual es mostrado según la fracción de _query_ mostrada a continuación.

```
-- Insertar los requisitos de los cursos del plan
INSERT INTO Requisitos (CursoID, RequisitoCursoID) VALUES(
	(SELECT CursoID FROM Cursos WHERE Nombre = 'Administración de sistemas'), 
    (SELECT CursoID FROM Cursos WHERE Nombre = 'Ingeniería Económica')),
    
	((SELECT CursoID FROM Cursos WHERE Nombre = 'Electrónica industrial'), 
    (SELECT CursoID FROM Cursos WHERE Nombre = 'Electrónica II')),
    
	((SELECT CursoID FROM Cursos WHERE Nombre = 'Electrónica industrial'), 
    (SELECT CursoID FROM Cursos WHERE Nombre = 'Máquinas Eléctricas I')),
    
	((SELECT CursoID FROM Cursos WHERE Nombre = 'Ciencia de datos para la est. y pron. de eventos'), 
    (SELECT CursoID FROM Cursos WHERE Nombre = 'Modelos Probabilísticos de Señales y Sistemas')),
    
	((SELECT CursoID FROM Cursos WHERE Nombre = 'Ciencia de datos para la est. y pron. de eventos'), 
    (SELECT CursoID FROM Cursos WHERE Nombre = 'Administración de sistemas')),
    
	((SELECT CursoID FROM Cursos WHERE Nombre = 'Seguridad Ocupacional'), 
    (SELECT CursoID FROM Cursos WHERE Nombre = 'Responsabilidades en el Ejercicio Profesional de la Ingeniería Eléctrica')),
    
	((SELECT CursoID FROM Cursos WHERE Nombre = 'Anteproyecto de TFG'), 
    (SELECT CursoID FROM Cursos WHERE Nombre = 'Proyecto Eléctrico')),
    
    ((SELECT CursoID FROM Cursos WHERE Nombre = 'Trabajo final de graduación'), 
    (SELECT CursoID FROM Cursos WHERE Nombre = 'Anteproyecto de TFG')),
    
	((SELECT CursoID FROM Cursos WHERE Nombre = 'Diseño Lógico Avanzado'), 
    (SELECT CursoID FROM Cursos WHERE Nombre = 'Circuitos Digitales II')),
    
    ((SELECT CursoID FROM Cursos WHERE Nombre = 'Diseño Lógico Avanzado'), 
    (SELECT CursoID FROM Cursos WHERE Nombre = 'Microelectrónica: Sistemas en Silicio')),
    
	((SELECT CursoID FROM Cursos WHERE Nombre = 'Sistemas Embebidos'), 
    (SELECT CursoID FROM Cursos WHERE Nombre = 'Estructuras Abstractas de Datos y Algoritmos')
);

-- Verificar la correcta insercion
SELECT * FROM Requisitos;
```
![Imgur](https://i.imgur.com/lz8GPu9.png)

Por último, se tienen las inserciones de registros a la tabla de Descripciones, hecho con la siguiente sección del _query_.

```
-- Insertar las descripciones
INSERT INTO Descripciones (CursoID, Descripcion, Dificultad) VALUES(
	(SELECT CursoID FROM Cursos WHERE Nombre = 'Estructuras Abstractas de Datos y Algoritmos'), 
	"POO en C++, bases de datos relacionales y no relacionales, debugging y paralelismo.", 
    'Media'),

	((SELECT CursoID FROM Cursos WHERE Nombre = 'Circuitos Digitales II'), 
    "Diseño conductual en Verilog.", 
    'Media'),
    
    ((SELECT CursoID FROM Cursos WHERE Nombre = 'Microelectrónica: Sistemas en Silicio'), 
    "Estudio fisico avanzado de circuitos integrados.", 
    'Dificil'),
	
	((SELECT CursoID FROM Cursos WHERE Nombre = 'Ingeniería Económica'), 
    "Principios de finanzas y microeconomia.", 
    'Facil'),
	
	((SELECT CursoID FROM Cursos WHERE Nombre = 'Electrónica II'), 
    "Electronica anlogica enfocada en amplificadores operacionales.", 
    'Media'),
	
	((SELECT CursoID FROM Cursos WHERE Nombre = 'Máquinas Eléctricas I'), 
    "Circuitos magneticos, motores, transformadores. Principios para potencia.", 
    'Dificil'),
	
	((SELECT CursoID FROM Cursos WHERE Nombre = 'Proyecto Eléctrico'), 
    "Proyecto final con profesor tutor.", 
    'Dificil'),
	
	((SELECT CursoID FROM Cursos WHERE Nombre = 'Modelos Probabilísticos de Señales y Sistemas'), 
    "Principios de probabilidad y estadistica. Proyectos programados aplicando la teoria.", 
    'Facil'),
	
	((SELECT CursoID FROM Cursos WHERE Nombre = 'Responsabilidades en el Ejercicio Profesional de la Ingeniería Eléctrica'), 
    "Filosofia sobre la moral y la etica.", 
    'Facil'),
	
	((SELECT CursoID FROM Cursos WHERE Nombre = 'Administración de sistemas'), 
    "Analisis de una organizacion o empresa.", 
    'Media'),
	
	((SELECT CursoID FROM Cursos WHERE Nombre = 'Electrónica Industrial'), 
    "Principios y fundamentos de la electronica de potencia.", 
    'Dificil'),
	
	((SELECT CursoID FROM Cursos WHERE Nombre = 'Ciencia de datos para la est. y pron. de eventos'), 
    "Analisis de eventos usando conceptos de cursos anteriores.", 
    'Media'),
	
	((SELECT CursoID FROM Cursos WHERE Nombre = 'Seguridad Ocupacional'), 
    "Principios de la seguridad en el dia a dia laboral.", 
    'Facil'),
	
	((SELECT CursoID FROM Cursos WHERE Nombre = 'Anteproyecto de TFG'), 
    "Desarrollo de habilidades necesarias para elaborar su propuesta de investigación de tesis.", 
    'Media'),
    
    ((SELECT CursoID FROM Cursos WHERE Nombre = 'Trabajo final de graduación'), 
    "Se puede elegir entre: Tesis, proyecto de graduación, seminario y práctica dirigida.", 
    'Dificil'),
    
    ((SELECT CursoID FROM Cursos WHERE Nombre = 'Optativa I'), 
    "Primer curso optativo.", 
    '-'),
    
    ((SELECT CursoID FROM Cursos WHERE Nombre = 'Optativa II'), 
    "Segundo curso optativo.", 
    '-'),
    
    ((SELECT CursoID FROM Cursos WHERE Nombre = 'Optativa III'), 
    "Tercer curso optativo.", 
    '-'),
    
    ((SELECT CursoID FROM Cursos WHERE Nombre = 'Optativa IV'), 
    "Cuarto curso optativo.", 
    '-'),
    
    ((SELECT CursoID FROM Cursos WHERE Nombre = 'Diseño Lógico Avanzado'), 
    "Programacion de RTLs y el diseno fisico de los mismos basado en los fundamentos de tecnologia CMOS para ICs.", 
    'Dificil'),
    
    ((SELECT CursoID FROM Cursos WHERE Nombre = 'Sistemas Embebidos'), 
    "Fundamentos teoricos de sistemas empotrados y aplicacion practica del mismo conocimiento.", 
    'Dificil'
);

-- Verificar la correcta insercion
SELECT * FROM Descripciones ORDER BY CursoID;
```

![Imgur](https://i.imgur.com/8kBh1tF.png)

### Consultas

La sección de consultas estará principalmente ubicada hacia el uso correcto y amplio de la directiva SELECT y sus distintas variaciones. Para esto, se realizarán distintas consultas a la base de datos y se buscará hacer uso de la mejor forma de SELECT para obtener los resultados. Estas pruebas se exponen a continuación.

Primero, se tiene una prueba donde se quiere mostrar sigla, nombre, semestre, créditos, descripción y dificultad de un curso. Para esto se hizo uso de un JOIN entre información de las tablas Cursos y Descripciones, extrayendo las columnas con la información solicitada. También se debe destacar que se hace el JOIN de las columnas bajo una condición en que los CursoID coincidan, para evitar cambios de información entre un curso y otro. Para lograr esto, se empleó el trozo de _query_ mostrado a continuación; obteniendo el resultado mostrado en la imagen. 

```
-- Consultar completos los cursos
SELECT c.Sigla, c.Nombre, c.Semestre, c.Creditos, d.Descripcion, d.Dificultad
FROM Cursos c
JOIN Descripciones d
ON c.CursoID = d.CursoID;
```
![Imgur](https://i.imgur.com/bYkdITx.png)

Luego de esto, se le realiza una consulta a la base de datos donde se quiere retornar los requisitos para un curso específico. Para este caso, se corren dos pruebas para corroborar el funcionamiento adecuado. El primer ejemplo será para el curso inventado "Diseño Lógico Avanzado" y luego para "Ciencia de datos para la est. y pron. de eventos". Para esta prueba se deseaba que el retorno fuera en una única fila y no en una fila por requisito, por lo que se acudió a usar la directiva GROUP_CONCAT para obtener correctamente los requsiitos por sigla y concatenarlos separados por una coma. Para esta consulta se debe volver a usar un JOIN pero doble esta vez, pues se necesita extraer de Requisitos el CursoID y el RequisitoID pero se hace JOIN con entre esta y Cursos para obtener nombre y sigla correspondientes. A continuación se muestran los dos ejemplos en un solo pedazo de _query_. Como se solicita d eun solo curso específico, el pedazo de _query_ empleado es el mostrado, mas podrían obtenerse de diversos cursos a la vez usando una directiva OR en la sentencia WHERE, declarando diversas condiciones.

```
-- Consultar requisitos de los cursos
SELECT c.CursoID, c.Sigla, c.Nombre, GROUP_CONCAT(c1.Sigla SEPARATOR ', ') AS Requisitos
FROM Cursos c
JOIN Requisitos r
ON c.CursoID = r.CursoID
JOIN Cursos c1
ON r.RequisitoCursoID = c1.CursoID
WHERE c.Nombre = 'Diseño Lógico Avanzado';

-- Consultar requisito de un segundo curso
SELECT c.CursoID, c.Sigla, c.Nombre, GROUP_CONCAT(c1.Sigla SEPARATOR ', ') AS Requisitos
FROM Cursos c
JOIN Requisitos r
ON c.CursoID = r.CursoID
JOIN Cursos c1
ON r.RequisitoCursoID = c1.CursoID
WHERE c.Nombre = 'Ciencia de datos para la est. y pron. de eventos';
```
![Imgur](https://i.imgur.com/rZZ77DV.png)
![Imgur](https://i.imgur.com/ENlKfMY.png)

### Actualizaciones


### Eliminaciones