# Pros and cons of ORM and SQL
## ORM
#### Pros:
- **Good productivity**:  ORM frameworks provide abstraction of SQL that saves developers from writing raw SQL queries and automates query optimization.
- **Database flexibility**: Since ORM frameworks abstract the underlying database, developers can switch between different database systems without modifying the code significantly. This provides flexibility and reduces vendor lock-in.

#### Cons:
- **Limited control leading to bad performance**: ORM frameworks abstract the database operations, which means developers have less control over the generated SQL queries and the database-specific optimizations. This can be a disadvantage when fine-tuning performance.
- **Abstraction overhead**: ORM frameworks introduce an additional layer of abstraction, which can result in performance overhead compared to writing optimized SQL queries.

## SQL
#### Pros:
- **More control leading to good performance**: Developers can optimize queries by writing SQL queries directly, leverage database-specific features, and fine-tune performance. Skilled developers can achieve high-performance results by utilizing these capabilities.

#### Cons:
- **Bad productivity**: Writing complex queries directly requires a strong understanding of query optimization techniques and can be challenging.
- **Database dependency**: SQL queries are often written with a specific database system in mind. Switching to a different database may require rewriting, potentially increasing maintenance efforts.

# N+1 problem
