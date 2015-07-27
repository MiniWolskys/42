global _ft_tolower

section .text

_ft_tolower:
	mov eax, edi
	cmp eax, 65
	jl end
	cmp eax, 90
	jg end
	add eax, 32
	ret

end:
	ret
