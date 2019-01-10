datas segment
	sentence db 50h,?,50h dup(?) ;定义一个50h的内存空间
	keyword db 10h,?,10h dup(?) ;keyword关键字，空间大小为10h
	match db 0ah,0dh,"Match at location: $" ;$代表当前指令的地址
	nomatch db 0ah,0dh,"No match$" 
	msg3 db 0ah,0dh,"Enter keyword:$"
	msg4 db 0ah,0dh,"Enter sentence:$"
	msg5 db "h of the sentence$"
datas ends ;数据段结束

stacks segment 
stacks ends 

codes segment
	assume cs:codes,ds:datas,ss:stacks 
start: 
	mov ax,datas 
	mov ds,ax
	
	lea dx,msg3 
	mov ah,09h 
	int 21h		;输出msg3:enter keyword
	
	lea dx,keyword 
	mov ah,0ah 
	int 21h		;读入带查找字符到keyword中

again:
	lea dx,msg4
	mov ah,09h
	int 21h		;输出msg4:enter sentence
	
	lea dx,sentence
	mov ah,0ah 
	int 21h		;读入带查找字符到keyword中
	
	lea si,sentence 
	lea di,keyword 
	mov ch,0 
	mov cl,[si+1] 	;cl:sentence的长度
	mov bl,[di+2] 	;bl:keyword的第一个字符
	add si,2
l: 
	mov bh,[si] 	;bh:sentence的第一个字符
	inc si 
	cmp bl,bh 	;比较bl和bh，如果相等则转移到begin
	jz begin 
	loop l		;l循环cx自减1，判断cx如果不为零则循环
	jmp nomat	;跳转到不匹配
 
begin: 
	push si 	;把si和cx压入栈进入内层循环
	lea di,keyword 
	push cx 
	mov ch,0 
	mov cl,[di+1] ;cl:keyword的长度
	
	dec cx ;如果cx等于0则跳转到mat
	jz mat 
l1:
	mov bl,[si] 	;bl:sentence的第二个字符
	mov al,[di+3] 	;al:keyword的第二个字符
	cmp bl,al		;比较bl和bh，如果不相等则转移到cont
	jnz cont 
	
	inc si 
	inc di 
	loop l1		;l1循环cx自减1，判断cx如果不为零则循环
	jmp mat 
cont:
	pop cx		;cx和si出栈
	pop si 
	lea di,keyword 
	mov bl,[di+2] 
	loop l		;l循环cx自减1，判断cx如果不为零则循环
nomat:
	lea dx,nomatch 
	mov ah,09h 
	int 21h 	;输出不匹配
	jmp error   ;结束程序
mat: 
	lea dx,match 
	mov ah,09h 
	int 21h 	;输出匹配
	
	pop cx 
	mov al,[sentence+1]	;al:sentence的长度
	sub al,cl
	inc al
	mov bl,al 
	
	call convert 
	lea dx,msg5
	mov ah,09h
	int 21h		;输出msg5:h of the sentence
	
	jmp again
error: 
	mov ah,4ch 
	int 21h 	;结束程序
	
convert proc near 
	mov ch,2
rotate:
	mov cl,4 
	rol bl,cl	;将dl中的数循环左移4位,也就是把dl最高4位,放到dl的最低4位上去
	mov al,bl 
	and al,0fh	;取低4位
	add al,30h  ;加上30h 从这里开始将4位二进制数转成16进制ASCII码	
	cmp al,3ah
	jl print	;小于9就跳转，直接打印
	add al,7h	;否则加上7h变为a-f
print:
	mov dl,al
	mov ah,02 
	int 21h		;显示dl字符的ascii码	
	dec ch
	jnz rotate	;ch不为零就跳转到rotate
	ret 
convert endp 

codes ends 
end start 
end




