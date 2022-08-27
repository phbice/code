;子程序设计：cube 计算 ax 中的数的立方
;2017-6-17 10:42
;TAB = 4

assume ds:data,ss:stack

stack segment
	db 100 dup (?)
stack ends

data segment
	n      dw 8
	result dd 0
data ends

;计算 ax 中的数的立方，结果高位在 dx 中，低位在 ax 中
;ax <= 1625  (659H)
assume cs:cube
cube segment
cube_s:
	push bx
	
	mov bx,ax
	mul bx
	mul bx
	
	pop bx
	
	retf
cube ends

assume cs:code
code segment
start:
	mov ax,stack
	mov ss,ax
	mov ax,data
	mov ds,ax
	mov ax,ds:[n]
	call far ptr cube_s
	mov ds:[result],ax
	mov ds:[result+2],dx
	
	mov ax,4c00h
	int 21h
code ends

end start