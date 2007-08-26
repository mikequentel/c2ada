/* $Source: /home/CVSROOT/c2ada/allocate.h,v $ */
/* $Revision: 1.1.1.1 $ $Date: 1999/02/02 12:01:51 $ $Author: nabbasi $ */
#ifndef _H_ALLOCATE_
#define _H_ALLOCATE_

#ifdef NO_DEALLOC
#	undef free
#	define free(x)
#endif

extern char *new_string ANSI_PROTO((char*));
extern char *new_strf( char *, ... ); /* uses printf style formatting */
extern void *allocate ANSI_PROTO((size_t size));
extern void deallocate ANSI_PROTO((void *ptr));

#define NEW(type) ((type*)allocate(sizeof(type)))

#endif /* _H_ALLOCATE_ */
