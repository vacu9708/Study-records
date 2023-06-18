# CORS(Cross-Origin Resource sharing)
The Same Origin Policy was introduced to prevent accessing resources from different domains **inside \<script>**.<br>
However, there are situations where webpages need to access resources from different domains.<br>
The **browser** allows web pages to access resources from different domains with CORS.<br>
CORS works by allowing the server to specify which domains are allowed to access its resources.<br>
#### Without CORS:
Without CORS, a web page would only be able to access resources on the same domain as the web page itself.<br>

### Process
![image](https://user-images.githubusercontent.com/67142421/183492714-17a6d283-1c28-4377-9a5b-0b3de112ec1a.png)
1. the browser sends an initial "preflight" request to the target server.
2. The server then responds to the preflight request with the CORS header
3. If the header indicate that the request is permitted, the browser proceeds with the actual request. Otherwise, it is blocked for security reasons.

Once the browser has successfully completed the preflight request and received the necessary CORS headers, it caches and reuses that information for subsequent requests to the same server, without the need for additional preflight requests.

# CSRF(Cross-Site Request Forgery)
CSRF exploits the trust a user has for a particular site to masquerade as a victim user to carry out any actions that the user is able to perform.<br>
CSRF attacks leverage the browser's automatic inclusion of auth credentials (e.g., cookies) with requests to the target domain.<br>
However, Cookies are subject to the same-origin policy in web browsers, so www.evil.com normally cannot send a malicious request using the cookies of www.good.com in a web browser.
## CSRF process
1. Trick a victim into entering the attacker's webpage that looks legitimate.
2. The victim's browser sends the authenticated user's credentials along with a malicious request. (e.g., changing account settings, making a purchase, etc.)
3. The targeted server, considering the request to be legitimate because it includes the user's credentials, performs the requested action on behalf of the user.
## How to prevent CSRF
- CORS prevents making a request to different domains but is not sufficient to prevent CSRF because there are many bypasses such as \<img src="victim.com/get_secret> **outside \<script>**.<br>
- The referer header contains the URL of the web page making the request, which is automatically went by a web browser. The server can check the referer header but it can be easily forged.
- ### `Anti-CSRF token`:
Use a CSRF token token for each user.<br>
For example, when the client received a CSRF token from "www.server.com" on "www.good.com" and then sends a request to the server on "www.evil.com," the CSRF token will block the evil request.<br>
#### how the CSRF token protection works in this scenario:
1. The client received the CSRF token from "www.server.com" on "www.good.com." The CSRF token is specific to the "www.good.com".
2. When the client makes a request to the server on "www.evil.com," the browser automatically attaches any cookies associated with the "www.evil.com".
3. However, since the CSRF token cookie was received from "www.good.com", it won't be present in the request to "www.server.com" on the "www.evil.com".
4. When the server receives the request, it compares the CSRF token in the request (which is missing) with the one expected from the user's session.
5. Since the CSRF token is missing or doesn't match, the server identifies this as a potential CSRF attack and blocks the request. It may return an error response or take other appropriate security measures.

# XSS(Cross-Site Scripting)
XSS is a type of injection attack in which malicious scripts are injected into web pages(such as posts) viwed by other users.<br>
The malicious code is executed on the same origin not on an external site, so it circumvents(bypasses) the same origin policy.<br>
### Example of malicious code
Malicious code includes stealing auth information such as token or session ID from the client-side storage inside \<script><br>
The malicious script can redirect the user to the attacker's server to capture the retrieved information.<br>

### How to prevent XSS
#### `Encode malicious characters`:
Malicious code such as **<**img**>** should be encoded to prevent the data from being interpreted as code by the web browser.
Example HTML
~~~html
<!DOCTYPE html>
<html>
<head>
  <title>XSS Prevention Example</title>
  <script>
    function sanitizeInput(input) {
      return input
        .replace(/&/g, '&amp;')
        .replace(/</g, '&lt;')
        .replace(/>/g, '&gt;')
        .replace(/"/g, '&quot;')
        .replace(/'/g, '&#x27;')
        .replace(/\//g, '&#x2F;');
    }

    function DisplayPreventedUserInput() {
      var input = document.getElementById('input').value;
      var sanitizedInput = sanitizeInput(input);
      document.getElementById('preventedOutput').innerHTML = sanitizedInput;
    }

    function DisplayUserInput() {
      var input = document.getElementById('input').value;
      document.getElementById('output').innerHTML = input;
    }
  </script>
</head>
<body>
  <h1>XSS Prevention Example</h1>

  <form>
    <label for="input">User Input:</label> <!--<img src="x" onerror="alert('XSS Attack!')">-->
    <input type="text" id="input" />
    <button type="button" onclick="DisplayPreventedUserInput()">Display</button>
    <button type="button" onclick="DisplayUserInput()">Display without prevention</button>
  </form>

  <h2>Prevented output:</h2>
  <div id="preventedOutput"></div>

  <h2>Output without prevention:</h2>
  <div id="output"></div>
</body>
</html>
~~~
  
# Man-in-the-middle (MITM) attack
An attacker positions themselves between the client and the server to eavesdrop on or manipulate the data being exchanged.<br>
The attacker can steal important information like the user's token.<br>
This attack can be mitigated by using HTTPS to protect the communication channel.<br>

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
