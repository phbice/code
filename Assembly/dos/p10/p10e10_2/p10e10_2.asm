;DivDw 32位除法
;通过栈传递参数
;DivDw(dividend dword, divisor word)
;返回值：      sp
;        ss    xx xx xx xx xx xx
;              ----- -低----高--
;              余数      商
;2017-6-17 16:57
;TAB = 4

assume cs:code,ds:data,ss:stack

stack segment
	db 100 dup (?)
stack ends

data segment
	dividend dd 0ffffffffh
	divisor  dw 6
data ends

code segment
start:
	mov ax,stack
	mov ss,ax
	mov sp,100
	
	mov ax,data
	mov ds,ax
	
	push word ptr ds:[divisor]
	push word ptr ds:[dividend+2]
	push word ptr ds:[dividend]
	call far ptr DivDw_s
	pop cx
	pop ax
	pop dx
	
	mov ax,4c00h
	int 21h
code ends

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