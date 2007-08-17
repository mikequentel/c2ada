/* $Source: /home/CVSROOT/c2ada/printf.h,v $ */
/* $Revision: 1.2 $ $Date: 1999/02/03 19:45:04 $ $Author: nabbasi $ */

/* why don't these functions have prototypes in <stdio.h> ? */

#include <stdio.h>
#include <stdarg.h>

#if !defined(LINUX)
#include <sys/stdtypes.h>
#endif

#include "lowlevel.h"

#if !defined(LINUX)
extern void fclose ANSI_PROTO((FILE *));
extern void fflush ANSI_PROTO((FILE *));
extern void fprintf ANSI_PROTO((FILE *, char *, ...));
extern void fputc ANSI_PROTO((char, FILE *));
extern void fputs ANSI_PROTO((char *, FILE *));
extern int  fwrite ANSI_PROTO((char*, int, int, FILE *));
extern void vfprintf ANSI_PROTO((FILE *, char *, va_list));
extern void fscanf ANSI_PROTO((FILE *, char *, ...));

extern void _flsbuf ANSI_PROTO((char, FILE *));
extern int  mkstemp ANSI_PROTO((char *));
extern int  munmap ANSI_PROTO((void *, size_t));
extern void printf ANSI_PROTO((char *, ...));
extern void puts ANSI_PROTO((char *));
extern int  rename ANSI_PROTO((char *, char *));
extern void unlink ANSI_PROTO((char *));

extern char tolower ANSI_PROTO((char));
#endif


