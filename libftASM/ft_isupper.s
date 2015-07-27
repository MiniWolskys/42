global _ft_isupper

section .text

_ft_isupper:
	cmp edi, 'A'
	jl ret_no
	cmp edi, 'Z'
	jg ret_no
	mov eax, 1
	ret

ret_no:
	mov eax, 0
	ret
