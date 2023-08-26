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
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/6de94ece-9792-4820-85a3-740ba922916e)<br>
Data encrypted using a private key can be decrypted using the corresponding public key. This is known as "digital signature" or "signing".<br>
In real implementation, It is the hash value of the data that is encrypted.
1. The sender creates a digital signature for the message using the private key and sends the message along with the digital signature.
2. A cheater forges the message.
3. The receiver verifies the message by decrypting its signature with the public key and comparing the decrypted signature with the received message.
4. The decrypted signature and the received messages do not match.

# HTTPS
#### [How to set up an HTTPS server](https://github.com/vacu9708/Tools-etc/tree/main/https)
While asymmetric key encryption ensures that intercepted messages cannot be read, it does not prevent a man-in-the-middle attack from impersonating the server's domain and manipulating the communication channel itself.<br>
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/2801946a-5c97-45ca-a9fd-d7d8d3219369)<br>
### 1. Handshake:
The client (e.g., web browser) initiates a connection to the server and requests a secure connection. The server responds with its certificate and public key.

### 2. Certificate verification:
This process ensures that the domain is not owned by an attacker but the proper server.
- The client verifies the authenticity of the server's certificate(using digital signature, certificate chain pre-installed in the web browser).
- The client checks if the certificate is signed by a trusted certificate authority (CA), if the domain name matches the server it is connecting to, and whether it has expired.

**Why the certificate should be verified?**: Trusted CA verifies the ownership of the server's domain before issuing a certificate. This process ensures that the HTTPS connection belongs to the server's domain, making it impossible to impersonate the server's domain.

### 3. Symmetric key(session key) exchange:
The asymmetric key encryption is slower than the symmetric key encryption.
Therefore, the client generates a symmetric key, encrypts it with the server's public key, and sends it to the server. The server uses its private key (which corresponds to the public key) to decrypt the session key.

### 4. Secure communication:
The client and server can now securely exchange HTTP requests and responses, as the data is encrypted using the symmetric key. This encryption makes it difficult for attackers to eavesdrop or tamper with sensitive information.
