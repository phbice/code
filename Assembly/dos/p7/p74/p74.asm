assume cs:code,ds:data

data segment
	hotel db 'HoTeL'
	minix db 'MiNiX'
data ends

code segment
start:
	mov ax,data
	mov ds,ax
	mov bx,0
	
	mov cx,5
	s:
		mov al,ds:minix[bx]
		and al,11011111B
		mov ds:minix[bx],al
		
		inc bx
	loop s
	
	mov ax,4c00h
	int 21h
code ends

end start