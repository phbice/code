assume cs:code,ds:data
data segment
	db 77h,65h,6Ch,63h,6Fh,6Dh,65h,20h,74h,6Fh,20h,6Dh,61h,73h,6Dh,21h
	;welcom to masm!
data ends
code segment
s:	mov ax,data
	mov ds,ax
	mov ax,0b800h
	mov es,ax
	mov si,0
	mov di,0
	mov cx,16
	
	l:	mov al,ds:[si]
		mov es:[di],al
		add si,1
		add di,1
		mov al,01000010b
		mov es:[di],al
		add di,1
	loop l
	
	mov ax,4c00h
	int 21h
code ends
end s
