data segment
a dw 000Dh
b db 02h
c dw ?,?
data ends
code segment
assume cs:code,ds:data
start:mov ax,data
      mov ds,ax
      mov ax,a
      mov bl,b
      div bl
      mov c,al;quotient
      mov c+2,ah;remainder
mov ah,4ch
int 21h
code ends
end start
