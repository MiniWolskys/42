extern		_ft_strlen
extern		_malloc
extern		_ft_memcpy

global		_ft_strdup

section 	.text

_ft_strdup:
	cmp		rdi, 0
	je		error
	push	rdi
	call	_ft_strlen
	push	rax
	mov		rdi, rax
	inc		rdi
	call	_malloc
	cld
	cmp		rax, 0
	je		error
	pop		rcx
	pop		rsi
	mov		rdi, rax
	rep		movsb
	mov		byte [rdi], 0
	ret

error:
	mov		rax, 0
	ret
