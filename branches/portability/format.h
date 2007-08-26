/* $Source: /home/CVSROOT/c2ada/format.h,v $ */
/* $Revision: 1.1.1.1 $ $Date: 1999/02/02 12:01:51 $ $Author: nabbasi $ */
#ifndef _H_FORMAT_
#define _H_FORMAT_

#undef START_INDENT
#define START_INDENT	0

#ifndef COMMENT_POS
#define COMMENT_POS		64
#endif

extern int output_line ANSI_PROTO((void));
extern void reset_output_line ANSI_PROTO((void));

extern void reset_indent ANSI_PROTO((void));
extern void new_line ANSI_PROTO((void));
extern void indent_to ANSI_PROTO((int));
extern void put_string ANSI_PROTO((char*));
extern void put_char ANSI_PROTO((int));
extern int cur_indent ANSI_PROTO((void));

extern void putf(char*,...);

#endif /* _H_FORMAT_ */
