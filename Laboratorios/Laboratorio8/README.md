# Laboratorio 8
## IE-0217: Estructuras Abstractas de Datos y Algoritmos para Ingeniería

Este laboratorio se enfoca en practicar e irse acostumbrando mas a la sintaxis y funcionamiento de los comandos SQL vistos en el curso. La parte practica consiste en realizar parte de la practica de comandos SQL disponible en la pagina web [sql-practice.com](https://www.sql-practice.com/). La modalidad de trabajo sera en grupos de 4 a traves de _breakout rooms_ de Zoom.

- Numero de _breakout room_: **3**
- Integrantes _breakout room_: 
    - Jorge Meneses
    - Marcelo Valverde
    - Kryssia Martinez
    - Oscar Rojas

## Preguntas seleccionadas y asignacion

Se deben trabajar 16 preguntas de las disponibles en la pagina web previamente mencionada. Entonces, se trabajan 8 para cada base de datos disponible. Para la escogencia de los ejercicios, se tomaron los 8 mas dificiles de cada DB, de acuerdo a la clasificacion de dificultad dada por la misma pagina. En la siguiente seccion se presentan los enunciados y las soluciones planteadas para cada ejercicio, comentada por la persona que lo resolvio.

### Base de datos hospital.db
- ***Marcelo***:
    1. We need a breakdown for the total amount of admissions each doctor has started each year. Show the doctor_id, doctor_full_name, specialty, year, total_admissions for that year.
        ```
        -- Seleccionamos las columnas necesarias
        SELECT
        d.doctor_id as doctor_id,                              -- ID del doctor
        CONCAT(d.first_name, ' ', d.last_name) as doctor_name, -- Nombre completo del doctor (nombre + apellido)
        d.specialty,                                           -- Especialidad del doctor
        YEAR(a.admission_date) as selected_year,               -- Año de la fecha de admisión
        COUNT(*) as total_admissions                           -- Conteo total de admisiones
        FROM
        doctors as d                                           -- Tabla de doctores
        LEFT JOIN admissions as a ON d.doctor_id = a.attending_doctor_id -- Unimos con la tabla de admisiones usando el ID del doctor
        GROUP BY
        doctor_name,                                           -- Agrupamos por el nombre completo del doctor
        selected_year                                          -- y por el año de admisión
        ORDER BY
        doctor_id,                                             -- Ordenamos por ID del doctor
        selected_year                                          -- y por año de admisión
        ```

    2. Sort the province names in ascending order in such a way that the province 'Ontario' is always on top.
        ```
        -- Seleccionamos la columna province_name de la tabla province_names
        SELECT province_name
        FROM province_names
        -- Ordenamos los resultados según los criterios especificados
        ORDER BY
        (NOT province_name = 'Ontario'), -- Primero ordenamos para que 'Ontario' aparezca primero
        province_name                    -- Luego ordenamos alfabéticamente el resto de los nombres de provincias
        ```
    3. For each day display the total amount of admissions on that day. Display the amount changed from the previous date.
        ```
        -- Creamos una tabla común con el recuento de admisiones por fecha
        WITH admission_counts_table AS (
        -- Seleccionamos la fecha de admisión y contamos el número de pacientes por fecha
        SELECT 
            admission_date, 
            COUNT(patient_id) AS admission_count
        FROM 
            admissions
        -- Agrupamos por fecha de admisión
        GROUP BY 
            admission_date
        -- Ordenamos por fecha de admisión en orden descendente
        ORDER BY 
            admission_date DESC
        )
        -- Seleccionamos de la tabla común creada anteriormente
        SELECT
        admission_date, -- Fecha de admisión
        admission_count, -- Número de admisiones en esa fecha
        -- Calculamos la diferencia en el número de admisiones con respecto a la fecha anterior
        admission_count - LAG(admission_count) OVER(ORDER BY admission_date) AS admission_count_change 
        FROM 
        admission_counts_table
        ```
    4. Show the percent of patients that have 'M' as their gender. Round the answer to the nearest hundreth number and in percent form.
        ```
        -- Seleccionamos el porcentaje de pacientes masculinos redondeado a 2 decimales y convertido a un formato de porcentaje
        SELECT
        -- Calculamos el porcentaje de pacientes masculinos (gender = 'M'), lo multiplicamos por 100, lo redondeamos a 2 decimales
        -- y lo concatenamos con el símbolo '%' para formatearlo como un porcentaje
        ROUND(100 * AVG(gender = 'M'), 2) || '%' AS percent_of_male_patients
        FROM
        patients;   
        ```
        
- ***Kryssia***:
    1. We are looking for a specific patient. Pull all columns for the patient who matches the following criteria:
        - First_name contains an 'r' after the first two letters.
        - Identifies their gender as 'F'
        - Born in February, May, or December
        - Their weight would be between 60kg and 80kg
        - Their patient_id is an odd number
        - They are from the city 'Kingston'
        ```
        SELECT *
        FROM patients
        WHERE
          -- Verifica que el nombre (first_name) contenga una 'r' después de las dos primeras letras.
          first_name LIKE '__r%'  
          -- Identifica el género como femenino ('F').
          AND gender = 'F'
          -- Verifica que la fecha de nacimiento (birth_date) sea en febrero (2), mayo (5) o diciembre (12).
          -- MONTH(birth_date) extrae el mes de la columna birth_date.
          AND MONTH(birth_date) IN (2, 5, 12)
          -- Verifica que el peso (weight) esté entre 60 kg y 80 kg.
          AND weight BETWEEN 60 AND 80
          -- Verifica que el patient_id sea un número impar.
          -- Un número impar al dividirlo por 2 tiene un residuo de 1.
          AND patient_id % 2 = 1
          -- Verifica que la ciudad (city) sea 'Kingston'.
          AND city = 'Kingston';

        ```
    2. Show the provinces that has more patients identified as 'M' than 'F'. Must only show full province_name
        ```
        --Select sirve para seleccionar el nombre completo de la provincia
        SELECT pr.province_name
        FROM patients AS pa
        --Aca sirve para unir la tabla 'patients' con la tabla 'province_names' en la columna 'province_id' como se señala despues del igual JOIN province_names AS pr ON pa.province_id = pr.province_id
        --Luego, en esta parte se agrupan los resultados con el nombre de la provincia
        GROUP BY pr. province_name
        --Aca se hace un filtro y se muestran provincias donde los pacientes masculinos son mas que los pacientes femeninos.
         HAVING
        --Se cuentan los pacientes masculinos 'M' en cada grupo
        COUNT (CASE WHEN pa.gender = 'M' THEN 1 END) >

        --Se cuentan los pacientes femeninos 'F' en cada grupo
        COUNT (CASE WHEN pa.gender = 'F' THEN 1 END);

        ```
    3. Each admission costs \$50 for patients without insurance, and \$10 for patients with insurance. All patients with an even patient_id have insurance. Give each patient a 'Yes' if they have insurance, and a 'No' if they don't have insurance. Add up the admission_total cost for each has_insurance group.
        ```
        SELECT 
        -- Dice que se identifique si el patient_id es par: Yes o impar: No y se clasifique en la columna has_insurance
        CASE WHEN patient_id % 2 = 0 Then 
            'Yes'
        ELSE 
            'No' 
        --clasifique en
        END as has_insurance,
        -- Sum sirve para sumar los costos que se asignaron en base que el patient_id sea par o impar
        SUM(CASE WHEN patient_id % 2 = 0 Then 
            10
        ELSE 
            50
        -- si es asi se guarda en la columna cost_after_insurance
        END) as cost_after_insurance
        -- Luego from indica que la tabla a utilizar es admissions
        FROM admissions 
         -- Este sirve para agrupar los resultados 
        GROUP BY has_insurance;

        ```

    4. All patients who have gone through admissions, can see their medical documents on our site. Those patients are given a temporary password after their first admission. Show the patient_id and temp_password. The password must be the following, in order:
        1. patient_id
        2. the numerical length of patient's last_name
        3. year of patient's birth_date
        ```
        -- Select sirve para seleccionar el patient_id de la tabla patients
        SELECT
          DISTINCT P.patient_id,
        -- Este sirve para concatenar el patient_id, la longitud del apellido last_name y el año de nacimiento birth_date  
          CONCAT(
            P.patient_id,
            LEN(last_name),
            YEAR(birth_date) 
        -- esto se concatena para crear una contraseña temporal y se le asigna con AS como 'temp_password'
          ) AS temp_password 
        -- Luego dice que de la tabla patients 'P'  
        FROM patients P  
        -- Se usa un JOIN entre las tablas patients y admissions y que se use patient_id para unirlas
          JOIN admissions A ON A.patient_id = P.patient_id
        ```

### Base de datos northwind.db
- ***Oscar***:
    1. Show the company_name, contact_name, fax number of all customers that has a fax number. (not null)
        ```
        SELECT company_name, contact_name, fax
        FROM customers
        WHERE fax is not null
        ```
    2. Show the first_name, last_name, hire_date of the most recently hired employee.
        ```
        SELECT first_name, last_name, MAX(hire_date)
        FROM employees
        ```
    3. Show the average unit price rounded to 2 decimal places, the total units in stock, total discontinued products from the products table.
        ```
        SELECT ROUND(AVG(unit_price),2), SUM(units_in_stock), SUM(discontinued) 
        FROM products
        ```
    4. Show the ProductName, CompanyName, CategoryName from the products, suppliers, and categories table.
        ```
        SELECT p.product_name, s.company_name, c.category_name
        FROM products p
        JOIN suppliers s ON s.supplier_id = p.supplier_id
        JOIN categories c On c.category_id = p.category_id 
        ```
- ***Jorge***:
    1. Show the category_name and the average product unit price for each category rounded to 2 decimal places.
        ```
        -- Extraer nombre de categoria y promedio de precios redondeado
        SELECT categories.category_name, ROUND(AVG(products.unit_price), 2)
        FROM categories JOIN products
        -- Condicion de JOIN cuando los ID de la categoria sea el mismo
        ON categories.category_id = products.category_id
        -- AGrupar por el nombre de la categoria
        GROUP BY categories.category_name;
        ```
    2. Show the city, company_name, contact_name from the customers and suppliers table merged together. Create a column which contains 'customers' or 'suppliers' depending on the table it came from.
        ```
        -- Extraer los valores de customers y asignar la columna de relacion si es customer o supplier
        SELECT city, company_name, contact_name, 'customers' AS relationship 
        FROM customers 
        -- Hacer el merge de las tablas
        UNION
        -- Extraer la informacion de los suppliers con la relacion fija
        SELECT city, company_name, contact_name, 'suppliers' 
        FROM suppliers ;
        ```
    3. Show the employee's first_name and last_name, a "num_orders" column with a count of the orders taken, and a column called "Shipped" that displays "On Time" if the order shipped_date is less or equal to the required_date, "Late" if the order shipped late. Order by employee last_name, then by first_name, and then descending by number of orders.
        ```
        -- Obtener nombre completo y cantidad de ordenes del empleado
        SELECT
          e.first_name,
          e.last_name,
          COUNT(o.order_id) AS num_orders,
          -- Case para asignar estado de entrega de cada orden dependiendod el shipped_date
          (CASE
              WHEN o.shipped_date <= o.required_date THEN 'On Time'
              ELSE 'Late'
           END) AS shipped
        -- EStablecer de donde sacar la informacion y el JOIN
        FROM orders o
        JOIN employees e 
        -- Condicion del JOIN: ID del empleado igual en la orden (foreign key) y el empleado
        ON e.employee_id = o.employee_id
        -- Agruparlo
        GROUP BY e.first_name, e.last_name, shipped
        -- Ordenarlo segun lo solicitado
        ORDER BY e.last_name, e.first_name, num_orders DESC;
        ```

    4. Show how much money the company lost due to giving discounts each year, order the years from most recent to least recent. Round to 2 decimal places
        ```
        SELECT 
        -- Extraer el anio de la orden
        YEAR(o.order_date) AS 'order_year' , 
        -- Obtener la cantidad total de dinero perdido en descuentos
        ROUND(SUM(p.unit_price * od.quantity * od.discount),2) AS 'discount_amount' 
        -- Especificar de donde sale la informacion y el JOIN
        FROM orders o 
        JOIN order_details od
        -- Condicion JOIN: ID de orden igual en order y en order_details
        ON o.order_id = od.order_id
        -- Unir con products basado en el ID del producto
        JOIN products p ON od.product_id = p.product_id
        -- Agrupar por anio
        GROUP BY YEAR(o.order_date)
        -- Ordenar descendientemente por el anio de la orden
        ORDER BY order_year DESC;
        ```

        