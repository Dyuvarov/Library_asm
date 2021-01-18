section .text
	global _ft_strcpy

_ft_strcpy:
	xor rax, rax	;rax = 0
	xor rcx, rcx	;rcx = 0
	jmp loop

loop:
	mov dl, byte[rsi + rcx]	;dl = src[i] 
	mov byte[rdi + rcx], dl	;dest[i] = dl
	cmp dl, 0				; if dl == '\0' goto end
	je end
	inc rcx					; ++i
	jmp loop
	
end:	
	mov rax, rdi			;	
	ret		
