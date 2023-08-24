# OAuth 2.0
OAuth (Open Authorization) is an open standard for access delegation, commonly used as a way for a delegate server to grant access to their information on other websites but without giving them the passwords.<br>
This allows users to share specific data with an application while keeping their usernames, passwords, and other information private.
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/0b164a5e-448a-4137-af62-929997aba72c)<br>
[OAuth.architecture.pptx](https://github.com/vacu9708/Fundamental-knowledge/files/12428136/OAuth.architecture.pptx)

### Overall process
1. `User Authentication:` A user wants to log in to a third-party application using their credentials from a well-known service like Google or Facebook.
2. `Request for Permission:` The third-party application redirects the user to the chosen service (e.g., Google), where they log in and decide whether to give the third-party application permission to access certain information (like their email address or contacts).
3. `Granting Access:` If the user agrees, the service (e.g., Google) redirects them back to the third-party application with an authorization code.
4. `Access Token Exchange:` The third-party application exchanges the authorization code for an access token by making a server-to-server request.
5. `Accessing User Information:` Using the access token, the third-party application can request the user's information from the service (e.g., Google) without needing to know the user's login credentials for that service.
