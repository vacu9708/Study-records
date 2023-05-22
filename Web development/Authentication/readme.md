# JWT(JSON Web Token)
![image](https://user-images.githubusercontent.com/67142421/183502457-7ba21a27-068e-4421-9670-e1f1736208ca.png)

JWT consists of 3 parts.
## Header
identifies which algorithm is used to generate the signature
~~~javascript
{"algorithm": "HS256", "type": "JWT"}
~~~
## Payload
contains token information and public information to identify the user. It is not encrypted, so care must be taken so that sensitive data is not included.
~~~javascript
{"issuedAt": "65131721", "ID": "catherine"}
~~~
## Signature
The header and payload are taken together and encoded into a signature when the token is issued.<br>
If the JWT was tampered with, the signature recalculated using the received header and payload data will no longer match the signature in the JWT. (or the same way as the digital signature can also be used where the signature and decrypted)

## Workflow
### Issuing
1. Client logs in using their credentials (e.g. username and password).
2. If the login information is valid, the server generates a JWT containing a header, a payload, and a signature. The signature is created using the server's private key.
3. The server sends the JWT(access token and refresh token) to the client, typically in the response body or as a cookie.
4. (Same as the digital signature process)The client verifies the token by decrypting its signature with the public key.
### Authentification
1. The client forges and sends the JWT in the HTTP header
2. The server checks that the token has not expired and verifies the message by generating a new signature of the forged message with the private key and comparing it with the original signature.
3. The server refuses to send the requested data to the client.

## Refresh token
A refresh token is needed for the trade-off between security and convenience.<br>
A refresh token is needed as part of the OAuth 2.0 authentication flow to obtain a new access token when the existing access token has expired. Access tokens are short-lived and typically expire after a specific amount of time, typically in minutes or hours.
When an access token expires, it can no longer be used to access protected resources on behalf of the user. In order to continue accessing those resources, a new access token must be obtained. However, asking the user to re-authenticate every time an access token expires can be inconvenient and disruptive to the user experience.

# Session-cookie VS JWT in authorization
### Session-cookie
The fact that session objcets are managed on the server side results in the pros and cons.
#### Pros:
- **More control**: More control in managing user's login state.
- **Smaller traffic**: The client only sends its session ID, which leads to less traffic than JWT.
#### Cons:
- **More server-side storage required**
- **Bad scalability**: Session objects across multiple servers are difficult to manage.

### JWT
The fact that all the information is stored in the token(stateless) without server-side storage results in the pros and cons.
#### Pros:
- **Extra server-side storage not required**
- **Good scalability**
#### Cons:
- **Less control**: The token that was already issued cannot be controlled.
- **Larger traffic**

## Token stealing attacks
- Cross-site scripting (XSS): An attacker injects malicious code into a website or application, which is then executed in a user's browser. This code can be used to steal the user's access token or refresh token from the client-side storage location.

- Cross-site request forgery (CSRF): An attacker tricks a user into submitting a malicious request to an application that includes the user's access token or refresh token. If the application does not have appropriate CSRF protections in place, it may inadvertently authorize the request and expose the user's token to the attacker.

- Man-in-the-middle (MITM) attack: An attacker intercepts communications between the client application and the server, allowing them to steal the user's access token or refresh token as it is transmitted between the two. This can be mitigated by using HTTPS encryption to protect the communication channel.

- Server-side vulnerabilities: If an attacker gains access to the server or the database where access tokens or refresh tokens are stored, they may be able to steal them directly.

# OAuth 2.0
OAuth2 (Open Authorization 2.0) is a standardized framework that allows other servers to access user resources without sharing the user's credentials.<br>
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/20beccb9-7d40-4bf1-a2b7-fd5ec49909c2)
[OAuth.architecture.pptx](https://github.com/vacu9708/Fundamental-knowledge/files/11513033/OAuth.architecture.pptx)



