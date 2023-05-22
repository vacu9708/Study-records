A **database transaction** is a sequence of multiple operations performed as a single unit on database — taking place **wholly or not at all**. In other words, there’s never a case that only part of the operations are performed and the results are saved.
When a database transaction is in flight, the database state may be temporarily inconsistent, but when the transaction is committed(when a transaction has ended),
the changes are applied.<br>
The purpose of **transaction** is to guarantee **data integrity** in concurrent operations. (synchronization)

# A unit of work example
~~~
A customer is making a payment to a seller
Operations here consist of : 
1. $100 are taken away from the customer's account.(UPDATE)
2. $100 are credited to the seller's account.(UPDATE)
These two operations are a single unit of transaction.
~~~
All the queries have to be finished so that the transaction can be finished, which is called **Committed**<br>
If one of the queries fails, all data modifications made from the start of the transaction are erased, which is called **Rollback**<br>
When a transaction is rolled back, it gets into the **aborted** state.<br>

## In database
The **Autocommit** feature of a database performs **commit** automatically.

# ACID properties of transactions
## Atomicity
All changes to data are performed as if they are a single operation. That is, either all the changes are applied, or none of them are.(All or nothing)<br>

## Consistency
Data is in a consistent state when a transaction starts and when it ends.<br>
For example, in an application that transfers funds from one account to another, the total money doesn't change.

## Isolation
When two or more transactions are being executed, none of them can intervene in each other<br>

## Durability
After a transaction successfully completes, changes to data persist and are not undone, even in the event of a system failure.<br>
For example, in an application that transfers funds from one account to another, the durability property ensures that the changes made to each account will not be reversed.<br>

# Isolation levels
Transaction isolation levels are used to ensure data consistency.<br>
1. Read Uncommitted (level 0) : data can be accessed without any restriction.
2. Read Committed (level 1) : a shared lock is issued to data where a SELECT is being executed. (Default of SQL)
3. Repeatable Read (level 2) : a shared lock is issued to data where a transaction is being executed. (Default of MySQL)
4. SERIALIZABLE (Level 3) : no SQL operation can be performed on the region where a transaction is being performed. the simplest, strictest and almost never used.

# Transaction deadlock
Resources of a database are in a critical section(shared data is synchronous).<br>
A deadlock may occur if multiple transactions need exclusive use of resources.<br>
In other words, it occurs when two ore more transactions want to access resources locked by another one.<br>
Transactions wait for the resource to become available forever if it is not solved by t SQL server intervention.

![image](https://user-images.githubusercontent.com/67142421/178089624-c7a83d81-ee29-404f-94e4-1a4f2811a0c7.png)

stored procedure : does the same thing as a function of normal programming languages
