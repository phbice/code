;2017-6-17 11:25
;将字符串中的字母全部转化为大写
;ds:bx 为字符串的首地址，字符串应以 00H 结尾

assume cs:code,ds:data,ss:stack

stack segment
	db 100 dup (?)
stack ends

data segment
	db 'Hello world',0
data ends

code segment
start:
	mov ax,stack
	mov ss,ax
	mov sp,100

	mov ax,data
	mov ds,ax
	mov bx,0
	call far ptr UpperCase_s

	mov ax,4c00h
	int 21h
code ends

assume cs:UpperCase
UpperCase segment
UpperCase_s:
	push bx
	push cx
	
	mov cx,0
	s:
		mov cl,ds:[bx]
		jcxz ok
		and byte ptr ds:[bx],11011111B
		inc bx
	jmp s
	ok:
	pop cx
	pop bx
	
	retf
UpperCase ends

end start