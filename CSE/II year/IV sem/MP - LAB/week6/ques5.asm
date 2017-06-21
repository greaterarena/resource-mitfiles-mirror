data segment
f1 db 'C:\STUDENT\B1-18\Week6\readfile.txt',0
h1 dw ?
str db 25,?,25 dup(0)
data ends

code segment
assume cs:code, ds:data
start: mov ax,data
       mov ds,ax

       mov dx,offset f1
       mov ah,3dh
       mov al,02h
       int 21h
       mov h1,ax

       mov dx,offset str
       mov bx,h1
       mov cx,18
       mov ah,3Fh
       int 21h


       mov bx,h1
       mov ah,3eh
       int 21h
       
      mov dx,offset str
      mov ah,09h
      int 21h
      mov ah,4ch
      int 21h
code ends
end start
