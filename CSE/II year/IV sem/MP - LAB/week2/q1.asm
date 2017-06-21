data segment
a db 02h
b db 04h
c dw 0001h
data ends
code segment
assume cs:code,ds:data
start:mov ax,data
      mov ds,ax
      mov ax,a
      mul b
      mov c,ax
      mov ah,4ch
      int 21h
      code ends
      end start
