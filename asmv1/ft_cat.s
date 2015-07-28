%define		SYSCALL(x) 0x2000000 | x
%define		READ 3
%define		WRITE 4
%define		STDOUT 1
%define		BUFF_SIZE 2048

extern		_ft_strlen

global		_ft_cat

section		.data

buf:		times BUFF_SIZE db 0

section		.text

_ft_cat:
	cmp		rdi, 2147483647
	jge		error
	lea		rsi, [rel buf]
	jmp		loop

loop:
	push	rdi
	mov		rdx, BUFF_SIZE
	mov		rax, SYSCALL(READ)
	syscall
	cmp		rax, -1
	je		error
	push	rax
	mov     rdx, rax
    mov     rdi, STDOUT
    mov     rax, SYSCALL(WRITE)
    syscall
	pop		rax
	pop		rdi
	cmp		rax, 0
	jne		loop
	ret

error:
	ret
