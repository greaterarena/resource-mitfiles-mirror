data segment
msg db "enter string:$"
str1 db "pondi$"
str2 db 15,?,13 dup(0)
strlen1 equ ($-str1-1)
strlen2 equ ($-str2-1)
res db (strlen1+strlen2+1) dup(?)
data ends

code segment
assume cs:code, ds:data, es:data
start: mov ax,data
       mov ds,ax
       mov es,ax
       mov ah,09h
       mov dx,offset msg
       int 21h
       mov dx,offset str2
       mov ah,0ah
       int 21h
       mov cx,strlen1
       lea si,str1
       lea di,res
       cld
       rep movs res,str1
       mov cx,strlen2
       lea si,str2
       rep movs res,str2
       mov al,'$'
       mov [di],al
       mov ah,4ch
       int 21h
code ends
end start

       lea str2

