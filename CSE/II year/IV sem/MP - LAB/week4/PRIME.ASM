data segment
a db 2,9
list db 10 dup(0)
count equ 1
data ends

code segment
assume cs:code,ds:data
start:
        mov ax,data
        mov ds,ax
        lea di,list
        mov bh,a
    do1:add bh,1
        cmp bh,a+1
        je do4
        mov bl,count
    do2:add bl,1
        cmp bl,bh
        je do3
		mov ah,0
		mov al,bh
        div bl
        cmp ah,0
        je do1
        jne do2
    do3:mov [di],bh
        inc di
        jmp do1
    do4:mov ah,4ch
        int 21h
        code ends
        end start
        
