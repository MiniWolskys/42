global _ft_isalpha

section .text

_ft_isalpha:
	cmp rdi, 91
	jl try_maj
	cmp rdi, 97
	jl ret_no
	cmp rdi, 122
	jg ret_no
	mov rax, 1
	ret

try_maj:
	cmp rdi, 65
	jl ret_no
	mov rax, 1
	ret

ret_no:
	mov rax, 0
	ret
