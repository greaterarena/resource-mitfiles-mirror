data segment
list db 1,2,3,4,5,6,7,8,9,10
sum db ?
data ends

code segment
assume cs:code, ds:code
start: mov ax,data
       mov ds, ax
       mov cl,09
       mov si,offset list
       mov al,[si]
do: inc si
    add al,[si]
    dec cl
    jnz do
    mov sum,al
    mov ah,4ch
    int 21h
code ends
end start

