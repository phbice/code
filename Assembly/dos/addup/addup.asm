;add up data from 1000:0 to 1000:11

ASSUME    CS:CODE
code segment
start:
	mov ax,1000h
	mov ds,ax
	mov ax,0h
	mov bx,0h
	mov cx,12
	mov dx,0h

	s:
		mov al,ds:[bx]
		add dx,ax
		inc bx
	LOOP s

	mov ax,4c00h
	int 21h
code ends
end start
