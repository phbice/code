;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;D2Str
;将数字转化为字符串
;通过栈传递参数
;      bp          bp+4  bp+6  bp+8  bp+10 bp+12
;ss:   xx xx xx xx xx xx xx xx xx xx xx xx xx xx
;      ----- ----- ----- ----- ----- ----- -----
;       IP    CS    SI    DS   基数  低位  高位
;ds:si 指向字符串的首地址
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;TAB = 4
;2017-6-17 22:19

assume cs:code,ds:data,ss:stack

stack segment
	db 100 dup (?)
stack ends

data segment
	digit  dd 12345678  ;BC614Eh
	string db 11 dup (?);FFFFFFFFh = 4'294'967'295
data ends

code segment
start:
	mov ax,stack
	mov ss,ax
	mov sp,100

	mov ax,data
	mov ds,ax

	mov ax,ds:[digit]
	mov dx,ds:[digit+2]
	mov cx,10
	mov si,offset string
	push dx ;高位
	push ax ;低位
	push cx ;基数 10
	push ds ;
	push si ;ds:si 指向字符串
	call far ptr D2Str_s

	mov si,offset string
	mov dh,33        ;33列
	mov dl,11        ;11行
	mov cl,00000010B ;黑底绿字
	push ds ;
	push si ;ds:si 指向字符串
	push dx ;行、列号
	push cx ;颜色
	call far ptr ShowStr_s

	mov ax,4c00h
	int 21h
code ends

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;D2Str
;将数字转化为字符串
;通过栈传递参数
;      bp          bp+4  bp+6  bp+8  bp+10 bp+12
;ss:   xx xx xx xx xx xx xx xx xx xx xx xx xx xx
;      ----- ----- ----- ----- ----- ----- -----
;       IP    CS    SI    DS   基数  低位  高位
;ds:si 指向字符串的首地址
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

assume cs:D2Str
D2Str segment
D2Str_s:
	push ax ;;;;;;;;;;;;;;;;
	push cx ;;;;;;;;;;;;;;;;
	push ds ;保护寄存器的值
	push si ;;;;;;;;;;;;;;;;
	push bp ;;;;;;;;;;;;;;;;

	mov bp,sp
	add bp,10
    mov ds,[bp+6]
	mov si,[bp+4]

	mov ax,0 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	push ax  ;;00H 压入栈底，作为字符串的结尾

	D2Str_s1:
		push [bp+8]          	;基数作除数
		push [bp+12]         	;被除数的高位
		push [bp+10]         	;被除数的低位
		call far ptr DivDw_s 	;做除法
		pop ax               	;余数即为 X 进制数码 （X 为基数）
		pop [bp+10]          	;商的低位
		pop [bp+12]          	;商的高位

		add ax,'0'           	;将十进制数码转化为字符串
		push ax              	;并压入栈中

		push cx       			;保护 (cx)
		mov cx,[bp+12]			;
		or  cx,[bp+10]			;当且仅当 [bp+12] == 0 且[bp+10] == 0 ，即商为零时，(cx) == 0
		jcxz D2Str_ok1			;(cx) == 0,即商等于 0 时，结束循环
		pop cx        			;恢复 (cx)

	jmp short D2Str_s1
	D2Str_ok1:
	pop cx             ;恢复 (cx)，同时使栈顶归位

	D2Str_s2:
		pop cx         ;字符出栈，字符储存在 cl 中
		jcxz D2Str_ok2 ;出现 00h ，说明字符串已结束，则结束循环
		mov ds:[si],cl 
		inc si
	jmp short D2Str_s2
	D2Str_ok2:
	mov byte ptr ds:[si],0 ;为字符串添 00H 作结尾

	pop bp ;;;;;;;;;;;;;;;;
	pop si ;;;;;;;;;;;;;;;;
	pop ds ;恢复寄存器的值
	pop cx ;;;;;;;;;;;;;;;;
	pop ax ;;;;;;;;;;;;;;;;
	
	retf 10
D2Str ends

assume cs:DivDw
DivDw segment
DivDw_s:
	push ax
	push dx
	push bp

	mov bp,sp
	add bp,6
;	[bp+4] 被除数 低位
;	[bp+6] 被除数 高位                          ;                       商的高位      商的低位
;	[bp+8] 除数                                 ;                     xx xx xx xx   xx xx xx xx
	mov dx,0                                    ;                    __________________________
	mov ax,[bp+6]                               ;       xx xx xx xx / xx xx xx xx | xx xx xx xx 
	div word ptr [bp+8]                         ;                     xx xx xx xx
	push ax	            ;商的高位               ;                     -----------
	mov ax,[bp+4]       ;被除数的低位           ;                     xx xx xx xx   xx xx xx xx
	div word ptr [bp+8] ;dx 为上一次除法的余数  ;                 余数作被除数的高位
	                    ;作被除数的高位         ;		
	mov [bp+6],ax       ;商的低位               ;
	pop [bp+8]          ;商的高位               ;
	mov [bp+4],dx       ;余数                   ;
	
	pop bp
	pop dx
	pop ax
	retf
DivDw ends

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;ShowStr 显示字符串
;通过栈传递参数
;     bp    bp+2  +4    +6      +8    +10
;ss:  xx xx xx xx xx xx xx   xx xx xx xx xx
;     ----- ----- ----- ------- ----- -----
;	   IP    CS   颜色 行号 列号 SI    DS
;
;ds:si 指向字符串的首地址
;字符串应以零结尾
;行号 （0-24）
;列号 （0-79）
;颜色  7   6 5 4    3    2 1 0
;      BL  R G B    I    R G B
;     闪烁 背景    高亮  前景
;无返回值
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

assume cs:ShowStr
ShowStr segment
ShowStr_s:
	push ax
	push bx
	push cx
	push ds
	push es
	push si
	push bp

	mov bp,sp
	add bp,14

	mov ax,0B800H
	mov es,ax

	mov ds,[bp+10]
	mov si,[bp+8]

	mov ax,160
	mul byte ptr [bp+6]      ;计算行地址
	mov bx,ax                ;行地址存于 bx 中
	mov al,[bp+7]            ;读取列号
	add al,al                ;计算列地址
	mov ah,0
	add bx,ax       ;行、列地址相加得首字符在显存中的偏移地址
	mov al,[bp+4]	;颜色参数转移到 al 中
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
	pop bp
	pop si
	pop es
	pop ds
	pop cx
	pop bx
	pop ax

	retf 8
ShowStr ends

end start