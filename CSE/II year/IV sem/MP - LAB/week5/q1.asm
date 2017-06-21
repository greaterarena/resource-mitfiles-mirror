 dataseg segment
 a db 'January','$'
 len db ?
 dataseg ends

 codeseg segment
 assume cs:codeseg,ds:dataseg,es:dataseg
 start:mov ax,dataseg
       mov ds,ax
       mov es,ax
       mov di,offset a
       mov al,'$'
       mov ch,0

    li:inc ch
       cld
       scas a
       jnz li
       dec ch
       mov len,ch

 mov ax,4c00h
 int 21h
 codeseg ends
 end start


