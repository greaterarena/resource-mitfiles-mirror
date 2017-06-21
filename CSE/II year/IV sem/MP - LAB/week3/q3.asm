data segment
fib db 10 dup(0)
data ends

code segment
assume cs:code, ds:data
start: mov ax,data
       mov ds,ax
       mov cl,08
       mov si,offset fib
       mov al,[si]
       inc si
       mov bl, 01h
       mov [si],bl
do: inc si
    add al, [si-2]
    add al,[si-1]
    mov [si],al
    mov al,00h
    dec cl
    jnz do
mov ah,4ch
int 21h
code ends
end start
