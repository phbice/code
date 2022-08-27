;letterc 将字符串中的小写字母转化为大写字母
;字符串以 00H 结尾
;ds:si 指向字符串首地址
;2017-6-19 12:03

assume cs:code,ds:data,ss:stack

stack segment
	db 100 dup (?)
stack ends

data segment
	db "Beginner's All-purpose Symbolic Instruction Code.",0
data ends

code segment
start:
	mov ax,stack
	mov ss,ax

	mov ax,data
	mov ds,ax
	mov si,0

	call letterc

	mov ax,4c00h
	int 21h
	
	letterc:
		push cx

		mov cx,0
		letterc_s:
			mov cl,byte ptr ds:[si]
			jcxz letterc_ok

			cmp cl,'a'
			jb letterc_not_lower_case
			cmp cl,'z'
			ja letterc_not_lower_case
				and byte ptr ds:[si],11011111B
			letterc_not_lower_case:
			inc si
		jmp short letterc_s
		letterc_ok:

		pop cx
	ret
code ends

end start