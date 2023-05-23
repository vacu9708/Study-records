# Transaction
A database transaction is a sequence of multiple operations performed as a single independent unit, ensuring that the operations either occur entirely or not at all.<br>
It guarantees that partial results are never saved. Changes made during a transaction are permanently applied to the database only when the transaction is **committed**(, meaning it has ended successfully) <br>

The primary purpose of a transaction is to maintain data integrity in situations during multiple concurrent operations.<br>
By treating a group of operations as a transaction, the database ensures that the data remains consistent and avoids potential issues like data corruption.

# ACID properties of transactions
### Atomicity
All changes to data are performed as if they are a single operation. That is, either all the changes are applied, or none of them are.(All or nothing)<br>

### Consistency
Data is in a consistent state when a transaction starts and when it ends.<br>
For example, in an application that transfers funds from one account to another, the total money doesn't change.

### Isolation
When two or more transactions are being executed, none of them can intervene in each other<br>

### Durability
After a transaction successfully completes, changes to data persist and are not undone, even in the event of a system failure.<br>
For example, in an application that transfers funds from one account to another, the durability property ensures that the changes made to each account will not be reversed.<br>

### Isolation levels
Transaction isolation levels are used to ensure data consistency.<br>
1. Read Uncommitted (level 0) : data can be accessed without any restriction.
2. Read Committed (level 1) : a shared lock is issued to data where a SELECT is being executed. (Default of SQL)
3. Repeatable Read (level 2) : a shared lock is issued to data where a transaction is being executed. (Default of MySQL)
4. SERIALIZABLE (Level 3) : no SQL operation can be performed on the region where a transaction is being performed. the simplest, strictest and almost never used.

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

stored procedure : does the same thing as a function of normal programming languages
