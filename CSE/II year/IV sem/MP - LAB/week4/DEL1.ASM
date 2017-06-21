data segment
a db 8,7
list db 5,6,7,8,9,10
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
        jne do1
        je do2
    do1:inc si
        loop do
    do2:mov ah,[si+1]
        xchg ah,[si]
        inc si
        loop do2
		mov ah,0
		mov [si],ah
        dec dx
        inc di
        dec bx
        jnz rp
        code ends
        end start
