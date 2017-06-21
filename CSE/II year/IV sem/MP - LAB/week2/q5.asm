data segment
a dw 000Ah,0000h
b dw 0002h
c dw ?,?
data ends
code segment
assume cs:code,ds:data
start:mov ax,data
      mov ds,ax
      mov ax,a
      mov dx,a+2
      mov cx,b
      div cx
      mov c,ax;quotient
      mov c+2,dx;remainder
mov ah,4ch
int 21h
code ends
end start
