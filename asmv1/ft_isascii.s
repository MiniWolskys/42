global _ft_isascii

section .text

_ft_isascii:
	cmp rdi, 0
	jl ret_no
	cmp rdi, 127
	jg ret_no
	mov rax, 1
	ret

ret_no:
	mov rax, 0
	ret
