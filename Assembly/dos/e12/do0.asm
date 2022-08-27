;0 号中断（除法溢出）处理程序
;2017-6-19 16:13
assume cs:code,ss:stack

stack segment
	db 100 dup (?)
stack ends

code segment
start:
;安装do0
	mov ax,stack
	mov ss,ax
	mov sp,100

	mov ax,cs
	mov ds,ax
	mov si,offset do0
	
	mov ax,0
	mov es,ax
	mov di,200h
	mov cx,offset do0_end - offset do0
	cld
	rep movsb
	
	mov word ptr es:[2],20h
	mov word ptr es:[0],0
	
	mov ax,4c00h
	int 21h

do0:
	jmp short do0_s
	string db 'Divide error!',0
do0_s:
	mov ax,cs
	mov ds,ax
	mov si,offset string - offset do0

	mov ax,0B800H
	mov es,ax
	mov di,12*160+36*2
	mov cx,0
	do0_s1:
		mov cl,ds:[si]
		jcxz do0_ok
		inc si

		mov es:[di],cl
		inc di
		mov byte ptr es:[di],00000100B
		inc di
	jmp short do0_s1
do0_ok:
	mov ax,4c00h
	int 21h
do0_end:
	nop
code ends

end start