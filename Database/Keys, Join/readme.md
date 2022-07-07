### Example table1
|id|student_number|student_name|age|
|---|---|---|---|
|1|123|John|20|
|2|456|Paul|21|
|3|789|John|22|

### Example table2
|id|student_number|student_name|age|
|---|---|---|---|
|1|987|Katherine|22|
|2|654|Ana|21|
|3|321|John|20|

The **database key** is an attribute or a group of attributes that can uniquely identify each record in a table.<br>

* **Candidate key** : one or more keys that can uniquely identify rows in a table
Ex) id or student_number. Student name cannot be a candidate key because there may be a duplication.
* **Primary key** : a key selected among candidate keys
* **Alternate key** : remaining keys after excluding the primary key
* **Super key** : a subset of keys with one or more attributes that can uniquely identify rows in a table
Ex) id + student_number or id + studnet_name

# JOIN
## INNER JOIN
~~~sql
SELECT student_name FROM table1, table2
WHERE table1.age = table2.age
~~~
**Both make the same result**
~~~sql
SELECT student_name FROM table1
INNER JOIN table2 ON table1.age = table2.age
~~~
### Output
|student_name|
|---|
|Katherine|
|John|
