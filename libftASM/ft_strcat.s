extern		_ft_strlen

global		_ft_strcat

section		.text

_ft_strcat:
	push	rdi
	cmp		rdi, 0
	je		error
	cmp		rsi, 0
	je		error
	mov		rcx, 0
	call	_ft_strlen
	pop		rdi
	push	rdi
	add		rdi, rax
	jmp		loop

loop:
	mov		al, [rsi]
	mov		[rdi], al
	cmp		al, 0
	je		get_out
	inc		rdi
	inc		rsi
	jmp		loop

get_out:
	pop		rax
	ret

error:
	pop		rax
	ret
