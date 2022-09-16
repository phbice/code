assume cs:code,ds:data,ss:stack

stack segment
	db 100 dup (?)
stack ends

data segment
	szYear  db '1975','1976','1977','1978','1979','1980','1981','1982'
			db '1983','1984','1985','1986','1987','1988','1989','1990'
			db '1991','1992','1993','1994','1995'
			;以上是21个年份
		
	dwSum   dd 16,22,382,1356,2390,8000,16000,24486,50065,97479,140417,197514
			dd 345980,590827,803530,1183000,1843000,2759000,3753000,4649000,5937000
			;以上是公司总收入
		
	wEmpNum dw 3,7,9,13,28,38,130,220,476,778,1001,1442,2258,2793,4037,5635,8226
			dw 11542,14430,15257,17800
			;以上是雇员人数
    dwAverage dd 21 dup (?)
	wShowStrArgs   dw 0,0,0,0
	Base dw 10
	i              dw 0
	szTemp   db ' '
		year db 10 dup(' ')
		sum  db 10 dup(' ')
		en   db 10 dup(' ')
		avg  db 10 dup(' ')
		     db 0

data ends

code segment
start:
	mov ax,stack
	mov ss,ax
	mov sp,100
	
	mov ax,data
	mov ds,ax
	
	mov word ptr ds:[wShowStrArgs],00000111B ;黑底白字
	mov word ptr ds:[wShowStrArgs+2],0        ;0行 0列
	mov word ptr ds:[wShowStrArgs+4],offset szTemp
	mov word ptr ds:[wShowStrArgs+6],ds

	mov cx,21
	mov si,0
	mov word ptr ds:[i],0
	s1:
		call i42si
		mov ax,ds:[szYear+si]
		mov ds:[year],ax
		mov ax,ds:[szYear+si+2]
		mov ds:[year+2],ax
		;^^ 年份储存在year中

		push word ptr ds:[dwSum+si+2]
		push word ptr ds:[dwSum+si]
		push ds:[Base]
		push ds
		mov ax,offset sum
		push ax
		call far ptr D2Str_s

		call i22si
		mov ax,0
		push ax
		push ds:[wEmpNum+si]
		push ds:[Base]
		push ds
		mov ax,offset en
		push ax
		call far ptr D2str_s

		push ds:[wEmpNum+si]
		call i42si
		push word ptr ds:[dwSum+si+2]
		push word ptr ds:[dwSum+si]
		call far ptr DivDw_s
		add sp,2 ;舍弃余数
		pop word ptr ds:[dwAverage+si]
		pop word ptr ds:[dwAverage+si+2]

		push word ptr ds:[dwAverage+si+2]
		Push word ptr ds:[dwAverage+si]
		push ds:[Base]
		push ds
		mov ax,offset avg
		push ax
		call far ptr D2Str_s

		push ds:[wShowStrArgs+6]    ;ds
		push ds:[wShowStrArgs+4]    ;si
		push ds:[wShowStrArgs+2]    ;0行 0列
		push ds:[wShowStrArgs]      ;黑底白字
		call far ptr ShowStr_s

		inc word ptr ds:[i]
		inc byte ptr ds:[wShowStrArgs+2] ;行号加一
		dec cx
		jcxz ok
	jmp near ptr s1
	ok:
	mov ax,4c00h
	int 21h
	
	i22si:
		mov si,ds:[i]
		add si,si
	ret
	i42si:
		mov si,ds:[i]
		add si,si
		add si,si
	ret
code ends

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
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

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;D2Str
;将数字转化为字符串
;通过栈传递参数
;      bp          bp+4  bp+6  bp+8  bp+10 bp+12
;ss:   xx xx xx xx xx xx xx xx xx xx xx xx xx xx
;      ----- ----- ----- ----- ----- ----- -----
;       IP    CS    SI    DS   基数  低位  高位
;ds:si 指向字符串的首地址

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
;	mov byte ptr ds:[si],0 ;为字符串添 00H 作结尾

	pop bp ;;;;;;;;;;;;;;;;
	pop si ;;;;;;;;;;;;;;;;
	pop ds ;恢复寄存器的值
	pop cx ;;;;;;;;;;;;;;;;
	pop ax ;;;;;;;;;;;;;;;;
	
	retf 10
D2Str ends

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;DivDw 32位除法
;通过栈传递参数
;DivDw(dividend dword, divisor word)
;返回值：      sp
;        ss    xx xx xx xx xx xx
;              ----- -低----高--
;              余数      商
;2017-6-17 16:57
;TAB = 4

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

end start