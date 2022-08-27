;int 10h:
;ah = 0eh 输出单个字符
;参数：(al) = 字符的ascii码
;      (bl) = 颜色参数
;2017-6-20 11:03

assume cs:code,ds:data,ss:stack

stack segment
	db 100 dup (?)
stack ends

data segment
	db 'Hello world!',0ah,0
data ends

code segment
start:
	mov ax,stack
	mov ss,ax
	mov sp,100

	mov ax,data
	mov ds,ax
	mov si,0
	mov ah,0eh
	mov bl,00000111B ;white
	ShowStr:
		mov al,ds:[si]
		cmp al,0
		je finish
		inc si

		int 10h
	jmp short ShowStr
	finish:
	mov ax,4c00h
	int 21h
code ends

end start