global _ft_isalnum

section .text

_ft_isalnum:
	cmp edi, 58
	jl check_digit
	cmp edi, 91
	jl check_maj
	cmp edi, 97
	jl ret_false
	cmp edi, 122
	jg ret_false
	mov eax, 1
	ret

check_digit:
	cmp edi, 48
	jl ret_false
	mov eax, 1
	ret

check_maj:
	cmp edi, 65
	jl ret_false
	mov eax, 1
	ret

ret_false:
	mov eax, 0
	ret
