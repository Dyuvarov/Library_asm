section .text
	global _ft_strlen

_ft_strlen:
	xor rax, rax
	jmp loop

loop:
	cmp byte[rdi + rax], 0
	je	end
	inc rax
	jmp loop
	
end:		
	ret	
