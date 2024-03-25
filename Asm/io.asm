global _start
section .text
_start:
	mov rax,1
	mov rbx,1
	mov rcx,hello
	syscall
	
section .data
hello: db 'hello world'
hello_len: equ $-hello	
