#ifndef __SYSCALL_H__
#define __SYSCALL_H__


#define SC_TERMINATE_PROCESS 0x00
#define SC_PUT_CHAR 0x01
#define SC_PRINT_STRING 0x02
#define SC_NEW_LINE 0x03
#define SC_STRING_TO_INTEGER 0x04
#define SC_PRINT_INTEGER_HEX 0x05
#define SC_PRINT_INTEGER 0x06
#define SC_INPUT_INTEGER 0x07
#define SC_COMPARE_STRINGS 0x08
#define SC_STRING_LENGTH 0x09
#define SC_INITIALIZE_SCREEN 0x0A
#define SC_DISABLE_CURSOR 0x0B
#define SC_ENABLE_CURSOR 0x0C
#define SC_GET_CURSOR_POSITION 0x0D
#define SC_SET_CURSOR_POSITION 0x0E
#define SC_CENTER_PRINT_STRING 0x0F
#define SC_INPUT_STRING 0x10
#define SC_SET_PALETTE 0x11
#define SC_LOAD_FILE 0x12
#define SC_GET_CURRENT_DRIVE 0x13
#define SC_START_NEW_PROGRAM 0x14
#define SC_LOWER_TO_UPPERCASE 0x15
#define SC_UPPER_TO_LOWERCASE 0x16
#define SC_GET_CURRENT_PALETTE 0x17
#define SC_PAUSE 0x18
#define SC_ALLOCATE_MEMORY 0x19
#define SC_CUT_STRING 0x1A
#define SC_TIMER_READ 0x20
#define SC_LOAD_DIR 0x21
#define SC_SPEAKER_BEEP_FREQUENCY 0x22
#define SC_FLOPPY_READ_SECTORS 0x23
#define SC_FLOPPY_READ_BYTE 0x24
#define SC_FLOPPY_READ_WORD 0x25
#define SC_FLOPPY_READ_DWORD 0x26
#define SC_STRING_COPY 0x27
#define SC_DIRECTORY_SCANNER 0x28
#define SC_SET_CURRENT_DRIVE 0x29
#define SC_PING_FILE 0x2B
#define SC_FAT_TIME_TO_INTEGER 0x2C
#define SC_STRING_END 0x2D
#define SC_GET_CURRENT_DIR 0x2E
#define SC_FLOPPY_WRITE_SECTORS 0x31
#define SC_FLOPPY_WRITE_BYTE 0x32
#define SC_FLOPPY_WRITE_WORD 0x33
#define SC_FLOPPY_WRITE_DWORD 0x34
#define SC_INVALID_CACHE 0x35
#define SC_ENTER_GRAPHICS_MODE 0x80
#define SC_DRAW_PIXEL 0x81
#define SC_EXIT_GRAPHICS_MODE 0x82
#define SC_DRAW_LINE 0x83
#define SC_DRAW_SPRITE 0x84
#define SC_CLEAR_SCREEN 0x85
#define SC_PUSH_FRAME 0x86
#define SC_GET_VERSION_NUMBER 0x87


#endif