# CORS(Cross-Origin Resource sharing)
**CORS** is a mechanism that allows resources to be requested from different origins.<br>
Same-Origin Policy was introduced to prevent malicious requests(CSRF) from different origins.<br>
However, web pages often need to make requests to different domains.<br>
#### Without CORS:
Without CORS, a web page would only be able to make requests to resources on the same domain as the web page itself.<br>
CORS works by allowing a server to specify which domains are allowed to access its resources.<br>

### Process
1. the browser sends an initial "preflight" request to the target server.
2. The server then responds to the preflight request with the CORS headers
3. If the headers indicate that the request is permitted, the browser proceeds with the actual request. Otherwise, it is blocked for security reasons.<br>
![image](https://user-images.githubusercontent.com/67142421/183492714-17a6d283-1c28-4377-9a5b-0b3de112ec1a.png)

# Cross-site security issues
Both CSRF and XSS allow an attacker to masquerade as a victim user, to carry out any actions that the user is able to perform.

## CSRF(Cross-Site Request Forgery)
CSRF exploits the trust a user has for a particular site. It tricks a victim into submitting malicious requests on the attacker's behalf.
### CSRF process
1. Trick a victim into entering the attacker's page that looks legitimate.
2. The victim's browser sends the authenticated user's credentials (such as session cookies) along with a malicious request. (e.g., changing account settings, making a purchase, etc.)
3. The targeted server, considering the request to be legitimate because it includes the user's credentials, performs the requested action on behalf of the user.
### How to prevent CSRF
- Accept only requests from allowed origins
- Use a security token on each session of the user : The backend checks if the token in the request parameter is the token of the legitimate session.

## XSS(Cross-Site Scripting)
XSS is a type of injection attack in which malicious scripts are injected into web pages(such as posts) viwed by other users.<br>
The malicious code is executed on the same origin not on an external site, so it circumvents(bypasses) the same origin policy.<br>
Malicious code includes stealing authorization information such as security token or session ID.

### How to prevent XSS
- Encoding the dangerous characters (**<** and **>** in **<**script**>**) in the data that a web page receives to prevent the data from being interpreted in any malicious way.

# SQL injection
An SQL injection is to inject malicious SQL statements into an input to gain unauthorized access to database.
### Example to illustrate how SQL injection works
1. The website uses SQL queries to validate the user's credentials against a database.
~~~sql
DB.execute(`SELECT * FROM users WHERE username = ${input_username} AND password = ${input_password}`);
~~~
2. SQL injection attack:
If the website does not properly validate and sanitize the user inputs, an attacker can inject malicious SQL code. For example, instead of entering a valid username, the attacker enters:
~~~sql
' OR '1'='1
~~~
3. The manipulated query becomes:
~~~sql
SELECT * FROM users WHERE username = '' OR '1'='1' AND password = 'input_password';
~~~

4. Exploiting the vulnerability:
Since '1'='1' is always true, the attacker effectively bypasses the login validation by injecting additional SQL code. The query will return all the rows from the "users" table, allowing the attacker to log in without providing a valid username or password.

### How to prevent SQL injection
#### Parameterized queries:
Instead of directly embedding user input into SQL statements, use parameterized queries provided by the framework.<br>
They separate the query from the user input, effectively automatically preventing malicious input.<br>
~~~sql
DB.execute(SELECT * FROM users WHERE username = ? AND password = ?, [input_username, input_password]);
~~~
#### Hashing before saving:
Hash the password before saving it in the DB
#### Input validation and sanitization:
Apply strict validation rules to ensure that only expected and valid data is accepted. Sanitize the input by removing or escaping special characters that could alter the SQL syntax.