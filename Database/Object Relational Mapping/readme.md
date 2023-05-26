# Pros and cons of SQL and ORM
## SQL
#### Pros:
- **More control leading to good performance**: Developers can optimize queries by writing SQL queries directly, leverage database-specific features, and fine-tune performance. Skilled developers can achieve high-performance results by utilizing these capabilities.

#### Cons:
- **Bad productivity**: Writing complex queries directly requires a strong understanding of query optimization techniques and can be challenging.
- **Database dependency**: SQL queries are often written with a specific database system in mind. Switching to a different database may require rewriting, potentially increasing maintenance efforts.

## ORM
ORM frameworks provide a higher level of abstraction, allowing developers to work with objects and entities rather than dealing with SQL queries and database operations.<br>
ORM frameworks automate the mapping of SQL query results to Java beans or objects.<br>
#### Pros:
- **Good productivity**:  ORM frameworks provide abstraction of SQL that saves developers from writing raw SQL queries and automates query optimization.
- **Database flexibility**: Since ORM frameworks abstract the underlying database, developers can switch between different database systems without modifying the code significantly. This provides flexibility and reduces vendor lock-in.

#### Cons:
- **Limited control leading to bad performance**: ORM frameworks abstract the database operations, which means developers have less control over the generated SQL queries and the database-specific optimizations. This can be a disadvantage when fine-tuning performance.
- **Abstraction overhead**: ORM frameworks introduce an additional layer of abstraction, which can result in performance overhead compared to writing optimized SQL queries.

# 1+N problem
The "N+1 problem" is a common performance issue that can occur in object-relational mapping (ORM) frameworks when retrieving data from a relational database.<br>
It refers to a situation where an ORM framework, such as Spring JPA, ends up executing 1+N queries to retrieve N entities(1 query) and their associated entities(N queries).<br>

Suppose there are two entities, Author and Book, with a one-to-many relationship where one author can have multiple books.
### The entities could be defined as follows:
~~~java
@Entity
public class Author {
    @Id
    private Long id;
    private String name;
}

@Entity
public class Book {
    @Id
    private Long id;
    private String title;

    @ManyToOne(fetch = FetchType.LAZY) // Lazy fetching results in the 1+N problem
    @JoinColumn(name = "author_id")
    private Author author;

    // Getters and setters
}
~~~
### A example of how the 1+N problem can occur:
~~~java
List<Author> authors = authorRepository.findAll();
for (Author author : authors) {
    System.out.println(author.getName());
    for (Book book : author.getBooks()) {
        System.out.println(book.getTitle());
    }
}
~~~
In this example, **authorRepository.findAll();** retrieves all authors(1 query).<br>
However, **author.getBooks()** within the loop triggers a separate query to fetch the books for each author individually(N queries).<br>
### How to mitigate 1+N problem
#### Eager fetching:
Eager fetching loads the associated entities (books) along with the main entity (authors) in a single query.(e.g. along with findAll();)<br>
This can be achieved by specifying the fetch = FetchType.EAGER option in the annotation.<br>
