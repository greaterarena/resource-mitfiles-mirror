data segment
str db "Enter a string:$"
str3 db "Press enter to close me!$"
str2 db "Number of words in above sting - $"
str1 db 25,?,15 dup(0)
data ends

code segment
assume cs:code, ds:data
 start:	mov ax,data
	mov ds,ax
	mov dx,offset str
	mov ah, 09h
	int 21h
	mov dx,offset str1
	mov ah, 0ah
	int 21h
	call newline
	lea si,str1
	mov al,' '
	mov ah,'$'
	mov cl,00h
	jmp count
 
 count:	cmp [si],ah
	je exit
	cmp [si],al
	je inky
	inc si
	jmp count

 inky:	inc si
	inc cl
	jmp count
 
 newline proc near
	mov dl,13d
	mov ah, 02h
	int 21h
	mov dl,10d
	mov ah, 02h
	int 21h
	ret
 newline endp
		
 exit:	mov dx,offset str2
	mov ah,09h
	int 21h
	mov dl,cl
	add dl,30h
	mov ah,02h
	int 21h
	call newline
	mov dx,offset str3
	mov ah,09h
	int 21h
	mov ah,01h
	int 21h
	mov ah,4ch
	int 21h	
code ends
end start
