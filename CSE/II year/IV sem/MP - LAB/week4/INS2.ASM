data segment
a db 8,7
list db 5,6,9,?,?
pos equ 3
count equ 3
count2 equ 2
data ends

code segment
assume cs:code,ds:data
start:
        mov ax,data
        mov ds,ax
        mov dx,count
        mov bx,count2
        lea di,a
     rp:mov cx,pos
        lea si,list
     do:inc si
        loop do       
        dec si
        mov cx,dx
        sub cx,pos
		inc cx
        mov ah,[di]   
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
