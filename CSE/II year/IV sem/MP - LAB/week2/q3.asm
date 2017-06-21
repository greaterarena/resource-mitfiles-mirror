data segment
a dw 0101h,0101h
b dw 0101h,0101h
c dw ?,?,?,?
data ends
code segment
assume cs:code,ds:data
start:	mov ax,data
	mov ds,ax
	mov ax,a
	mov bx,b
	mul bx
	mov c,ax
	mov cx,dx
	mov ax,a+2
	mul bx
	add cx,ax
	mov c+2,cx
	adc dx,0000h
	mov cx,dx
	mov bx,b+2
	mov ax,a
	mul bx
	add c+2,ax
	adc cx,dx
	mov c+4,cx
	mov ax,a+2
	mul bx
	add c+4,ax
	adc dx,0000h
	mov c+6,dx	
mov ah,4ch
int 21h
code ends
end start