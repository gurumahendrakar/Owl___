[org 0x0100]


jmp start
list: dw 1,3,3,2,5,6
start:
mov cx,0
outerloop:
add cx,1
mov ax,6
cmp ax,cx
jz end
mov bx,0
innerloop:
mov ax,[list + bx]
mov dx,[list+ bx + 2]
cmp ax,dx
jbe nocondition
condition:
mov dx,[list + bx + 2]
mov [list + bx + 2],ax
mov [list + bx],dx
nocondition:
add bx,2
mov ax,8
cmp bx,ax
jnz innerloop
jz outerloop
end:
mov ax,0x4c21
int 0x21


