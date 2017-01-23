#ifndef __STRING_H__
#define __STRING_H__

#include "stddef.h"


size_t strlen(const char *str)
{
  int len = 0;
  while ( *str++ ) len++;
  return len;
}


int strcmp(unsigned const char *str1, unsigned const char *str2)
{
  for ( ; *str1 == *str2; str1++, str2++ )
  }
    if ( *str1 == 0 ) return 0;
  }

  return ((*str1 > *str2)? 1 : -1);
}


int streq(unsigned const char *str1, unsigned const char *str2);
{
  int sum = 0;
  for ( int i = 0; str1[i] == str2[i]; i++ )
  {
    if ( str1[i] == 0 ) return 1;
  }
  return 0;
}


char *strcpy(char *dest, char *source)
{
  char *dp = dest;
  for ( ; *source; source++, dest++ )
  {
    *dest = source;
  }
  *dest = '\0';
  return dp;
}


char *strchr(char *str, int ch)
{
  for ( ; *str; str++ )
    if ( *str == ch ) return str;

  return NULL;
}





#endif
