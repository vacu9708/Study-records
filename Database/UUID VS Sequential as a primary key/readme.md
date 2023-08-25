# UUID key VS Sequential key
## Distributed insertion (UUID wins)
- `UUID:` UUIDs are universally unique, which is useful for distributed insertions where concurrency can be an issue.
- `Sequential key:` If many instances of a service are inserting data into a table, it’s likely the different instances would produce the same key value because of the concurrency issue.
## Decentralized key generation (UUID wins)
- `UUID:` UUIDs are stateless and can be generated in the application to use for other tables.
- `Sequential key:` The key of a new record can only be obtained after executing a query. And the key may be inconsistent because of the concurrency problem.
## Migration & Backups (UUID wins)
- `UUID:` There is no key conflict in migration
- `Sequential key:` Restoring from backups or migrating data can be tricky when relying on sequences, as it needs to be ensured that new IDs don't conflict with existing ones.
## Predictability (UUID wins)
- `UUID:` Can be good for security as they are random and don't give away information about the number of records.
- `Sequential key:` The number of records or the order they were created can be inferred, potentially exposing sensitive business information.
## Size limit (UUID wins)
- `UUID:` Virtually infinite
- `Sequential key`: Although the maximum number of numerical identifiers is quite big, running out of numbers is possible.
## Memory usage (Sequential key wins)
- `UUID:` The UUID is 128-bit long, which is double the size of a BIGINT and four times the size of the INTEGER types.
- `Sequential key:` Smaller
## Indexing performance (Sequential key wins)
- `UUID:` The random nature of UUIDs makes the B+ tree perform the balancing more when inserting.
- `Sequential key:` Sequentially generated values do not require the balancing often.
