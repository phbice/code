;div 16位除法 100001/100
assume cs:code

code segment
start:
	mov dx,1h
	mov ax,86a1h ; 186A1H == 100001
	mov bx,100

	div bx
	
	mov ax,4c00h
	int 21h
code ends

end start