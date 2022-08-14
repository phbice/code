;send data 0~63H to 0:200~0:23F

assume cs:code

code segment
	mov ax,0
	mov ds,ax ;initialize segment register (DS) = 0
	mov bx,23fH ;initialize offset address (BX) = 200
	mov cx,63;
	
	s:
		mov ds:[bx],cl
		dec bx
	loop s
	
	mov ax,4c00h
	int 21h
	
code ends

end