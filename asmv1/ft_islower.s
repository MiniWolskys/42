global _ft_islower

section .text

_ft_islower:
	cmp rdi, 'a'
	jl ret_no
	cmp rdi, 'z'
	jg ret_no
	mov rax, 1
	ret

ret_no:
	mov rax, 0
	ret
