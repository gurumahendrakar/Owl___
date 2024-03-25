[ org 0x0100 ]
jmp start
data: dw 25
change_data:
	push bp;
	mov bp,sp
	mov ax,1
	mov bx,2
	add sp,4	
	pop bx
	pop ax
	ret
start:
	mov ax,3
	mov bx,4
	push ax
	push bx
	call change_data
end:
mov ax,0x4c21
int 0x21
