;将 mov ax,4c00h 指令以前的代码复制到 0020h 段中

assume cs:code
code segment
start:
	mov ax,cs
	mov ds,ax

	mov ax,0020h
	mov es,ax

	mov bx,0
	mov cx,offset cEnd - offset start
	
cpyLoop:
	mov al,ds:[bx]
	mov es:[bx],al
	inc bx
	loop cpyLoop
	
cEnd:
	mov ax,4c00h
	int 21h
code ends
end start