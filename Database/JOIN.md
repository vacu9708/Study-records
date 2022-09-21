### Example table1
|id|student_name|email|grade|
|---|---|---|---|
|1|John|qwe@gmail.com|90|
|2|Paul|asd@gmail.com|80|
|3|Katherine|zxc@gmail.com|70|
|4|Ana|wer@gmail.com|70|

### Example table2
|id|student_name|email|grade|
|---|---|---|---|
|1|Smith|sdf@gmail.com|90|
|2|Maria|xcv@gmail.com|90|
|3|Ana|ert@gmail.com|80|

### SQL to create example tables
~~~sql
use first_database;

create table if not exists students1(
    id INT(99) primary key AUTO_INCREMENT comment 'ID',
    student_name varchar(99) not null comment 'student_name',
    email varchar(99) not null comment 'email',
    grade INT(99) not null comment 'grade'
);
create table if not exists students2(
    id INT(99) primary key AUTO_INCREMENT comment 'ID',
    student_name varchar(99) not null comment 'student_name',
    email varchar(99) not null comment 'email',
    grade INT(99) not null comment 'grade'
);

INSERT INTO students1(student_name, email, grade) VALUES('John', 'qwe@gmail.com', '90');
INSERT INTO students1(student_name, email, grade) VALUES('Paul', 'asd@gmail.com', '80');
INSERT INTO students1(student_name, email, grade) VALUES('Katherine', 'zxc@gmail.com', '70');
INSERT INTO students1(student_name, email, grade) VALUES('Andrea', 'wer@gmail.com', '70');

INSERT INTO students2(student_name, email, grade) VALUES('Smith', 'sdf@gmail.com', '90');
INSERT INTO students2(student_name, email, grade) VALUES('Maria', 'xcv@gmail.com', '90');
INSERT INTO students2(student_name, email, grade) VALUES('Ana', 'ert@gmail.com', '80');
~~~
# JOIN
A JOIN clause is used to combine rows from two or more tables, based on a related column between them.
## INNER JOIN
![image](https://user-images.githubusercontent.com/67142421/191418502-b67d9c97-f6c1-41a0-8866-65ef27344f9d.png)

The INNER JOIN is the most common and default JOIN clause. It returns rows that have matching values in both tables

### Both make the same result
~~~sql
SELECT students1.student_name, students2.student_name, students1.grade
FROM students1, students2 WHERE students1.grade = students2.grade;
~~~
~~~sql
SELECT students1.student_name, students2.student_name, students1.grade
FROM students1 INNER JOIN students2 ON students1.grade = students2.grade;
~~~
### Output
![image](https://user-images.githubusercontent.com/67142421/177883594-b714df59-1b5b-4a9e-9e91-76fbfa5aaafe.png)

## LEFT JOIN
![image](https://user-images.githubusercontent.com/67142421/177880429-7f2cd5a9-a9ed-42ad-8049-50ea628dede2.png)

The LEFT JOIN returns all rows from the left table and the matching rows from the right table. It returns NULL for no matching rows in the right table.

~~~sql
SELECT students1.student_name, students2.student_name, students1.grade
FROM students1 LEFT JOIN students2 ON students1.grade = students2.grade;
~~~~

### Output
![image](https://user-images.githubusercontent.com/67142421/177883665-33dc874d-0ca8-47eb-9c6e-83642080dc41.png)

# CROSS JOIN
Both make the same result.
~~~sql
SELECT *
FROM students1 CROSS JOIN students2;
~~~
~~~sql
SELECT *
FROM students1, students2;
~~~
