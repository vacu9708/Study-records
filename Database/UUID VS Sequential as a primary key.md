# Random UUID key VS Sequential key
## Uniqueness
- `UUID`: UUIDs are universally unique, which is useful in distributed systems where concurrency is an issue.
- `Sequential key`: In distributed systems, where more than one system is inserting the data into the database, it’s likely the different systems would produce the same key value because of the concurrency issue.
## Generating the value
- `UUID`: UUIDs are stateless and can be generated in the application to use when inserting into multiple tables.
- `Sequential key`: The key of the new record can only be obtained after executing a query.
## Predictability
- `UUID`: Can be good for security as they are random and don't give away information about the number of records.
- `Sequential key`: The number of records or the order they were created can be inferred, potentially exposing sensitive business information.
## Memory usage
- `UUID`: The UUID is 128-bit long, which is double the size of a BIGINT and four times the size of the INTEGER types.
- `Sequential key`: Smaller
## Indexing performance
- `UUID`: The random nature of UUIDs makes the B+ tree perform the balancing more when inserting.
- `Sequential key`: Sequentially generated values do not require the balancing often.
## Size limit
- `UUID`: Virtually infinite
- `Sequential key`: Although the maximum number of numerical identifiers is quite big, running out of numbers is possible.