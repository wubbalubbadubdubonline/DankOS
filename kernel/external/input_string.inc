input_string:

;   Gets a string from keyboard (0x00 terminated).
;     maximum string length in EBX
;     buffer to save string to in ES:EDI

push ax
push ebx
push ecx
push edi

xor ecx, ecx
.loop:
	push 0x1C
	int 0x80
	cmp al, 0x08
	je .backspace
	cmp al, 0x0D
	je .enter
	test al, al
	jz .loop
	cmp ecx, ebx
	je .loop
	inc ecx
	push esi
	xor esi, esi
	mov si, ax
	push 0x01
	int 0x80
	pop esi
	a32 o32 stosb
	jmp .loop
.backspace:
	test ecx, ecx
	jz .loop
	push esi
	xor esi, esi
	mov si, 0x08
	push 0x01
	int 0x80
	pop esi
	dec edi
	dec ecx
	jmp .loop
.enter:
	xor al, al
	a32 o32 stosb
	pop edi
	pop ecx
	pop ebx
	pop ax
	iret
