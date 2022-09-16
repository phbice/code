;ShowStr 显示字符串
;通过栈传递参数
;     bp    bp+2  +4    +6      +8    +10
;ss:  xx xx xx xx xx xx xx   xx xx xx xx xx
;     ----- ----- ----- ------- ----- -----
;	   IP    CS   颜色 行号 列号 SI    DS
;ds:si 指向字符串的首地址
;字符串应以零结尾
;行号 （0-24）
;列号 （0-79）
;颜色  7   6 5 4    3    2 1 0
;      BL  R G B    I    R G B
;     闪烁 背景    高亮  前景
;无返回值
;2017-6-18 15:58

assume cs:code,ds:data,ss:stack

stack segment
	db 100 dup (?)
stack ends

data segment
	db 'Hello world!',0
data ends

code segment
start:
	mov ax,stack
	mov ss,ax
	mov sp,100
	
	mov ax,data
	mov ds,ax
	
	mov si,0
	mov dh,33        ;33列
	mov dl,0         ;0行
	mov cl,00000010B ;黑底绿字

	push ds
	push si
	push dx
	push cx
	call far ptr ShowStr_s

	mov ax,4c00h
	int 21h
code ends

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

; assume cs:ShowStr
; ShowStr segment
; ShowStr_s:
	; push ax
	; push bx
	; push cx
	; push dx
	; push si
	; push es
	
	; mov ax,0B800H
	; mov es,ax
	; mov al,160
	; mul dh      ;计算行地址
	; mov bx,ax
	; add dl,dl   ;计算列地址
	; mov dh,0
	; add bx,dx   ;行、列地址相加得首字符在显存中的偏移地址
	; mov al,cl	;颜色参数转移到 al 中
	; mov cx,0
	; ShowStr_s1:
		; mov cl,ds:[si]
		; jcxz ShowStr_ok   ;读取到 00H 则终止循环
		; inc si

		; mov es:[bx],cl	;;;;;;;;;;;;;;;;;;;;;;;;;
		; inc bx			;
		; mov es:[bx],al	;将字符与颜色参数依次写入显存
		; inc bx			;;;;;;;;;;;;;;;;;;;;;;;;;

		; jmp short ShowStr_s1
	; ShowStr_ok:
	; pop es
	; pop si
	; pop dx
	; pop cx
	; pop bx
	; pop ax
	
	; retf
; ShowStr ends