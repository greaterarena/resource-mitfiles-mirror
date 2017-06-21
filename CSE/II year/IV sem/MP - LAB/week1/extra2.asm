Data segment
A db 00010101b
B db 01010101b
C db ?
D db ?
E db ?
data ends
code segment
assume cs:code,ds:data
Start:mov ax,data
      mov ds,ax
      mov ah,A
      MOV al,B
      AND al,ah
      mov C,al
      OR  al,ah
      mov D,al
      xor al,ah
      mov E,al
      mov ah,4ch
      int 21h
code ends
end start
