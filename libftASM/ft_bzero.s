global		_ft_bzero

section		.text

_ft_bzero:
	cmp		rdi, 0
	je		error
	cmp		rsi, 0
	je		error
	mov		rcx, 0
	jmp		loop

loop:
	mov		byte[rdi], 0
	inc		rcx
	inc		rdi
	cmp		rdi, 0
	je		get_out
	cmp		rsi, rcx
	je		get_out
	jmp		loop

error:
	ret

get_out:
	ret
