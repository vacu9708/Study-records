# database key
The **database key** is an attribute or a group of attributes that can uniquely identify each tuple in a table.<br>

* ## Super key
A key that can uniquely identify rows in a table and may have one or more redundant attributes<br>
Ex) id + student_number + studnet_name
* ## Candidate key
One or more keys that can uniquely identify rows in a table where excluding ona attribute makes it impossible to distinguish duplciations on tuples<br>
Candidate keys are a subset of superkeys<br>
Ex) id + email + student_name cannot be a candidate key because excluding "id" attribute makes it impossible to distinguish duplications on tuples.
* ## Primary key
One key selected among candidate keys
* ## Foreign key
A foreign key is one or more attributes in a table that refers to the primary key of another table (or the same table).
* ## Alternate key
remaining keys after excluding the primary key
