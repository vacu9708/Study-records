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
If the JWT was tampered with, the signature recalculated using the received header and payload data will no longer match the signature in the JWT.

## Workflow
### Issuing
1. Client logs in using their credentials (e.g. username and password).
2. If the login information is valid, the server generates a JWT containing a header, a payload, and a signature. The signature is created using the server's private key.
3. The server sends the JWT(access token and refresh token) to the client, typically in the response body or as a cookie.
4. (Same as the digital signature process)The client verifies the token by decrypting its signature with the public key and comparing the decrypted signature with the received message.
### Authentification
1. The client forges and sends the JWT in the HTTP header
2. The server checks that the token has not expired and verifies the message by generating a new signature of the forged message with the private key and comparing it with the received signature.
3. The server refuses to send the requested data to the client.

## Refresh token
Unlike session objects that can be deleted as the server wants, tokens are not owned by the server and cannot be deleted freely.<br>
That is why access tokens are short-lived and typically expire after a specific amount of time, typically in some hours.<br>
A refresh token is needed for the trade-off between security and convenience.<br>
Asking the user to re-authenticate every time an access token expires is inconvenient and disruptive to the user experience.<br>
### Where to store refresh tokens?
#### On the clinet side:
- **No state stored on the server**
- **Vulnerability**: Storing refresh tokens on the client-side introduces a higher risk of compromise if an attacker gains access to the client-side storage.
- **Limited Control**: Tokens cannot be revoked selectively in situations such as when the user has been banned.
#### On the server side(redis):
- **Client states accessed sometimes**: Refresh tokens are accessed much less frequently than login sessions. Storing refresh tokens in Redis can be a good trade off between the security and the performance.
- **Enhanced Security**: The server can maintain the tokens in a secure manner, protecting them from client-side attacks.
- **Easier control**: Tokens can be revoked easily.

# Session-cookie VS JWT in authorization
### JWT
The fact that all the information is stored in the token(stateless) without a server-side state results in the pros and cons.
#### Pros:
- **Extra server-side storage not required**
- **Good scalability**: because of the decoupling between the token and the server
#### Cons:
- **Less control**: The token that was already issued cannot be controlled.
- **Larger traffic**: Tokens are bigger than session cookies

### Session-cookie
The fact that session objcets are managed on the server side results in the pros and cons.
#### Pros:
- **More control**: More control in managing user's login state.
- **Smaller traffic**: The client only sends its session ID, which leads to less traffic than JWT.
#### Cons:
- **More server-side storage required**
- **Bad scalability**: The high coupling between the server and session objects makes horizontal scaling difficult

# OAuth 2.0
OAuth2 (Open Authorization 2.0) is a standardized framework that allows other servers to access user resources without sharing the user's credentials.<br>
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/20beccb9-7d40-4bf1-a2b7-fd5ec49909c2)
[OAuth.architecture.pptx](https://github.com/vacu9708/Fundamental-knowledge/files/11513033/OAuth.architecture.pptx)



