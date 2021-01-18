
section .text
	global _ft_write
	extern ___error

_ft_write:				
	mov	rax, 0x2000004	;to syscall write
	syscall
	jc	error			;if error return -1
	ret

error:
	push rax		;save syscall return value
	call ___error	
	pop rdi			;get syscall return value in rdi
	mov [rax], rdi	;set errno value 
	mov rax, -1		;set return value
	ret
