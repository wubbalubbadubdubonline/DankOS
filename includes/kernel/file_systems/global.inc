; **********************************************************************************************
;     This file contains FAT routines that are callable from outside programs using int 0x80
; **********************************************************************************************



load_file:

; *********************************************
;     Loads a file from the specified drive
; *********************************************

; IN:
; es:bx		-->		Target segment:offset
; ds:si		-->		Must point to a filename (readable format)

; OUT:
; ecx		-->		File size (in bytes)

; Carry if failure

push ax
push bx
push dx
push si
push di
push bp
push es
push gs

mov cx, es

mov ax, 0x9000
mov gs, ax

mov word [gs:.TargetSegment], cx
mov word [gs:.TargetBuffer], bx

push 0x2B						; Get starting cluster and size
int 0x80

test ax, ax
jz .failure						; Check for success

push cx

mov cx, word [gs:.TargetSegment]
mov es, cx

mov bx, word [gs:.TargetBuffer]

push 0x13						; Get current drive
int 0x80

call fat12_load_chain			; Load chain into the buffer

pop cx

jmp .success

.failure:

mov bp, sp
add sp, 20		; Get to the flags
pop dx			; Pop and set carry flag
or dx, 0000000000000001b
push dx			; Put flags back in stack
mov sp, bp		; Restore stack
jmp .done

.success:

mov bp, sp
add sp, 20		; Get to the flags
pop dx			; Pop and clear carry flag
and dx, 1111111111111110b
push dx			; Put flags back in stack
mov sp, bp		; Restore stack

.done:

pop gs
pop es
pop bp
pop di
pop si
pop dx
pop bx
pop ax
iret


.TargetSegment dw 0x0000
.TargetBuffer  dw 0x0000



fat_get_metadata:

; ****************************************
;     Returns the metadata of an entry
; ****************************************

; IN: DS:SI file name

; OUT:
;      AX = starting cluster, 0x0000 if not found
;      BX = raw FAT time
;      ECX = file size
;      DX = raw FAT date

push si
push di
push ds
push es

push eax

mov ax, 0x9000
mov es, ax

mov di, .ConvertedName			; Convert to fat name
push 0x17
int 0x80

mov ds, ax

mov di, CurrentDirectoryCache
mov word [.EntryCounter], 0x0000

.next_entry:

mov si, .ConvertedName

inc word [.EntryCounter]

mov ah, byte [es:di]	; Byte from the directory table, first of entry
test ah, ah		; End of table?
jz .not_found

mov cx, 11
.check_name_loop:

lodsb			; Byte from the file name
mov ah, byte [es:di]	; Byte from table
inc di
cmp al, ah
jne .skip_entry
loop .check_name_loop

; FILE FOUND!!!

add di, 11				; Get raw creation time
mov ax, word [es:di]
mov word [.RawTime], ax

add di, 2				; Get raw creation date
mov ax, word [es:di]
mov word [.RawDate], ax

add di, 2				; Retrieve starting cluster
mov ax, word [es:di]
mov word [.Cluster], ax

add di, 2				; Get file size
mov eax, dword [es:di]
mov dword [.FileSize], eax

jmp .done

.skip_entry:

mov ax, 32
mov di, CurrentDirectoryCache
mul word [.EntryCounter]
add di, ax
jmp .next_entry

.not_found:

mov word [.Cluster], 0x0000

.done:

pop eax

mov ax, word [.Cluster]
mov bx, word [.RawTime]
mov ecx, dword [.FileSize]
mov dx, word [.RawDate]

pop es
pop ds
pop di
pop si
iret


.EntryCounter	dw	0x0000
.Cluster		dw	0x0000
.FileSize		dd	0x00000000
.RawDate		dw	0x0000
.RawTime		dw	0x0000
.ConvertedName	times 12 db 0x00



directory_scanner:

; **********************************************************
;     Scans the content of the directory (current drive)
; **********************************************************

; IN:
; ax		-->		Directory entry number

; OUT:
; es:di		-->		File name
; dl		-->		Directory flag (0x00 if file, 0xFF if directory)

; Carry if entry not found

push ax
push bx
push cx
push si
push di
push bp
push ds
push es

push dx

mov bx, 0x9000
mov ds, bx

mov word [.EntryNumber], ax
mov word [.TargetBuffer], di
mov ax, es
mov word [.TargetSegment], ax
mov word [.EntryCounter], 0x0000

mov es, bx

mov si, CurrentDirectoryCache

.next_entry:

mov di, .FatNameBuffer
lodsb	; Byte from the directory table, first of entry
dec si
test al, al		; End of table?
jz .failure

mov cx, 11
rep movsb
xor al, al
stosb

; Check for special reserved entries

mov al, byte [si-11]	; Check for deleted entry
cmp al, 0xE5
je .skip_entry

mov al, byte [si]		; Check for a vfat entry (ignore it)
cmp al, 0x0F
je .skip_entry

mov al, byte [si]		; Check for a dir entry
and al, 0x10
jz .no_directory
mov byte [.DirectoryFlag], 0xFF
jmp .directory_check_done
.no_directory:
mov byte [.DirectoryFlag], 0x00
.directory_check_done:


mov ax, word [.EntryNumber]
cmp word [.EntryCounter], ax
je .success

inc word [.EntryCounter]

.skip_entry:

add si, 21		; Get to the next entry
jmp .next_entry


.failure:

mov bp, sp
add sp, 22		; Get to the flags
pop dx			; Pop and set carry flag
or dx, 0000000000000001b
push dx			; Put flags back in stack
mov sp, bp		; Restore stack
jmp .done

.success:

mov bp, sp
add sp, 22		; Get to the flags
pop dx			; Pop and clear carry flag
and dx, 1111111111111110b
push dx			; Put flags back in stack
mov sp, bp		; Restore stack

mov si, .FatNameBuffer				; Convert name
mov di, word [.TargetBuffer]
mov ax, word [.TargetSegment]
mov es, ax

push 0x2A
int 0x80

.done:

pop dx

mov dl, byte [.DirectoryFlag]

pop es
pop ds
pop bp
pop di
pop si
pop cx
pop bx
pop ax
iret



.DirectoryFlag		db	0x00
.EntryNumber		dw	0x0000
.EntryCounter		dw	0x0000
.TargetBuffer		dw	0x0000
.TargetSegment		dw	0x0000
.FatNameBuffer		times 12 db 0x00



