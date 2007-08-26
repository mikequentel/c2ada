/* $Source: /home/CVSROOT/c2ada/print.h,v $ */
/* $Revision: 1.1.1.1 $ $Date: 1999/02/02 12:01:51 $ $Author: nabbasi $ */

#include "macro.h"

extern char * nameof_stmt_kind( stmt_kind_t );
extern char * nameof_node_kind( node_kind_t );
extern char * nameof_typekind ( typekind_t  );
extern char * nameof_sym_kind ( sym_kind_t  );

extern void print_stmt_kind ANSI_PROTO((stmt_kind_t s));
extern void print_stmt ANSI_PROTO((stmt_pt s, int indent));
extern void print_node ANSI_PROTO((node_pt n, int indent));
extern void print_symbol ANSI_PROTO((symbol_pt s, int indent));
extern void print_typekind ANSI_PROTO((typekind_t t));
extern void print_node_kind ANSI_PROTO((node_kind_t n));
extern void print_typeinfo ANSI_PROTO((typeinfo_t *t, int indent));
extern void print_sym_kind ANSI_PROTO((sym_kind_t s));
extern void print_case_alist ANSI_PROTO((case_alist_pt ap, int indent));
extern void print_case_slist ANSI_PROTO((case_slist_pt sp, int indent));
extern void print_case_blist ANSI_PROTO((case_blist_pt bp, int indent));
extern void print_case_stmt ANSI_PROTO((case_stmt_pt cp, int indent));
extern void print_macro ANSI_PROTO((macro_t *m, int indent));
extern void print_macro_function ANSI_PROTO((macro_function_t *f, int indent));
extern void print_file_pos ANSI_PROTO((file_pos_t pos));
extern void print_comment_block 
    ANSI_PROTO((struct comment_block *bl, int indent));
extern void print_cpp_eval_result_t 
    ANSI_PROTO((cpp_eval_result_t *res, int indent));
