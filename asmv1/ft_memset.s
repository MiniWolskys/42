global		_ft_memset

section		.text

_ft_memset:
	push	rdi
	cmp		rdi, 0
	je		get_out
	cmp		rdx, 0
	je		get_out
	mov		al, sil
	mov		rcx, rdx
	rep		stosb
	pop		rax
	mov		rdi, rax
	ret

get_out:
	pop		rax
	ret
