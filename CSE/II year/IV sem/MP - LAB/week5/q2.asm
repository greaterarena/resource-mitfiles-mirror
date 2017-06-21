 dataseg segment
 str db 'nitin','$'
 actlen equ ($-str-1)
 str1 db actlen dup(?),'$'
 res db ?
 dataseg ends

 codeseg segment
 assume cs:codeseg,ds:dataseg,es:dataseg
 start:mov ax,dataseg
       mov ds,ax
       mov es,ax
       mov si,offset str
       mov di,offset str1
       mov cx,actlen
       add si,actlen
    l1:dec si
       mov al,[si]
       mov[di],al
       inc di
       dec cx
       jnz l1
       mov di,offset str1
       mov cx,actlen
       cld
       repe cmpsb
       jnz l2
       mov res,01
       jmp l3
    l2:mov res,00
    l3:mov ax,4c00h
       int 21h
 codeseg ends
 end start