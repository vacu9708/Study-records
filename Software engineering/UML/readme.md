# Use case diagram
A use case diagram is a visual representation of the interactions between users (or "actors") and a system.<br>
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/0e097971-8af2-414d-b201-36c01a7da343)
### Use case
Use cases are typically represented as ovals and describe the functional requirements of the system – essentially, what the system should do.<br>
Each use case represents a distinct functionality or a goal that an actor wants to achieve by interacting with the system.

### Relationships
#### Include:
- Description: The include relationship is used when one use case (base use case) contains the functionality of another use case (inclusion use case). This allows for the reuse of functionality in the use case model.
- Example: Consider a use case diagram for an online shopping system. A use case like "Place Order" might include a common use case "Verify Credit Card."
#### Extend:
- Description: The extend relationship is used to represent optional or conditional behavior that can extend the functionality of a use case, but isn't necessary for the use case to be complete unlike the include.
- Example: In the same online shopping system, a use case "Browse Items" might be extended by an optional use case "Filter Results," which is used only under certain conditions (e.g., if the user wants to filter the items).

# Sequence diagram
A sequence diagram shows how objects interact in a given scenario of a use case.
### Example of a use case "Make an order"
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/2c540e32-df57-49bc-a8b1-c1f162e005c1)
### Components
- Actors and Objects: These are typically represented at the top of the diagram. Actors are external entities that interact with the system (like users), while objects are instances of classes within the system.
- Lifelines: Vertical dashed lines that represent the lifespan of an object during the interaction being modeled. They show the presence and activity of an object over time.
- Activation Bars: Rectangular boxes on a lifeline that indicate when an object is active or performing an operation.
- Messages: Horizontal arrows between lifelines. These depict the communication between objects.
- Return Messages: Typically represented as dashed horizontal arrows, showing the response from a receiver to the sender.
- Frames and Fragments: These can enclose parts of a sequence diagram to denote loops, conditionals, or other advanced control structures.
- Creation and Destruction Markers: Symbols that show when an object is created or destroyed during the sequence.

# Class diagram
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/d7dc6f52-73ec-4264-adbe-b5faafbe0239)<br>
A class diagram is a type of static structure diagram that describes the structure of a system by showing the system's classes, their attributes, operations (or methods), and the relationships among the classes.

# Flow diagram
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/30ba57e8-9eb9-459f-ac02-ce4fdafeb4e7)<br>
A flowchart is a graphical representation of a process, showing the steps as boxes of various kinds, and their order by connecting them with arrows. This diagrammatic representation illustrates a solution model to a given problem

# Entity-Relationship Diagram
![image](https://github.com/vacu9708/Fundamental-knowledge/assets/67142421/c6ed731e-3191-42b1-81b6-eca0c9e3264f)<br>
An ERD visually represents the relationships between entities (or data objects) within a system.
