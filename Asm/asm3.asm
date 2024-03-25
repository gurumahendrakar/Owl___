


[ org 0x0100 ]


xor ax,ax
mov bx,3
loop:
	sub bx,1
	jnz loop

mov ax,0x4c00
int 0x21


