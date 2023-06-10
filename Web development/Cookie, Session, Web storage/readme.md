The 2 major features of HTTP are **"connectionless"** and **"stateless"** as a result of it.<br>
* **Connectionless** : The server processes a request and sends a response back, after which the connection is cut.
* **Stateless** : Once the communication is done, the state information is not retained.
>These features of HTTP is why HTTP cookie or session is needed.<br>
>They are used to remember certain information about a user like what's in the user's shopping cart or login information.

## HTTP cookie and session
- **Cookie** is a small piece of data created by a server and placed on the user's computer.<br>
It is automatically sent back to the server through the HTTP request header on every request.

|| Cookie |
| :---: | :---: |
| Storage location | Client |
| Form | text |
| Limit | 300 cookies per client, 20 cookies per domain, 4KB per cookie |
| Expiration | Manually set |

## Web storage
Web storage is similar to HTTP cookie but with a greatly enhanced capacity(5MB) and no information sent in the HTTP request header.<br>
There are 2 types of web storage: **local storage** and **session storage**.<br>
Local storage is persistent while session storage is expired when the tab is closed.<br>
