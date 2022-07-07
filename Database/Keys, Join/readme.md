### Example table1
|id|student_name|age|grade|
|---|---|---|---|
|1|John|20|90|
|2|Paul|21|80|
|3|Katherine|22|70|
|4|Ana|23|70|

### Example table2
|id|student_name|age|grade|
|---|---|---|---|
|1|Smith|20|90|
|2|Maria|21|90|
|3|Ana|22|80|

### SQL to create example tables
~~~sql
use first_database;

create table if not exists students1(
	id INT(99) primary key AUTO_INCREMENT comment 'ID',
    student_name varchar(99) not null comment 'student_name',
    age INT(99) not null comment 'age',
    grade varchar(99) not null comment 'grade'
);
create table if not exists students2(
	id INT(99) primary key AUTO_INCREMENT comment 'ID',
    student_name varchar(99) not null comment 'student_name',
    age INT(99) not null comment 'age',
    grade varchar(99) not null comment 'grade'
);

INSERT INTO students1(student_name, age, grade) VALUES('John', '20', '90');
INSERT INTO students1(student_name, age, grade) VALUES('Paul', '21', '80');
INSERT INTO students1(student_name, age, grade) VALUES('Katherine', '22', '70');
INSERT INTO students1(student_name, age, grade) VALUES('Andrea', '23', '70');

INSERT INTO students2(student_name, age, grade) VALUES('Smith', '21', '90');
INSERT INTO students2(student_name, age, grade) VALUES('Maria', '22', '90');
INSERT INTO students2(student_name, age, grade) VALUES('Ana', '23', '80');
~~~

The **database key** is an attribute or a group of attributes that can uniquely identify each record in a table.<br>

* **Candidate key** : one or more keys that can uniquely identify rows in a table
Ex) id, email student_name cannot be a candidate key because there may be a duplication.
* **Primary key** : a key selected among candidate keys
* **Super key** : a subset of keys with one or more attributes that can uniquely identify rows in a table
Ex) id + studnet_name
* **Alternate key** : remaining keys after excluding the primary key

# JOIN
A JOIN clause is used to combine rows from two or more tables, based on a related column between them.
## INNER JOIN
![image](https://user-images.githubusercontent.com/67142421/177866430-5e4254c3-d4f9-4922-9a5b-6775f83f0c81.png)

**Both make the same result**
~~~sql
SELECT students1.student_name, students2.student_name, students1.grade
FROM students1, students2 WHERE students1.grade = students2.grade;
~~~
~~~sql
SELECT students1.student_name, students2.student_name, students1.grade
FROM students1 INNER JOIN students2 ON students1.grade = students2.grade;
~~~
### Output
![image](https://user-images.githubusercontent.com/67142421/177880242-75572761-ee2c-4c4a-98d1-0970905ffeb5.png)

## LEFT JOIN
![image](https://user-images.githubusercontent.com/67142421/177880429-7f2cd5a9-a9ed-42ad-8049-50ea628dede2.png)

~~~sql
SELECT students1.student_name, students2.student_name, students1.grade
FROM students1 LEFT JOIN students2 ON students1.grade = students2.grade;
~~~~

### Output
![image](https://user-images.githubusercontent.com/67142421/177880271-beeef3fd-f194-4bcd-aded-0a610e207c0f.png)


