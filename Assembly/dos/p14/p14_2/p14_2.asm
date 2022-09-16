;通过逻辑移位与加法计算 (ax)*10
;(ax)*10 = (ax)*2  + (ax)*8
;        = (ax)<<1 + (ax)<<3
;2017-6-19 21:47

assume cs:code,ss:stack

stack segment stack
	db 100 dup (?)
stack ends

code segment
start:
	mov ax,10
	mov bx,ax

	shl bx,1

	mov cl,3
	shl ax,cl

	add ax,bx
	
	mov ah,4ch
	int 21h
code ends

end start