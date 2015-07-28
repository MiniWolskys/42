global		_ft_memcpy

section		.text

_ft_memcpy:
	cmp		rdi, 0
	je		error
	cmp		rsi, 0
	je		error
	cmp		rdx, 0
	je		error
	push	rdi
	mov		rcx, rdx
	rep		movsb
	pop		rax
	mov		rdi, rax
	ret

error:
	mov		rax, 0
	ret
