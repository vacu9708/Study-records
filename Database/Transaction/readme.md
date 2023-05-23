# Transaction
A database transaction is a sequence of multiple operations performed as a single independent unit, ensuring that the operations either occur entirely or not at all.<br>
It guarantees that partial results are never saved. Changes made during a transaction are permanently applied to the database only when the transaction is **committed**(, meaning it has ended successfully) <br>

The primary purpose of a transaction is to maintain data integrity in situations during multiple concurrent operations.<br>
By treating a group of operations as a transaction, the database ensures that the data remains consistent and avoids potential issues like data corruption.

# ACID properties of transactions
### Atomicity
All changes within a transaction are treated as a single unit of work. Either all the changes are committed, or none of them are. It follows the principle of "all or nothing."

### Consistency
For example, in a fund transfer transaction, the total amount of money should remain constant before and after the transaction.

### Isolation
Concurrently executing transactions are isolated from each other, ensuring that they do not interfere with or impact each other.

### Durability
Changes made by a committed transaction should not be undone. They should be permanent and survive any subsequent system failures.

## Isolation levels
The higher transaction isolation level, the better data consistency.<br>
#### Read Uncommitted:
Uncommitted changes can be read without any restriction.
#### Read Committed:
This is the default of many SQL database<br>.
A transaction can only read data committed by other transactions.<br>
However, if transaction B modifies data that transaction A read earlier, transaction A might see different results each time it reads the data.
#### Repeatable Read:
Even if transaction B modifies data that transaction A read earlier, transaction A always sees the same results each time it reads the data.
#### SERIALIZABLE:
No SQL operation can be performed on the region where a query is being executed. The simplest, strictest and almost never used.

# Example
The **Autocommit** feature of a database performs **Commit** automatically.
~~~
User A wants to transfer $100 from their account to User B's account.
Begin transaction
1. Deduct $100 from User A's account.
2. $100 are credited to the User B's account.
Commit transaction
~~~
#### If it were not for the transaction:
- The amount of money is inconsistent if one of the operations fails
- The operations may access the same user's account and incur a race condition, which leads to inconsistent amount of money.

#### If a transaction fails:
- If one of the queries fails, all data modifications made from the start of the transaction are erased, which is called **Rollback**.
- When a transaction is rolled back, it gets into the **aborted** state.

# Transaction deadlock
Resources of a database are in a critical section(shared data is synchronous).<br>
A deadlock may occur if multiple transactions need exclusive use of resources.<br>
In other words, it occurs when two ore more transactions want to access resources locked by another one.<br>
Transactions wait for the resource to become available forever if it is not solved by t SQL server intervention.

![image](https://user-images.githubusercontent.com/67142421/178089624-c7a83d81-ee29-404f-94e4-1a4f2811a0c7.png)

Stored procedure : does the same thing as a function of normal programming languages
