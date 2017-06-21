data segment
list db 15,03,01,08
count equ 3
data ends

code segment
assume cs:code,ds:data
start:
        mov ax,data
        mov ds,ax
        mov dx,count
   rep1:mov cx,dx
        lea si,list
   rep2:mov al,[si]
        cmp al,[si+1]
        jl do
        xchg [si+1],al
        xchg [si],al
     do:add si,1
        loop rep2
        dec dx
        jnz rep1
        code ends
        end start
