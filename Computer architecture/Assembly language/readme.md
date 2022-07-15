### Selection sort in C++
![image](https://user-images.githubusercontent.com/67142421/179166501-5dd22127-b281-4b34-9e3b-89e1afd1808a.png)

### How to find min, middle, and max value in assembly language
1.	Sort the array to find the min, mid, and max. Here I used the Selection sort.
2.	Since the array is sorted in ascending order, the first element of the array is the minimum, array[length / 2] is the middle value, and the last element is the maximum.

•	SHL 1 on pointer offsets, which means multiplying pointer offsets by 2, is necessary because the size of an element in the array is 2bytes, that is, shifting a pointer twice
~~~assembly
main 	segment
	assume cs:main, ds:main
	mov ax, cs
	mov ds, ax
	
loop1:	
	cmp i, 9
	jg break
	; {
	; min=i
	mov si, offset i
	mov ax, [si]
	mov si, offset min
	mov [si], ax
	;-----
	; j=i+1
	mov si, offset i
	mov ax, [si]
	inc ax
	mov si, offset j
	mov [si], ax
	;-----
	inner_loop: ; Find min
			cmp j, 10
			jg inner_end
			; {
			;arr[j]
			mov si, offset j
			mov ax, [si]
			SHL ax, 1 ; due to 16bits
			mov si, offset values
			add si, ax ; Move pointer
			mov ax, [si] ; ax=arr[j]
			;-----
			;arr[min]
			mov si, offset min
			mov bx, [si]
			SHL bx, 1 ; due to 16bits
			mov si, offset values
			add si, bx
			mov bx, [si] ; bx=arr[min]
			;-----
			; if (arr[j] < arr[min])
			cmp ax, bx
			jg else1
				; min=j
			mov si, offset j
			mov ax, [si]
			mov si, offset min
			mov [si], ax
				;-----
			else1:
				inc j
				jmp inner_loop
			; -----
	inner_end: ; swap
			; temp = arr[i]
			mov si, offset i
			mov ax, [si]
			SHL ax, 1 ; due to 16bits
			mov si, offset values
			add si, ax ; Move pointer
			mov ax, [si] ; ax=arr[i]

			mov si, offset temp
			mov [si], ax
			;-----
			; arr[i] = arr[min]
			mov si, offset min
			mov ax, [si]
			SHL ax, 1 ; due to 16bits
			mov si, offset values
			add si, ax ; Move pointer
			mov ax, [si] ; ax=arr[min]
			
			mov si, offset i
			mov bx, [si]
			SHL bx, 1 ; due to 16bits
			mov si, offset values
			add si, bx ; Move pointer
			mov [si], ax ; arr[i] = arr[min]
			;-----
			; arr[min] = temp
			mov si, offset temp
			mov ax, [si] ; ax=temp
			
			mov si, offset min
			mov bx, [si]
			SHL bx, 1 ; due to 16bits
			mov si, offset values
			add si, bx ; Move pointer
			mov [si], ax ; [values+min] = [temp]
			;-----		
	inc i
	jmp loop1
break: ; Print
	mov si, offset values
	; int to ascii
	mov dx, [si] ; min
	add dx, 48
	; Print
	mov ah, 2
	int 21h
	; space
	mov dx, 32
	mov ah, 2
	int 21h

	; int to ascii
	mov dx, [si+10] ; mid
	add dx, 48
	; Print
	mov ah, 2
	int 21h
	; space
	mov dx, 32
	mov ah, 2
	int 21h

	; int to ascii
	mov dx, [si+20] ; max
	add dx, 48
	; Print
	mov ah, 2
	int 21h
	; space
	mov dx, 32
	mov ah, 2
	int 21h

	; Exit
	mov ah, 4ch
	int 21h

i dw 0
j dw 0
min dw 0 ; For selection sort
temp dw 0
;values dw 5,7,8,9,6,5,4,7,8,9,6
;values dw 5,7,6,3,2,5,4,7,0,1,4
;values dw 0,1,2,3,4,5,6,7,8,9,7
;values dw 9,8,7,6,5,4,3,2,1,1,0
values dw 8,3,1,2,7,6,3,2,5,4,7

main	ends
	end
~~~

## Output
![image](https://user-images.githubusercontent.com/67142421/179167025-1ce5e900-3fda-4b63-bbbc-6458987217f3.png)

![image](https://user-images.githubusercontent.com/67142421/179167045-98a81067-74fc-47a5-ad57-8a41c3ffd34d.png)

![image](https://user-images.githubusercontent.com/67142421/179167065-75601332-f7ec-49bc-91b9-b2711483ba70.png)

![image](https://user-images.githubusercontent.com/67142421/179167100-61d1bb61-23ee-4f5d-a009-8c1377673207.png)

![image](https://user-images.githubusercontent.com/67142421/179167115-625d53d3-2a5b-4f76-8195-6bfb5127ba24.png)

