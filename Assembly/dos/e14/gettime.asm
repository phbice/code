assume cs:code,ds:data,ss:stack

stack segment stack
	db 100 dup (?)
stack ends

data segment
	; year   db 0
	; month  db 0
	; day    db 0
	; hour   db 0
	; minute db 0
	; second db 0
	string db '  /  /  ',' ','  :  :  ',0ah,0
;              01 34 67   8   9a cd f

	table1  dw 9,8,7,4,  2,  0
	table2  dw 0   + offset string
	        dw 3   + offset string
			dw 6   + offset string
			dw 9   + offset string
			dw 0ch + offset string
			dw 0fh + offset string
data ends

code segment
start:
	mov ax,data
	mov ds,ax

	mov bx,0
	mov cx,6
	gettime_s1:
		mov ax,table1[bx]
		call getData
		mov si,table2[bx]
		call bcd2c
		add bx,2
	loop gettime_s1
	
	mov si,offset string
	mov bl,00000111B
	call ShowStr

	mov ah,4ch
	int 21h

getData:
	out 70h,al
	in  al,71h
ret

bcd2c:
	push ax
	push cx

	mov ah,al
	mov cl,4
	shr ah,cl
	and al,00001111B
	add ah,'0'
	add al,'0'
	mov ds:[si],ah
	mov ds:[si+1],al

	pop cx
	pop ax
ret

ShowStr: ;ds:si 指向以 00h 结尾的字符串
         ;bl    颜色
	push ax
	push si

	mov ah,0eh
;	mov bl,00000111B ;white
	ShowStr_s1:
		mov al,ds:[si]
		cmp al,0
		je finish
		inc si

		int 10h
	jmp short ShowStr_s1
	finish:
	pop si
	pop ax
ret
code ends

end start