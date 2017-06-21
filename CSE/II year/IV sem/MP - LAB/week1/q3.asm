data segment
a db 07h
b db 03h
c db ?
data ends
code segment
assume cs:code,ds:data
start:mov ax,data
      mov ds,ax
      mov ah,a
      mov al,b
      sub ah,al
      mov c,ah
      mov ah,4ch
      int 21h
      code ends
      end start
