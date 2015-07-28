global _ft_tolower

section .text

_ft_tolower:
	mov rax, rdi
	cmp rax, 65
	jl end
	cmp rax, 90
	jg end
	add rax, 32
	ret

end:
	ret
