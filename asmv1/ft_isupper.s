global _ft_isupper

section .text

_ft_isupper:
	cmp rdi, 'A'
	jl ret_no
	cmp rdi, 'Z'
	jg ret_no
	mov rax, 1
	ret

ret_no:
	mov rax, 0
	ret
