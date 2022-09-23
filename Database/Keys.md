The **database key** is an attribute or a group of attributes that can uniquely identify each record in a table.<br>

* ## Super key
A subset of keys that can uniquely identify rows in a table and can have one or more redundant attributes<br>
Ex) id + student_number + studnet_name
* ## Candidate key
One or more keys that can uniquely identify rows in a table<br>
A candidate key belongs to a super key<br>
Ex) id + email + student_name cannot be a candidate key because excluding "id" attribute makes it impossible to distinguish duplications.
* ## Primary key
One key selected among candidate keys
* ## Alternate key
remaining keys after excluding the primary key
