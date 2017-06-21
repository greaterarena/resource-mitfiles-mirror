data segment
a dw 0065h
b dw 0034h
c dw ?
data ends
code segment
assume cs:code,ds:data
start:mov ax,data
      mov ds,ax
      mov ax,a
      mov bx,b
      sub ax,bx
      mov c,ax
      mov ah,4ch
      int 21h
      code ends
      end start
