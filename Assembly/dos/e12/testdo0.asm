;测试 0 号中断（除法溢出）处理程序

Assume cs:code,ss:stack

stack segment
	db 100 dup (?)
stack ends

code segment
start:
	mov ax,stack
	mov ss,ax
	mov ax,0ffffh
	mov dx,0fffh
	mov bx,1
	div bx

	mov ax,4c00h
	int 21h
code ends

end start