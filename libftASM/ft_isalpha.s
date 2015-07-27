global _ft_isalpha

section .text

_ft_isalpha:
	cmp edi, 91
	jl try_maj
	cmp edi, 97
	jl ret_no
	cmp edi, 122
	jg ret_no
	mov eax, 1
	ret

try_maj:
	cmp edi, 65
	jl ret_no
	mov eax, 1
	ret

ret_no:
	mov eax, 0
	ret
