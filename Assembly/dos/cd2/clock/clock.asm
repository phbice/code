;clock

assume cs:code,ds:data,ss:stack

stack segment stack
	db 100 dup (?)
stack ends

data segment
	gettime_string db '  /  /  ',' ','  :  :  ',0
;              01 34 67   8   9a cd f

	gettime_table1  dw 9,8,7,4,  2,  0
	gettime_table2  dw 0   + offset gettime_string
					dw 3   + offset gettime_string
					dw 6   + offset gettime_string
					dw 9   + offset gettime_string
					dw 0ch + offset gettime_string
					dw 0fh + offset gettime_string
data ends

code segment
start:
	mov ax,data
	mov ds,ax
	
	clearInput: ;清除键盘缓存区
		mov ah,01h
		int 16h
		jz clearInput_end ;缓存区清空则结束循环
		mov ah,0
		int 16h ;删除一个键盘输入
	jmp short clearInput
	clearInput_end:

	mov ah,03h
	mov bh,0
	int 10h ;获取光标位置
	s1:
		call gettime

		mov si,offset gettime_string
		mov cl,00000111B
		call ShowStr

		mov ah,01h
		int 16h
	jz s1 ;无字符输入则循环

	
	mov ah,0
	int 16h ;删除一个键盘输入

	mov ah,4ch
	int 21h

gettime:
	push ax
	push bx
	push cx
	push si

	mov bx,0
	mov cx,6
	gettime_s1:
		mov ax,gettime_table1[bx]
		call getData
		mov si,gettime_table2[bx]
		call bcd2c
		add bx,2
	loop gettime_s1

	pop si
	pop cx
	pop bx
	pop ax
ret

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

;ShowStr 显示字符串
;通过寄存器传递参数
;(dh) = 行号 （0-24）
;(dl) = 列号 （0-79）
;(cl) = 颜色  7   6 5 4    3    2 1 0
;             BL  R G B    I    R G B
;            闪烁 背景    高亮  前景
;ds:si 指向字符串的首地址
;字符串应以零结尾
;无返回值
;2017-6-17 15:59

ShowStr:
	push ax
	push bx
	push cx
	push dx
	push si
	push es
	
	mov ax,0B800H
	mov es,ax
	mov al,160
	mul dh      ;计算行地址
	mov bx,ax
	add dl,dl   ;计算列地址
	mov dh,0
	add bx,dx   ;行、列地址相加得首字符在显存中的偏移地址
	mov al,cl	;颜色参数转移到 al 中
	mov cx,0
	ShowStr_s1:
		mov cl,ds:[si]
		jcxz ShowStr_ok   ;读取到 00H 则终止循环
		inc si

		mov es:[bx],cl	;;;;;;;;;;;;;;;;;;;;;;;;;
		inc bx			;
		mov es:[bx],al	;将字符与颜色参数依次写入显存
		inc bx			;;;;;;;;;;;;;;;;;;;;;;;;;

		jmp short ShowStr_s1
	ShowStr_ok:
	pop es
	pop si
	pop dx
	pop cx
	pop bx
	pop ax
	
ret

code ends


end start