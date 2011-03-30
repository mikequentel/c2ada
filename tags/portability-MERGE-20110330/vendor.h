/* $Source: /home/CVSROOT/c2ada/vendor.h,v $ */
/* $Revision: 1.1.1.1 $ $Date: 1999/02/02 12:01:51 $ $Author: nabbasi $ */
#ifndef _H_VENDOR_
#define _H_VENDOR_

typedef enum {
	unspecified_vendor,
	Rational,
	VADS,
	ICC,					/* Irvine Compiler */
	GNAT
} vendor_t;

extern vendor_t ada_compiler;

#endif /* _H_VENDOR_ */
