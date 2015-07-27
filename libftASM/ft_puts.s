%define SYSCALL(x) 0x2000000 | x
%define WRITE 4
%define STDOUT 1

global _ft_puts

extern _ft_strlen

section .data

msg:	db		10, 10

section .text

_ft_puts:
    cmp     rdi, 0
    je      error
	push	rdi
	call	_ft_strlen
	mov		rdx, rax
	pop		rsi
    mov		rdi, STDOUT
    mov     rax, SYSCALL(WRITE)
    syscall
    mov     rdx, 1
    mov     rdi, STDOUT
    lea     rsi, [rel msg]
    mov     rax, SYSCALL(WRITE)
    syscall
    mov     rax, 1
    ret

error:
    mov     rdx, 1
    mov     rdi, STDOUT
    lea     rsi, [rel msg]
    mov     rax, SYSCALL(WRITE)
    syscall
    mov     rax, 0
    ret
