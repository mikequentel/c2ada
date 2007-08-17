/* $Source: /home/CVSROOT/c2ada/errors.h,v $ */
/* $Revision: 1.1.1.1 $ $Date: 1999/02/02 12:01:51 $ $Author: nabbasi $ */

#ifndef _H_ERRORS_
#define _H_ERRORS_

#include <stdarg.h>
#include "lowlevel.h"

typedef enum {
    Report_fatal,
    Report_error,
    Report_warning,
    Report_inform
} report_t;

extern void vreport(report_t severity,
		    char* filename, 
		    int   linenum,
		    char *format,
		    va_list ap);

extern void fatal ANSI_PROTO((char*,int,char*,...));
extern void error ANSI_PROTO((char*,int,char*,...));
extern void warning ANSI_PROTO((char*,int,char*,...));
extern void inform ANSI_PROTO((char*,int,char*,...));

extern void assert_failed ANSI_PROTO((char*,int,char*));
extern void syserr ANSI_PROTO((char*,int));

#endif /* _H_ERRORS_ */

