data segment
a db 02h
x db 01010101b
y db 11111111b
c db ?
d db ?
e db ?
f db ?
data ends
code segment
assume cs:code,ds:data
start:mov ax,data
      mov ds,ax
      mov al,a
      inc al
      mov c,al
      dec al
      mov d,al
      neg al
      mov f,al
      not al
      mov e,al
      mov ah,4ch
      int 21h
      code ends
      end start
