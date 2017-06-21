data segment
a dw 0004h
b dw 00FFh
c dw ?,?
data ends
code segment
assume cs:code, ds:data
start:mov ax,data
      mov ds,ax
      mov ax,a
      mov bx,b
      mul bx
      mov c,ax
      mov c+2,dx
      mov ah,4ch
int 21h
code ends
end start