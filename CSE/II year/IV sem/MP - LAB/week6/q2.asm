data segment
str db "Enter a string:$"
str3 db "Press enter to close me!$"
str2 db "Your String - $"
str1 db 25,?,25 dup(0)
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
	mov dx,offset str2
	mov ah,09h
	int 21h
	lea si,str1
	mov bl,41h
	mov bh,61h
	mov ch,'$'
	mov cl,20h
	jmp cmpk
 
 cmpk:	cmp [si],ch
	je exit
	cmp [si],cl
	je spc_e
	cmp [si],bh
	jae sub_e
	cmp [si],bl
	jae add_e	
	inc si
	jmp cmpk

 sub_e: mov dl,[si]
	sub dl,20h
	clc
	call printchar
	jmp cmpk
 add_e:	mov dl,[si]
	add dl,20h
	clc
	call printchar
	jmp cmpk
 spc_e: mov dl,20h
	call printchar
	jmp cmpk

printchar proc near
	inc si
	mov ah,02h
	int 21h
	ret
printchar endp

 newline proc near
	mov dl,13d
	mov ah, 02h
	int 21h
	mov dl,10d
	mov ah, 02h
	int 21h
	ret
 newline endp
		
 exit:	call newline
	mov dx,offset str3
	mov ah,09h
	int 21h
	mov ah,01h
	int 21h
	mov ah,4ch
	int 21h	
code ends
end start
