data segment
a db 8,7
list db 5,6,9,10,?,?
count equ 4
count2 equ 2
data ends

code segment
assume cs:code,ds:data
start:
        mov ax,data
        mov ds,ax
        mov bx,count2
        lea di,a
		mov dx,count
     rp:lea si,list        
        mov cx,dx
        mov ah,[di]
     do:mov al,[si]
        cmp ah,al
        jg do1
        jl do2
    do1:inc si
        loop do
    do2:xchg ah,[si]
        inc si
        loop do2
        mov [si],ah
        inc dx
        inc di
        dec bx
        jnz rp
        code ends
        end start
