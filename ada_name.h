/* $Source: /home/CVSROOT/c2ada/ada_name.h,v $ */
/* $Revision: 1.1.1.1 $ $Date: 1999/02/02 12:01:51 $ $Author: nabbasi $ */
#ifndef _H_ADA_NAME_
#define _H_ADA_NAME_

typedef enum {
	Upper,
	Lower,
	Cap
} ident_case_t;

extern int is_ada_keyword ANSI_PROTO((char*));
extern void make_ada_identifier ANSI_PROTO((char*, char*));
extern char *uniq_name ANSI_PROTO((char*, int));
extern char *ada_name ANSI_PROTO((char*, int));
extern ident_case_t id_case ANSI_PROTO((char*));
extern void id_format ANSI_PROTO((char*,ident_case_t));

/* return a pointer to the final component name in an Ada name */
extern char* tail(char * component);

#endif /* _H_ADA_NAME_ */