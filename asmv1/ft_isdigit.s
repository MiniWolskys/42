global _ft_isdigit

section .text

_ft_isdigit:
	cmp rdi, '0'
	jl ret_no
	cmp rdi, '9'
	jg ret_no
	mov rax, 1
	ret

ret_no:
	mov rax, 0
	ret
