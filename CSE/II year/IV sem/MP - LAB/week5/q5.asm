 dataseg segment
 str db 'assembler','$'
 str1 db 'ler','$'
 result db ?
 dataseg ends
 codeseg segment
 assume cs:codeseg,ds:dataseg,es:dataseg
 start:mov ax,dataseg
       mov ds,ax
       mov es,ax
       mov di,offset str
       mov al,'$'
       l1:
       mov si,offset str1
       mov ah,[si]
       cmp ah,[di]
       je l2
       scasb
       jnz l1
       jmp l4
       l2:
       cmp ah,al
       mov dl,ah
       je l3
       inc si
       inc di
       mov ah,[si]
       cmp ah,[di]
       je l2
       jmp l1
       l3:
       mov result,1
       jmp l5
       l4:
       mov result,0
       l5:
       mov ax,4c00h
       int 21h
       codeseg ends
       end start

