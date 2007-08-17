/* $Source: /home/CVSROOT/c2ada/units.h,v $ */
/* $Revision: 1.1.1.1 $ $Date: 1999/02/02 12:01:51 $ $Author: nabbasi $ */
#ifndef _H_UNITS_
#define _H_UNITS_

#ifndef _H_COMMENT
#include "comment.h"
#endif

#ifndef _H_FILES
#include "files.h"
#endif

/* Important note: The word "unit" should really be "package" in 
 * these names, including "unit_n", due to a really embarassing
 * terminological lapse. There's a unique unit_n for each Ada package
 * in the output.  This terminology dates back to the "cbind" version
 * of this source, which only emitted package specs, so packages and
 * units could be conflated.  Not any more.
 */
typedef int unit_n;  /* (type of) unique output Ada PACKAGE number */

extern void     unit_start_gen ANSI_PROTO((void));
extern boolean  set_unit ANSI_PROTO((unit_n));
extern unit_n   current_unit(void);
extern boolean  current_unit_is_header;
extern boolean  is_current_unit ANSI_PROTO((unit_n));
extern void unit_completed ANSI_PROTO((void));
extern void unit_included ANSI_PROTO((file_pos_t, int));
extern void init_unit ANSI_PROTO((file_pos_t));

extern int num_units(void);

boolean pos_in_current_unit(file_pos_t pos);
unit_n pos_unit(file_pos_t pos);

/* unit <ord> needs a "with" for <dep>;
 * <from_body> => from <ord>'s body, else <ord>'s spec */
extern void unit_dependency( unit_n ord, unit_n dep, boolean from_body );

extern char *cur_unit_source ANSI_PROTO((void));
extern char *cur_unit_name ANSI_PROTO((void));
extern char *cur_unit_path ANSI_PROTO((void));

extern int  cur_unit_has_const_string ANSI_PROTO((void));
extern void set_cur_unit_has_const_string ANSI_PROTO((void));

extern int  cur_unit_is_child_of_predef ANSI_PROTO((void));
extern void set_cur_unit_is_child_of_predef ANSI_PROTO((void));

extern boolean unit_has_private_part(unit_n unit);
extern void    set_unit_has_private_part(unit_n unit);

extern boolean cur_unit_header_comment_set(void);
extern comment_block_pt cur_unit_header_comment(void);
extern void set_cur_unit_header_comment( comment_block_pt );
extern comment_block_pt cur_unit_trailer_comment(void);
extern void set_cur_unit_trailer_comment( comment_block_pt );

extern char *predef_pkg;
extern char *unit_name(unit_n unit);

extern unit_n  nth_ref_unit_ord(int);
extern unit_n  nth_direct_ref_unit_ord(int);
extern unit_n  nth_body_ref_unit_ord(int);

extern void set_ellipsis(unit_n unit);
extern boolean has_ellipsis(unit_n unit);

extern void set_unchecked_conversion(unit_n unit, boolean in_spec);
extern boolean has_unchecked_conversion(unit_n unit);
extern boolean unchecked_conversions_to_spec(unit_n unit);

extern void with_c_pointers(unit_n unit);
extern boolean has_c_pointers(unit_n unit);

extern void with_c_const_pointers(unit_n unit);
extern boolean has_c_const_pointers(unit_n unit);

extern void output_to_spec ANSI_PROTO((void));
extern void output_to_body ANSI_PROTO((void));
extern void output_to ANSI_PROTO((int to_spec));
extern int  output_is_spec ANSI_PROTO((void));

#endif /* _H_UNITS_ */
