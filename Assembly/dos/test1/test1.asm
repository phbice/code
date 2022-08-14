assume cs:codesg;,ss:stack

;stack segment
;	db 11h,22h,33h,44h,55h,66h,77h,88h,99h,00h
;stack ends

codesg segment
	mov ax,2000h;stack
	mov ss,ax
	mov sp,0
	add sp,4
	pop ax
	pop bx

;	mov ax,5555h
;	mov bx,00AAh
	
	push ax
	push bx
	
;	mov ax,0
;	mov bx,0
	
	pop ax
	pop bx
	
	mov ax,4c00h
	int 21h
	
codesg ends
end