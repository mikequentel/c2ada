/* $Source: /home/CVSROOT/c2ada/lowlevel.h,v $ */
/* $Revision: 1.1.1.1 $ $Date: 1999/02/02 12:01:51 $ $Author: nabbasi $ */

#ifndef _H_LOWLEVEL_
#define _H_LOWLEVEL_

#if defined(_NO_PROTO_) || !(defined(__STDC__) || defined(__cplusplus))
#define ANSI_PROTO(x)	()
#else
#define ANSI_PROTO(x)	x
#endif

#undef assert

#ifdef NDEBUG
#define assert(EX) ((void)0)
#else
#if defined(__STDC__) || defined(__ANSI_CPP__)
#define assert(EX)  ((EX)?((void)0):assert_failed(__FILE__, __LINE__,  # EX ))
#else
#define assert(EX)  ((EX)?((void)0):assert_failed(__FILE__, __LINE__, "EX"))
#endif
#endif

typedef int boolean;
#define FALSE 0
#define TRUE  1

#endif /* _H_LOWLEVEL_ */

