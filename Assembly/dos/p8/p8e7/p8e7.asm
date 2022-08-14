;2017年6月14日 17:12
;结构化数据的储存
;TAB = 4
assume cs:code,ss:stack

stack segment
	db 100 dup (?)
stack ends

data segment
	szYear  db '1975','1976','1977','1978','1979','1980','1981','1982'
			db '1983','1984','1985','1986','1987','1988','1989','1990'
			db '1991','1992','1993','1994','1995'
			;以上是21个年份
		
	dwSum   dd 16,22,382,1352,2390,8000,16000,24486,50065,97479,140417,197514
			dd 345980,590827,803530,1183000,2759000,3753000,4649000,5937000
			;以上是公司总收入
		
	wEmpNum dw 3,7,9,13,28,38,130,220,476,778,1001,1442,2258,2793,4037,5635,8226
			dw 11542,14430,15257,17800
			;以上是雇员人数
data ends

table segment
	year    db 5 dup (' ')
	sum     db 5 dup (' ')
	NumE    db 3 dup (' ')
	average db 3 dup (' ')
	        db 20 dup ('year',' ','sum-',' ','ne',' ','??',' ')
table ends

code segment
start:
	mov ax,data
	mov ds,ax
	mov ax,table
	mov es,ax
	mov ax,stack
	mov ss,ax
	mov sp,100

	;以下为复制年份、总收入和雇员数
	mov bx,0 ;data seg year
	mov bp,0 ;table seg
	mov di,0 ;data seg EmpNum
	mov cx,21
	s1:
		mov ax,ds:wEmpNum[di]
		mov es:[bp].NumE,ax
		
		mov si,0
		push cx
		mov cx,2
		s2:
			mov ax,ds:szYear[bx][si]
			mov es:[bp].year[si],ax
			
			mov ax,ds:dwSum[bx][si]
			mov es:[bp].sum[si],ax
			
			add si,2
		loop s2
		pop cx
		
		add bx,4
		add di,2
		add bp,16
	loop s1
	
	;以下为计算人均收入
	mov bx,0
	mov cx,21
	s3:
		mov ax,es:[bx].sum[0]
		mov dx,es:[bx].sum[2]
		div word ptr es:[bx].NumE
		mov es:[bx].average,ax
		add bx,16
	loop s3

	mov ax,4c00h
	int 21h
code ends

end start