global _ft_isascii

section .text

_ft_isascii:
	cmp edi, 0
	jl ret_no
	cmp edi, 127
	jg ret_no
	mov eax, 1
	ret

ret_no:
	mov eax, 0
	ret
