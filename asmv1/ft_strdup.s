extern		_ft_strlen
extern		_malloc
extern		_ft_strcat

global		_ft_strdup

section 	.text

_ft_strdup:
	cmp		rdi, 0
	je		error
	push	rdi
	call	_ft_strlen
	mov		rdi, rax
	inc		rdi
	call	_malloc
	cmp		rax, 0
	je		error
	pop		rsi
	mov		rdi, rax
	call	_ft_strcat
	ret

error:
	mov		rax, 0
	ret
