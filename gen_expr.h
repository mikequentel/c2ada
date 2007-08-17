/* $Source: /home/CVSROOT/c2ada/gen_expr.h,v $ */
/* $Revision: 1.1.1.1 $  $Date: 1999/02/02 12:01:51 $ */

#ifndef _H_GEN_EXPR_
#define _H_GEN_EXPR_

#include "lowlevel.h"

#ifndef _H_IL_
#include "il.h"
#endif

extern void gen_expr( node_pt e, boolean in_parens );

extern char* null_pointer_value_name( typeinfo_pt type );

#endif
