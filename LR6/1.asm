.486
.model flat, c
.code
Funct PROC
	mov ecx, [esp+8]
	inc ecx
	mov al, '\'
	mov edi, [esp+4]
	add edi, ecx
	std
	repne scasb
	cld
	add edi, 2
	add ecx, 2
	sub ecx, [esp+8]
	not ecx
	add ecx, 2
	mov esi, [esp+12]
LP:	mov al, [edi]
	mov [esi], al
	inc esi
	inc edi
	loop LP
	ret
Funct ENDP
END
