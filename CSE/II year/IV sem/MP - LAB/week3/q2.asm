data segment
a db 09h
b db 06h
g db ?
l dw ?
data ends

code segment
assume cs:code, ds: data
start: mov ax, data
	mov ds,ax
	mov al,a
	mov bl, b
   do:	cmp al,bl
	Jz do1
	Jg do2
	Jl do3
   do1:	mov g, al
	mov al, a
	mov bl,b
	mul bl
	mov bl, g
	div bl
	mov l, al
	jmp do4
   do2: sub al,bl
	jmp do
   do3: sub bl,al
	jmp do
   do4: mov ah,4ch
	int 21h
code ends
end start