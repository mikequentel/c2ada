/* $Source: /home/CVSROOT/c2ada/nodeop.h,v $ */
/* $Revision: 1.1.1.1 $ $Date: 1999/02/02 12:01:51 $ $Author: nabbasi $ */
#ifndef _H_NODEOP_
#define _H_NODEOP_

extern node_t *access_to ANSI_PROTO((node_t*,node_t*));

extern node_pt new_node(node_kind_t, ...);
extern node_pt new_pos_node(file_pos_t pos, node_kind_t kind, ...);

extern node_t *id_from_typedef ANSI_PROTO((typeinfo_t*));
extern void reduce_node ANSI_PROTO((node_t*));
extern void free_node ANSI_PROTO((node_t*));

/* returns the op corresponding to an assign-op; eg {*=} => {*} */
extern node_kind_t non_assign_op( node_kind_t );

extern node_pt reshape_list( node_pt e );


/* for iterating over a list */

typedef struct {
    node_pt * head;
    node_pt * rest;
    node_pt * tail;  /* head + rest node */
} node_iter_t;

extern node_iter_t init_node_iter(node_pt * n);
extern node_pt *   next_list_ref(node_iter_t *iter);
extern node_pt *   node_iter_tail(node_iter_t *iter);


/* null pointer */
extern boolean is_null_ptr_value( node_pt node );



#endif /* _H_NODEOP_ */
