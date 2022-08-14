;用内存单元 0:0 - 0:7 内的数据改写程序中的数据
assume cs:codesg

codesg segment
	dw 1111h,2222h,3333h,4444h,5555h,6666h,7777h,8888h
start:
	mov ax,0
	mov ds,ax
	mov bx,0
	mov cx,8
	
	s:
		mov ax,[bx]
		mov cs:[bx],ax
		add bx,2
	loop s
	
	mov ax,4c00h
	int 21h
codesg ends

end start