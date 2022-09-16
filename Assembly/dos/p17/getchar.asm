;int 16h
;(ah) = 0 : 输入单个字符
;返回值：(ah) = 扫描码
;        (al) = ascii码
;2017-6-20 11:05

assume cs:code,ss:stack

stack segment stack
	db 100 dup (?)
stack ends

code segment
start:
	mov ah,0
	int 16h

	mov ah,0eh
	mov bl,00000111B
	int 10h

	mov ah,4ch
	int 21h
code ends

end start