global _ft_isprint

section .text

_ft_isprint:
	cmp rdi, 32
	jl ret_no
	cmp rdi, 126
	jg ret_no
	mov rax, 1
	ret

ret_no:
	mov rax, 0
	ret
