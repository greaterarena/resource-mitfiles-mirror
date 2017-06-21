data segment
a db 5
fact dw ?
data ends

code segment
assume cs:code, ds:data
start: mov ax,data
       mov ds, ax
       mov ax,0001h
       mov cl,a
       call facto
       mov fact,ax
       jmp exit
       facto proc near
       mul cl
       dec cl
       cmp cl,01h
       jz endproc
       call facto
endproc: ret
         facto endp
exit:    mov ah,4ch
         int 21h
code ends
end start
