A **database transaction** is a sequence of multiple operations performed on a database, and all served as a single logical unit of work — 
taking place wholly or not at all. In other words, there’s never a case that only half of the operations are performed and the results saved.
When a database transaction is in flight, the database state may be temporarily inconsistent, but when the transaction is committed(when a transaction has ended),
the changes are applied.<br>

**An example of unit of work**
>A customer is making a payment to a seller
>Operations here consist of : 
>1. $100 are taken away from the customer's account.(UPDATE)
>2. $100 are credited to the seller's account.(UPDATE)
>These two operations are a single unit of transaction.

All the 2 queries have to be finished so that the transaction can be finished, which is called **Committed**<br>
If one of the queries fails, all data modifications made from the start of the transaction are erased, which is called **Rollback**<br>
When a transaction is rolled back, it gets into the **aborted** state.<br>

stored procedure : does the same thing as a function of normal programming languages

## Transaction deadlock
A deadlock may occur if multiple transactions need exclusive use of resources.

![image](https://user-images.githubusercontent.com/67142421/178089624-c7a83d81-ee29-404f-94e4-1a4f2811a0c7.png)
