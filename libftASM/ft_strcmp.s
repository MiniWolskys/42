global		_ft_strcmp

section		.text

_ft_strcmp:
	cmp		rdi, 0
	je		error
	cmp		rsi, 0
	je		error
	mov		al, byte [rsi]
	cmp		al, 0
	je		error
	cmp		byte [rdi], al
	jg		out_sup
	cmp		byte [rdi], al
	jl		out_inf
	inc		rdi
	inc		rsi
	jmp		_ft_strcmp

out_sup:
	mov		rax, 1
	ret

out_inf:
	mov		rax, -1
	ret

error:
	mov		rax, 0
	ret
