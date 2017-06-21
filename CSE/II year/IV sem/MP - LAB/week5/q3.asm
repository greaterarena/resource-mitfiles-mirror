dataseg segment
str db 'pondi','$'
strlen equ ($-str-1)
str1 db 'cherry','$'
str1len equ ($-str1-1)
str2 db ($-str-3) dup(?)
dataseg ends

codeseg segment
assume cs:codeseg,ds:dataseg,es:dataseg
start:mov ax,dataseg
mov ds,ax
mov es,ax
mov cx,strlen
mov si,offset str
mov di,offset str2
cld
rep movs str2,str
mov cx,str1len
mov si,offset str1
cld
rep movs str2,str1
mov byte ptr[di],'$'
mov ax,4c00h
int 21h
codeseg ends
end start

