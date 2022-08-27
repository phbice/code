;端口读写
;CMOS RAM: 70h 地址
;          71h 数据
;2017-6-19 21:38

assume cs:code,ss:stack

stack segment stack
	db 100 dup (?)
stack ends

; data segment
	; db 0
; data ends

code segment
start:
	mov al,2
	out 70h,al
	in  al,71h

	nop

	mov al,2
	out 70h,al
	mov al,0
	out 71h,al

	nop

	mov al,2
	out 70h,al
	in al,71h
	mov ah,4ch
	int 21h
code ends

end start