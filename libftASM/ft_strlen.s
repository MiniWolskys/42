global _ft_strlen

section .text

_ft_strlen:
	mov		rcx, 0
	cmp		rdi, 0
	je		error
	xor		al, al
	dec		rcx
	repne	scasb
	inc		rcx
	not		rcx
	jmp		get_out

error:
	mov		rax, 0
	ret

get_out:
	mov		rax, rcx
	ret
