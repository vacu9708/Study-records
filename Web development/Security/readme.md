# Symmetric key encryption
Traditional encryption where only one private key is used to both encrypt and decrypt data.

# Asymmetric key encryption
### Pros
- Increased security because the private key does not need to be revealed to anyone.
- Easier management of keys because all that needs to be revealed is the public key while Symmetric key encryption requires that many private keys be sent.
### Cons
- Complex mathematical computation, which is slower than the Symmetric key encryption.
## How data is hidden
**Preparation**: The server generates a key pair consisting of a public key and a private key and send the public key to the client.<br>
![image](https://user-images.githubusercontent.com/67142421/222992037-5f45d95f-5a57-4a36-af02-6b1850d03899.png)

## Digital signature
Data encrypted using a private key can be decrypted using the corresponding public key. This is known as "digital signature" or "signing".<br>
In real implementation, It is the hash value of the data that is encrypted.
1. The sender creates a digital signature for the message using the private key and sends the message along with the digital signature.
2. A cheater forges the message.
3. The receiver verifies the message by decrypting its signature with the public key and comparing the decrypted signature with the received message.
4. The two messages do not match.

# HTTPs
Asymmetric key encryption cannot solely prevent the Man in the middle attack.
A trusted Certificate Authority requires proof of the server's domain ownership.
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/2801946a-5c97-45ca-a9fd-d7d8d3219369)<br>
#### 1. Handshake:
The client (e.g., web browser) initiates a connection to the server and requests a secure connection. The server responds by sending its HTTPs certificate, which contains its public key.
#### 2. Certificate verification:
The client verifies the authenticity of the server's certificate. It checks if the certificate is signed by a trusted certificate authority (CA), whether it has expired, and if the domain name matches the server it is connecting to.
#### 3. Key exchange:
If the certificate is valid, the client generates a symmetric key, encrypts it using the server's public key from the certificate, and sends it to the server.
Symmetric key encryption is faster than asymmetric key.


# CORS(Cross-Origin Resource sharing)
**CORS** is a mechanism that allows resources to be requested from different origins.<br>
Same-Origin Policy was introduced to prevent malicious requests(CSRF) from different origins.<br>
However, web pages often need to make requests to different domains.<br>
#### Without CORS
Without CORS, a web page would only be able to make requests to resources on the same domain as the web page itself.<br>
CORS works by allowing a server to specify which domains are allowed to access its resources.<br>

### Process
1. the browser sends an initial "preflight" request to the target server.
2. The server then responds to the preflight request with the CORS headers
3. If the headers indicate that the request is permitted, the browser proceeds with the actual request. Otherwise, it is blocked for security reasons.<br>
![image](https://user-images.githubusercontent.com/67142421/183492714-17a6d283-1c28-4377-9a5b-0b3de112ec1a.png)

# CSRF(Cross-Site Request Forgery)
CSRF exploits the trust a user has for a particular site. It tricks a victim into submitting malicious requests on the attacker's behalf.
## The process to execute CSRF
1. Trick a victim into entering the attacker's page that looks legitimate.
2. The victim's browser sends the authenticated user's credentials (such as session cookies) along with a malicious request. (e.g., changing account settings, making a purchase, etc.)
3. The targeted server, considering the request to be legitimate because it includes the user's credentials, performs the requested action on behalf of the user.
## How to prevent CSRF
- Accept only requests from allowed origins
- Use a security token on each session of the user : The backend checks if the token in the request parameter is the token of the legitimate session.

# XSS(Cross-Site Scripting)
XSS is a type of injection attack in which malicious scripts are injected into web pages(such as posts) viwed by other users. The malicious code is executed on the same origin not on an external site, so it circumvents(bypasses) the same origin policy. Malicious code includes stealing authorization information such as security token or session ID.
## XSS can be prevented by
encoding the dangerous characters (**<** and **>** in <script>) in the data that a web page receives to prevent the data from being interpreted in any malicious way

>Both CSRF and XSS allow an attacker to masquerade as a victim user, to carry out any actions that the user is able to perform.<br>

# SQL injection
An SQL injection is to inject malicious SQL statements into an input to gain unauthorized access to database.

