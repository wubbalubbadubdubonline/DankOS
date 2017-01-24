; *****************************************************
;     Moves the cursor to the next line (like a \n)
; *****************************************************

new_line:

push esi

mov si, 0x0A
push 0x01
int 0x80

pop esi
iret
