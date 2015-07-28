global		_ft_swap

section		.text

_ft_swap:
	cmp		rdi, 0
	je		error
	cmp		rsi, 0
	je		error
	mov		rdx, [rdi]
	mov		rax, [rsi]
	mov		[rsi], rdx
	mov		[rdi], rax
	cmp		byte [rdi], 0
	je		check
	add		rdi, 8
	add		rsi, 8
	jmp		_ft_swap
	ret

check:
	cmp		byte [rsi], 0
	je		end
	add		rdi, 8
	add		rsi, 8
	jmp		_ft_swap

error:
	ret

end:
	ret
