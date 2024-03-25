


[ org 0x0100 ]


xor ax,ax
mov bx,0
loop:
	add bx,1
	cmp bx,3
	jne loop	

mov ax,0x4c00
name: dw 2
int 0x21


