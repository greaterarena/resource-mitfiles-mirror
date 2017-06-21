data segment
buffer db "welcome to manipal$"
msg db 0ah, 0dh, "error$"
f1 db 'C:\STUDENT\B1-18\Week6\myfile.txt',0
h1 dw ?
data ends

code segment
assume cs:code, ds:data
start: mov ax,data
       mov ds,ax

       mov dx,offset f1
       mov ah,3ch
       mov cx,00h
       int 21h
       jc err
       mov h1,ax

       mov dx,offset f1
       mov ah,3dh
       mov al,02h
       int 21h
       jc err
       mov h1,ax

       mov dx,offset buffer
       mov bx,h1
       mov cx,18
       mov ah,40h
       int 21h
       jc err

       mov bx,h1
       mov ah,3eh
       int 21h
       jmp done

err: mov dx,offset msg
     mov ah,09h
     int 21h
     
done: mov ah,4ch
      int 21h
code ends
end start
