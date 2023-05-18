# Symmetric key encryption
Traditional encryption where only one key is used to both encrypt and decrypt data.

# Asymmetric key encryption
A type of encryption where a public key and a corresponding private key are used.
### Pros
- Increased security because the private key does not need to be revealed to anyone
- Easier management of keys because all that needs to be revealed is one public key while Symmetric key encryption requires that many private keys be sent.
### Cons
- Complex mathematical computation
## How data is hidden
![image](https://user-images.githubusercontent.com/67142421/222992037-5f45d95f-5a57-4a36-af02-6b1850d03899.png)

## Digital signature
Data encrypted using a private key can be decrypted using the corresponding public key. This is known as "digital signature" or "signing".<br>
In real implementation, It is the hash value of the data that is encrypted.
1. The sender uses their private key to create a digital signature for the original message.
2. The recipient uses the public key to decrypt the digital signature and obtain the original message.
3. The recipient compares the received message with the decrypted original message.

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

# Symmetric key cryptography, Asymmetric key cryptography
Symmetric encryption uses a single key while asymmetric encryption uses a pair of public key and a private key to encrypt and decrypt messages.
 
## The process where a confidential message is delivered in the public key crptography
![image](https://user-images.githubusercontent.com/67142421/183536116-574d043c-768c-4339-911c-99e308dcbd58.png)

1. Bob generates 2 keys : public key and private key
2. Bob gives the public key to Alice
3. Alice encrypts the secret message using the public key she received.
4. Alice gives the encrypted message to Bob
5. Bob decrypts the message using his private key

# TLS(Transport Layer Security)