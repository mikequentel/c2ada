/* $Source: /home/CVSROOT/c2ada/buffer.h,v $ */
/* $Revision: 1.1.1.1 $ $Date: 1999/02/02 12:01:51 $ $Author: nabbasi $ */
#ifndef _H_BUFFER_
#define _H_BUFFER_

/*
 * MAX_OUTBUF_LEN must be a power of 2 and it should
 * be large enough that overflows are uncommon, but
 * we use many automatic instances of the queues so
 * it shouldn't be so large that our stack grows
 * like Jack's beanstock.
 */
#ifndef MAX_OUTBUF_LEN
#define MAX_OUTBUF_LEN			1024
#endif

typedef struct buffer_t {
	char buf[MAX_OUTBUF_LEN];
	unsigned short head, tail;
	struct buffer_t *next, *last;
} buffer_t;

extern int buf_empty ANSI_PROTO((buffer_t*));
extern int buf_count ANSI_PROTO((buffer_t*));
extern void buf_add ANSI_PROTO((buffer_t*, int));
extern void buf_add_str ANSI_PROTO((buffer_t*, char*));
extern char buf_get ANSI_PROTO((buffer_t*));
extern void buf_init ANSI_PROTO((buffer_t*));
extern void buf_destroy ANSI_PROTO((buffer_t*));
extern void buf_concat ANSI_PROTO((buffer_t*,buffer_t*));
extern void buf_move_to ANSI_PROTO((buffer_t*,char*));
extern char *buf_get_str ANSI_PROTO((buffer_t*));

#endif /* _H_BUFFER_ */
