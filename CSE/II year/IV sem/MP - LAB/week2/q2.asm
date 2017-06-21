data segment
a dw 0304h,0102h
b dw 0101h
c dw ?,?,?
data ends
code segment
assume cs:code,ds:data
start:mov ax,data
      mov ds,ax
      mov ax,a
      mov bx,b
      mul bx
      mov c,ax
      mov cx,dx
      mov ax,a+2
      mul bx
      add ax,cx
      adc dx,0000h
      mov c+2,ax
      mov c+4,dx
      mov ah,4ch
      int 21h
      code ends
      end start
