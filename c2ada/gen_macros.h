/* $Source: /home/CVSROOT/c2ada/gen_macros.h,v $ */
/* $Revision: 1.1.1.1 $ $Date: 1999/02/02 12:01:51 $ $Author: nabbasi $ */

#ifndef _GEN_MACROS_H

extern void gen_macro_names ANSI_PROTO((void));
extern void import_macro_constants ANSI_PROTO((void));
extern void gen_macro_constants ANSI_PROTO((macro_t *m, int import)); 
extern void gen_macro_types ANSI_PROTO((macro_t *m, int import));
extern void gen_macro_funcs ANSI_PROTO((macro_t *m, int import));
extern void gen_macro_vars ANSI_PROTO((macro_t *m, int import, int colonpos));
extern void finish_macros ANSI_PROTO((macro_t *m));
extern void rethread_macros ANSI_PROTO((void));
extern void gen_macro_warnings ANSI_PROTO((void));

#endif
