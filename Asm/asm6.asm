

SECTION .text:
GLOBAL _start
_start:
	mov eax,0x4
	mov ebx,1
	mov ecx,message
	mov edx,message_length
	int 0x80

	mov eax,0x1
	mov ebx,0
	int 0x80

SECTION .data
	message db 'Guru_Mahendrakar'
	message_length equ $-message

