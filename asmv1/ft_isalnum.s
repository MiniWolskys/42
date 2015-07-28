global _ft_isalnum

section .text

_ft_isalnum:
	cmp rdi, 58
	jl check_digit
	cmp rdi, 91
	jl check_maj
	cmp rdi, 97
	jl ret_false
	cmp rdi, 122
	jg ret_false
	mov rax, 1
	ret

check_digit:
	cmp rdi, 48
	jl ret_false
	mov rax, 1
	ret

check_maj:
	cmp rdi, 65
	jl ret_false
	mov rax, 1
	ret

ret_false:
	mov rax, 0
	ret
