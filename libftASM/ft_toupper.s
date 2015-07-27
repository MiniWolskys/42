global _ft_toupper

section .text

_ft_toupper:
	mov rax, rdi
	cmp rax, 97
	jl end
	cmp rax, 122
	jg end
	sub rax, 32
	ret

end:
	ret

