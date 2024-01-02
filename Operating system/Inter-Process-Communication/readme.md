![image](https://user-images.githubusercontent.com/67142421/177234169-0dad21de-f3c8-42f2-b750-b011ae0decbf.png)

Processes are generally not permitted to access memory space that is allocated for use by another process. (A program's attempt to do so causes invalid page faults or segmentation violations.) There may be a need for communication between processes. That's why Inter-Process-Communication is needed.<br>
### In summary, IPC is needed because processes do not share memory 

## Types of IPC
- **Socket communication** : Processes share data via sockets.
- **Memory mapped file**(shared memory) : A file that works like a segment of virtual memory that can be used by multiple processes.
- **Pipe**: one-way communication where one process writes to the pipe, and the other process reads from it<br>
![image](https://user-images.githubusercontent.com/67142421/220620918-fcd90475-0530-42a9-8c2a-d6e6a08a0038.png)


# 📷[Video](https://youtu.be/OYb4Le92EiI)
![image](https://user-images.githubusercontent.com/67142421/177230621-fea1407e-3464-49eb-b177-ff80a497d07a.png)

# Explanation of the code of the first process. The other 2 processes have the same algorithm.

![image](https://user-images.githubusercontent.com/67142421/170632396-c4fab8a5-fa7a-47e7-bd23-3cbf05004398.png)<br>
Setting the location of the shared memory. The address will be put into HANDLE shared_memory.

![image](https://user-images.githubusercontent.com/67142421/170632443-bf48dfea-6784-4c6f-bb03-375935afb12b.png)<br>
Class to store the information of the ball to send to another process.

![image](https://user-images.githubusercontent.com/67142421/170632464-a12c8b21-9abb-4841-bd09-fe0be6240705.png)<br>
Threads to manage the ball and stick. When the ball has disappeared to another process, moving the ball is blocked.

![image](https://user-images.githubusercontent.com/67142421/170632477-42ace029-d3ec-45eb-bb4a-c726f203d2a3.png)<br>
Keep waiting until ball information arrives. If it has arrived, take the information to put the ball.

![image](https://user-images.githubusercontent.com/67142421/170632503-8820f097-5764-47f0-b5cb-9452e081e68e.png)<br>
Initialize variables.

![image](https://user-images.githubusercontent.com/67142421/170632527-6e670794-2ade-4a25-bbc8-257177530eae.png)<br>
Get the address of the shared memory.

![image](https://user-images.githubusercontent.com/67142421/170632561-d69c2df7-1f99-4812-b3ca-ed7236cdb253.png)<br>
Assign the address of shared memory to the ball information buffer.

![image](https://user-images.githubusercontent.com/67142421/170632575-28d01491-27e1-48ff-abe7-ba63b6efea90.png)<br>
Create threads.

![image](https://user-images.githubusercontent.com/67142421/170632585-671d1800-ee19-405f-ad80-fcf00016ad7d.png)<br>
If the button was pressed for the first time, pop up a message box, if not, initialize the position of the ball.
<br>
![image](https://user-images.githubusercontent.com/67142421/170632642-60c74ad9-0bba-4693-93db-d22213e62111.png)<br>
![image](https://user-images.githubusercontent.com/67142421/170632653-9e41ab9e-7703-4747-a8c5-a23de7f07ae1.png)<br>
Draw the ball and stick on windows timer.

![image](https://user-images.githubusercontent.com/67142421/170632668-c5aa7903-8b80-472d-a506-a23a3c0650a9.png)<br>
If the ball got to the left side of the window, bounce the ball. else if the ball got out of the window, pass the information of the ball to another process.
If the ball has hit the top or bottom, bounce it.

![image](https://user-images.githubusercontent.com/67142421/170632713-52a171aa-3318-4730-9902-c16c88bca19d.png)<br>
Move the stick up and down.

![image](https://user-images.githubusercontent.com/67142421/170632686-4b293ad4-4c04-4642-aeb8-c0165dfb9f06.png)<br>
When the ball and stick hit each other.


