assume cs:code

code segment
start:
	mov bx,4c00h
s1:	
	mov ax,bx
	mov si,offset s1
	mov di,offset s2
	mov ax,cs:[si]
	mov cs:[di],ax
	
s2:
	nop
	nop
	
;	mov ax,4c00h
	int 21h
code ends
end start