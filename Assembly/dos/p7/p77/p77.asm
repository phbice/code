;lower case to upper case
;use index register [bx + di]
;double-deck loop

assume cs:code,ds:data,ss:stack

stack segment
	db 100 dup(?)
stack ends

data segment
	db 'ibm             '
	db 'dec             '
	db 'dos             '
	db 'vax             '
data ends

code segment
start:
	mov ax,data
	mov ds,ax
	mov ax,stack
	mov ss,ax
	mov sp,100

	mov bx,0
	mov cx,4
	x:
		mov di,0
		push cx
		mov cx,3
		y:
			mov al,[bx][di]
			and al,11011111B
			mov [bx][di],al
			inc di
		loop y
		pop  cx
		add  bx,16
	loop x

	mov ax,4c00h
	int 21h
code ends

end start