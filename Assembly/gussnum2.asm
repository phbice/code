assume cs:main ds:data ss:stack

stack segment stack
    db 64 dup(?)
stack ends

data segment

data ends

main segment
start:
    ;init
    mov ax, data
    mov ds, ax
    mov ax, stack
    mov ss, ax
    mov sp, 64
    
random:
    mov   ah, 2ch
    int   21h
    mov   al, dl 
    mov   ah, 0
    mov   bl, 10
    div   bl
ret

main ends
end start