#ifndef __STDIO_H__
#define __STDIO_H__

#include "unistd.h"

#define EOF ((int)-1)


int putchar(int ch)
{
  if ( syscall(SC_PUT_CHAR, (unsigned char)ch) == 0 )
    return ch;
  else
    return EOF;
}


int puts(const char *str)
{
  if ( syscall(SC_PRINT_STRING, str) != -1 )
  {
    if ( putchar('\n') != EOF )
      return 1;
    else
      return EOF;
  }
  else
    return EOF;
}


#endif
