data segment
list db 5,6,7,8,9
pos equ 3
count equ 5
count2 equ 2
data ends

code segment
assume cs:code,ds:data
start:
        mov ax,data
        mov ds,ax
        mov dx,count
        mov bx,count2
     rp:mov cx,pos
        lea si,list
     do:inc si
        loop do       
        dec si
        mov cx,dx
        sub cx,pos
        inc cx          
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
