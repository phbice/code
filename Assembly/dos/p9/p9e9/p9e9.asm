ROW   equ 10
CROSS equ 30
COLOR equ 00000100B
assume cs:code,ds:data,ss:stack

stack segment
	db 100 dup (?)
stack ends

data segment
	db 'Welcome to Assembly!',0
data ends

code segment
start:
	mov ax,stack
	mov ss,ax
	mov ax,data
	mov ds,ax
	mov ax,0B800H
	mov es,ax
	
	mov bx,ROW * 160
	mov si,0
	mov di,0
	mov cx,0
	s:
		mov al,ds:[si]
		mov ah,COLOR
		mov es:[bx+di+CROSS*2],ax
		inc si
		add di,2
		
		mov cl,al
		jcxz ok
	jmp s
	ok:
	mov ax,4c00h
	int 21h
code ends

end start