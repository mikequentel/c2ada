/* $Source: /home/CVSROOT/c2ada/stab.h,v $ */
/* $Revision: 1.1.1.1 $ $Date: 1999/02/02 12:01:51 $ $Author: nabbasi $ */
#ifndef _H_STAB_
#define _H_STAB_

extern symbol_t *new_sym ANSI_PROTO((void));
extern symbol_t *find_sym ANSI_PROTO((char*));
extern void store_sym ANSI_PROTO((symbol_t*));

/* Scopes */

typedef enum {
    Unspecified_scope,
    Func_scope,
    File_scope,
    Block_scope,
    Proto_scope
} scope_kind_t;

extern scope_kind_t scope_kind(scope_id_t);
extern scope_id_t   scope_parent(scope_id_t);
extern symbol_pt    scope_symbol(scope_id_t);
extern symbol_pt    scope_parent_func( scope_id_t );
extern int          scope_level(scope_id_t);

extern void set_scope_kind( scope_id_t scope, scope_kind_t kind);
extern void set_scope_parent( scope_id_t scope, scope_id_t parent);
extern void set_scope_symbol( scope_id_t scope, symbol_pt sym);

extern void scope_push( scope_kind_t kind );
extern void scope_pop( void );

extern int next_param ANSI_PROTO((void));

extern scope_id_t new_scope_id(scope_kind_t kind);
extern scope_id_t new_block_scope(scope_id_t parent);

extern scope_id_t current_scope(void);
extern void   set_current_scope(scope_id_t);

#endif /* _H_STAB_ */








