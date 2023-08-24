# Saga pattern (Saga orchestrator)
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/02df917c-b27c-40fa-ab1e-ebed780aa1cf)

Using the Saga pattern, each local transaction at a microservice is performed as a separate step in a saga.<br>
If a local transaction fails, the saga coordinator triggers a compensation for already executed local transactions to undo their effects.<br>
This helps to ensure that the transactions across microservices are either successfully completed or compensated even if there are failures.<br>

### Distributed transaction
The term "saga" in the saga pattern refers to a sequence of local transactions or steps.
1. `Start`: A distributed transaction is triggered.
2. `Local transactions`: The saga includes local transactions such as payment, setting the stock, placing the order.
3. `Compensation`: If a step failed, compensation actions that undo the previously succeded steps are invoked, ensuring data consistency.
4. `Completion`: The saga concludes when all the steps are either successfully completed or compensated.

### Compensation after distributed transactions failed because of system failures (like unexpected shutdowns)
Keep logging of the start and end of each local transaction and automate the compensation of local transactions that did not end after system failures.
