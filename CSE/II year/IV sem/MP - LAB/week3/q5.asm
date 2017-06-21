data segment
asc dw 3831h,3531h
bcd db ?,?
count db 02
data ends

code segment
assume cs:code,ds:data
start: mov ax,data
       mov ds,ax
       mov cl,4
       lea si,bcd
       lea di,asc
do: mov ax,[di]
    sub ax,3030h
    rol al,cl
    shr ax,cl
    mov [si],al
    inc di
    inc di
    inc si
    dec count
    jnz do
    mov ah,4ch
    int 21h
    code ends
    end start
