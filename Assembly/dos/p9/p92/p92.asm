;2017年6月15日16:14
;寻找第一个值为零的字节
;条件跳转 jcxz
;TAB = 4
assume cs:code,ds:data

data segment
	db 1,1,1,1,0,1,1
data ends

code segment
start:
	mov ax,data
	mov ds,ax
	mov bx,0
	s:
		mov cl,[bx]
		jcxz ok
		inc bx
	jmp short s
	ok:
	mov dx,bx
	mov ax,4c00h
	int 21h
code ends

end start