# Hyperlink
something you can click on to jump to another place of the web. (It creates a nonlinear network of information)

# URI, URL
- URI: A unique string to identify a resource (e.g. www.example.com)
- URL: URI + protocol (e.g. http://www.example.com)

# The HyperText Markup Language, or HTML
the standard markup language that is used to define the structure of a webpage(, which can include hypermedia such as text, graphics, sound, video, and so on).

# HTTP and HTTPs
- **HTTP**: a stateless, insecure protocol for a client and a server to communicate, comprised of a request and a response. HTTP uses Uniform Resource Locators (URLs) to identify resources on the web. 
- **HTTPs**: HTTP that is encrypted using SSL handshake. It is secure but delays the speed of the website.

# HTTP methods
- **GET** for retrieving a resource
- **POST** for creating a new resource
- **PUT** for updating a resource
- **DELETE** for deleting a resource

# API
- An API allows different software applications to communicate.
- An open API is an API publicly available.
- An OpenAPI is a specification for describing RESTful APIs, which allows for the automatic generation of code, documentation, and tests based on the API specification.

# RESTful API
APIs that obey the REST constraints are described as RESTful API.<br>
Server side framework can be just about anything thanks to RESTful API that abstracts the implementation.
### REST constraints
- **Self-descriptive**: RESTful APIs are stateless and have to contain all the information needed to understand and process the request.
- **Uniform interface**: RESTful APIs have a uniform interface that provides a standardized way for clients and servers to communicate.
  #### The uniform interface constraint includes several aspects, such as:<br>
    - **Resource identification**: APIs are identified by unique URIs.
    - **Resource manipulation**: HTTP methods that have a specific meaning (GET, POST, etc.) are used.
    - **Representation of resources**: Resources are represented in a standardized format (e.g., JSON, XML) that both the client and server understand.

![image](https://user-images.githubusercontent.com/67142421/183272701-c6526ec7-79dd-4a9e-a72e-204dee53a978.png)<br>

# Hateoas
REST constraints are not enough to be a great API.<br>
HATEOAS suggests that an API should include hyperlinks in its responses, allowing clients to dynamically traverse the API by following the provided links instead of relying on prior knowledge or hard-coded URLs.<br>
This abstraction layer promotes loose coupling between the client and server as the client only needs to know the abstraction interface.<br>

### Traditional REST API response:
~~~json
GET /api/books/123
{
  "id": 123,
  "title": "The Catcher in the Rye",
  "author": "J.D. Salinger",
  "genre": "Fiction"
}
~~~
### HATEOAS REST API response:
~~~json
GET /api/books/123
{
  "id": 123,
  "title": "The Catcher in the Rye",
  "author": {
    "name": "J.D. Salinger",
    "links": {
      "self": "/api/authors/456"
    }
  },
  "genre": "Fiction",
  "links": {
    "self": "/api/books/123",
    "similar": "/api/books?genre=Fiction"
  }
}

~~~
In this HATEOAS REST API, the client-side code does not require any changes even if the APIs of "links" change, thanks to the abstraction layer provided by the "links" object.

# UI/UX
UI refers to visual elements that users interact with. UX refers more generally to users' overall experience, including how they feel about the interaction.
