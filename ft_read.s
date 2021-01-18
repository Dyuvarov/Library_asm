section .text
	global _ft_read
	extern ___error

_ft_read:
	mov	rax, 0x2000003	;to syscall read
	syscall
	jc error
	ret

error:
	push rax			;save syscall return value
	call ___error
	pop rdi				;get syscall return value in rdx
	mov [rax], rdi		;set errno value
	mov rax, -1			;set return value
	ret	
