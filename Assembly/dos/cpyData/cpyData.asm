;将数据 0-63H 写入内存单元 0:200H - 0:263H
assume cs:code
code segment
	mov ax,0h
	mov ds,ax
	mov bx,200h
	mov cx,64
cpyLoop:
	mov [bx],ax
	inc ax
	inc bx
	loop cpyLoop
	
	mov ax,4c00h
	int 21h
code ends
end