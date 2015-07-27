global _ft_isprint

section .text

_ft_isprint:
	cmp edi, 32
	jl ret_no
	cmp edi, 126
	jg ret_no
	mov eax, 1
	ret

ret_no:
	mov eax, 0
	ret
