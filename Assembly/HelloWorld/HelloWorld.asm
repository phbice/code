		.486
		.model flat,stdcall
		option casemap:none

__UNICODE__ equ 1
		
include		windows.inc
include		user32.inc
includelib	user32.lib
include		kernel32.inc
includelib	kernel32.lib

.data
szCaption	dw	4e00h,4e2ah,6d88h,606fh,6846h,0ff01h,0000h
				;“一个消息框！”
szText		dw	0048h,0065h,006Ch,006Ch,006Fh,0020h,0077h,006Fh,0072h,006Ch,0064h,0021h,0000h
				;“Hello world!”

.code
start:
	invoke 	MessageBoxW,\
			NULL,\
			offset szText,\
			offset szCaption,\
			MB_ICONINFORMATION or MB_OK
	invoke	ExitProcess,NULL
end	start