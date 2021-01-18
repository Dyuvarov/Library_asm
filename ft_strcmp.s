section .text
	global _ft_strcmp

_ft_strcmp:
	xor rax, rax	;rax = 0
	xor rbx, rbx	;rbx = 0
	xor al, al		;al = 0
	xor bl, bl		;bl = 0
	jmp loop
		
loop:
	mov al, byte[rdi]
	mov bl, byte[rsi]
	cmp al, 0
	je diff
	cmp bl, 0
	je diff
	cmp al, byte[rsi]
	jne diff
	inc rdi
	inc rsi
	jmp loop
	
diff:
	movzx rax, al
	movzx rbx, bl
	sub rax, rbx
	ret
