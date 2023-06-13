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
### Authentication
Authentication is the process of verifying the identity of a user and presenting a token.
1. Client logs in using their credentials (e.g. username and password).
2. If the login information is valid, the server generates a JWT containing a header, a payload, and a signature. The signature is created using the server's private key.
3. The server sends the JWT(access token and refresh token) to the client, typically in the response body or as a cookie.
4. (Same as the digital signature process)The client verifies the token by decrypting its signature with the public key and comparing the decrypted signature with the received message.
### Authorization
Authorization is the process of granting access to an authenticated user.
1. The client forges and sends the JWT in the HTTP header
2. The server checks that the token has not expired and verifies the message by generating a new signature of the forged message with the private key and comparing it with the received signature.
3. The server refuses to send the requested data to the client.

## Refresh token
Unlike session objects that can be deleted as the server wants, tokens are not owned by the server and cannot be deleted freely.<br>
That is why access tokens are short-lived and typically expire after a specific amount of time, typically in some hours.<br>
The refresh token is needed for the trade-off between security and convenience.<br>
Asking the user to re-authenticate every time the access token expires is inconvenient and disruptive to UX.<br>

### Re-issuing an access token to maintain a login state
When a user sends an expired access token, check if the requesting IP and the IP that generated the access token are the same. After validation, generate a new access token and return it to the user.<br>
However, a confirmation page if the user has gotten a different IP can be good for UX since the same user might get a different IP in some time.

---

# Login session
### How a session is made
1. Validate login information
2. The server creates a session object and sends a session ID that connects to the session object to the client
3. The session ID is stored as a cookie

### How authorized clinets are distinguished
1. The client sends an HTTP request with its session ID in the HTTP request header.
2. The server looks up if there is a session object matching the session ID.
3. If there is a match, the server authorizes the client.

If the session ID finds its way into the hands of a hacker, they can masquerade as that user. This is known as **session hijacking**.

---

# JWT VS Login session
### JWT
- **No client state without tokens stored on the server
- **Good scalability**: Horizontal scaling is easier because of the decoupling between the token and the server

### Login session
- **Better control**: Login sessions can be easily revoked in situations such as when the user has been banned.
- **Smaller traffic**: The client only sends its session ID, which leads to less traffic than JWT.

### External session storage server
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/9ee27101-d1a0-4dcc-b843-46a4c9c8f9e9)<br>
The decoupling between the session object and the server can be achieved by storing session objects in a separate session storage like Redis.<br>
#### Problem of the Session storage:
1. If the session server itself experiences a failure, it can result in the loss of all sessions, impacting all servers that rely on the session storage.
2. Retrieving sessions from an external session server introduces additional network I/O, potentially leading to decreased performance.

---

# OAuth 2.0
OAuth2 (Open Authorization 2.0) is a standardized framework that allows other servers to access user resources without sharing the user's credentials.<br>
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/20beccb9-7d40-4bf1-a2b7-fd5ec49909c2)
[OAuth.architecture.pptx](https://github.com/vacu9708/Fundamental-knowledge/files/11513033/OAuth.architecture.pptx)



