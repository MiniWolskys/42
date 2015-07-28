global		_ft_strcut

extern		_ft_strdup

section		.text

_ft_strcut:
	cmp		rdi, 0
	je		error
	cmp		byte [rdi], 0
	je		error
	dec		sil
	inc		rdi
	cmp		sil, 0
	jne		_ft_strcut
	call	_ft_strdup
	ret

error:
	mov		rax, 0
	ret
