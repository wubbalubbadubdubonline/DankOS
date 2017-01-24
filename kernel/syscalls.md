# DankOS Syscall Table (WIP)

To make a system call, push the opcode onto the stack and move the arguments
into si, di, (more to come) respectively, then call `int 0x80`


| opcode | name | arguments| short description |
| :---: | --- | --- | --- |
| 0x0 | terminate_process | none | terminates the current process |
| 0x1 | put_char | char | prints a single character |
| 0x2 | print_string | str | prints a null terminated string |
| 0x3 | new_line |  |  |
| 0x4 | string_to_integer |  |  |
| 0x5 | print_integer_hex |  |  |
| 0x6 | print_integer |  |  |
| 0x7 | input_integer |  |  |
| 0x8 | compare_strings |  |  |
| 0x9 | string_length |  |  |
| 0xA | initialize_screen |  |  |
| 0xB | disable_cursor |  |  |
| 0xC | enable_cursor |  |  |
| 0xD | get_cursor_position |  |  |
| 0xE | set_cursor_position |  |  |
| 0xF | center_print_string |  |  |
| 0x10 | input_string |  |  |
| 0x11 | set_palette |  |  |
| 0x12 | load_file |  |  |
| 0x13 | get_current_drive |  |  |
| 0x14 | start_new_program |  |  |
| 0x15 | lower_to_uppercase |  |  |
| 0x16 | upper_to_lowercase |  |  |
| 0x17 | get_current_palette |  |  |
| 0x18 | pause |  |  |
| 0x19 | allocate_memory |  |  |
| 0x1A | cut_string |  |  |
| 0x1B | (unused) | N/A | N/A |
| 0x1C | (unused) | N/A | N/A |
| 0x1D | (unused) | N/A | N/A |
| 0x1E | (unused) | N/A | N/A |
| 0x1F | (unused) | N/A | N/A |
| 0x20 | timer_read |  |  |
| 0x21 | load_dir |  |  |
| 0x22 | speaker_beep_frequency |  |  |
| 0x23 | floppy_read_sectors |  |  |
| 0x24 | floppy_read_byte |  |  |
| 0x25 | floppy_read_word |  |  |
| 0x26 | floppy_read_dword |  |  |
| 0x27 | string_copy |  |  |
| 0x28 | directory_scanner |  |  |
| 0x29 | set_current_drive |  |  |
| 0x2A | (unused) |  |  |
| 0x2B | ping_file |  |  |
| 0x2C | fat_time_to_integer |  |  |
| 0x2D | string_end |  |  |
| 0x2E | get_current_dir |  |  |
| 0x2F | (unused) |  |  |
| 0x30 | (unused) |  |  |
| 0x31 | floppy_write_sectors |  |  |
| 0x32 | floppy_write_byte |  |  |
| 0x33 | floppy_write_word |  |  |
| 0x34 | floppy_write_dword |  |  |
| 0x35 | invalid_cache |  |  |
| 0x36 | (unused) |  |  |
| 0x37 | (unused) |  |  |
| 0x38 | (unused) |  |  |
| 0x39 | (unused) |  |  |
| 0x3A | (unused) |  |  |
| 0x3B | (unused) |  |  |
| 0x3C | (unused) |  |  |
| 0x3D | (unused) |  |  |
| 0x3E | (unused) |  |  |
| 0x3F | (unused) |  |  |
| 0x40 | (unused) |  |  |
| 0x41 | (unused) |  |  |
| 0x42 | (unused) |  |  |
| 0x43 | (unused) |  |  |
| 0x44 | (unused) |  |  |
| 0x45 | (unused) |  |  |
| 0x46 | (unused) |  |  |
| 0x47 | (unused) |  |  |
| 0x48 | (unused) |  |  |
| 0x49 | (unused) |  |  |
| 0x4A | (unused) |  |  |
| 0x4B | (unused) |  |  |
| 0x4C | (unused) |  |  |
| 0x4D | (unused) |  |  |
| 0x4E | (unused) |  |  |
| 0x4F | (unused) |  |  |
| 0x50 | (unused) |  |  |
| 0x51 | (unused) |  |  |
| 0x52 | (unused) |  |  |
| 0x53 | (unused) |  |  |
| 0x54 | (unused) |  |  |
| 0x55 | (unused) |  |  |
| 0x56 | (unused) |  |  |
| 0x57 | (unused) |  |  |
| 0x58 | (unused) |  |  |
| 0x59 | (unused) |  |  |
| 0x5A | (unused) |  |  |
| 0x5B | (unused) |  |  |
| 0x5C | (unused) |  |  |
| 0x5D | (unused) |  |  |
| 0x5E | (unused) |  |  |
| 0x5F | (unused) |  |  |
| 0x60 | (unused) |  |  |
| 0x61 | (unused) |  |  |
| 0x62 | (unused) |  |  |
| 0x63 | (unused) |  |  |
| 0x64 | (unused) |  |  |
| 0x65 | (unused) |  |  |
| 0x66 | (unused) |  |  |
| 0x67 | (unused) |  |  |
| 0x68 | (unused) |  |  |
| 0x69 | (unused) |  |  |
| 0x6A | (unused) |  |  |
| 0x6B | (unused) |  |  |
| 0x6C | (unused) |  |  |
| 0x6D | (unused) |  |  |
| 0x6E | (unused) |  |  |
| 0x6F | (unused) |  |  |
| 0x70 | (unused) |  |  |
| 0x71 | (unused) |  |  |
| 0x72 | (unused) |  |  |
| 0x73 | (unused) |  |  |
| 0x74 | (unused) |  |  |
| 0x75 | (unused) |  |  |
| 0x76 | (unused) |  |  |
| 0x77 | (unused) |  |  |
| 0x78 | (unused) |  |  |
| 0x79 | (unused) |  |  |
| 0x7A | (unused) |  |  |
| 0x7B | (unused) |  |  |
| 0x7C | (unused) |  |  |
| 0x7D | (unused) |  |  |
| 0x7E | (unused) |  |  |
| 0x7F | (unused) |  |  |
| 0x80 | enter_graphics_mode |  |  |
| 0x81 | draw_pixel |  |  |
| 0x82 | exit_graphics_mode |  |  |
| 0x83 | draw_line |  |  |
| 0x84 | draw_sprite |  |  |
| 0x85 | clear_screen |  |  |
| 0x86 | push_frame |  |  |
| 0x87 | get_version_number |  |  |
