assume cs:code

code segment
	mov ax,0
	mov cx,123

	addup:
		add ax,236
	loop addup
	
	mov ax,4c00h
	int 21h
code ends
end