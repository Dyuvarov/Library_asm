section .text
	global _ft_strdup

	extern _malloc
	extern _ft_strlen
	extern _ft_strcpy
	extern ___error

_ft_strdup:
	push rdi			;saving str in stack
	call _ft_strlen		;rax = strlen(str);
	inc	rax				;++rax to '\0'
	mov	rdi, rax		;putting number of bytes to allocate in rdi
	call _malloc
	pop rsi				;return str from stack to rsi
	test rax, rax
	jz error			;protecting malloc
	mov rdi, rax		;putting allocated pointer to rdi
	call _ft_strcpy		;copy from rsi to rdi, rax = rdi
	ret

error:
	push rax
	call ___error
	pop rdi
	mov qword[rax], 12
	xor rax, rdi
	ret
		
