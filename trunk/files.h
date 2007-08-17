/* $Source: /home/CVSROOT/c2ada/files.h,v $ */
/* $Revision: 1.2 $ $Date: 1999/02/03 19:45:04 $ $Author: nabbasi $ */
/*
 * Routines for dealing with files and file names.
 *
 * The current file and line number during scanning is
 * maintained int packed long int.  This will reduce the size
 * of a lot of our IL types.
 */
#ifndef _H_FILES_
#define _H_FILES_

/* include definition of size_t */
#include <stddef.h>

#ifndef _H_HOSTINFO_
#include "hostinfo.h"
#endif

#ifndef FILE_ORD_BITS
#define FILE_ORD_BITS		10
#endif

#if !defined(BITS_PER_BYTE)
#define BITS_PER_BYTE 8
#endif

#if !defined(SIZEOF_LONG)
#define SIZEOF_LONG 4
#endif


#define LINE_NUMBER_BITS	((SIZEOF_LONG * BITS_PER_BYTE) - FILE_ORD_BITS)
#define MAX_UNIQ_FNAMES		(1 << FILE_ORD_BITS)

/*
 * Upper FILE_ORD_BITS specify file ordinal.
 * Rest of integer specifies line number.
 */

typedef unsigned long file_pos_t;
typedef int      file_id_t;
typedef unsigned long line_nt;

extern file_id_t pos_file(file_pos_t);
extern line_nt   pos_line(file_pos_t);

#define line_number(x)		((x) & ((1 << LINE_NUMBER_BITS) - 1))

extern int num_files ANSI_PROTO((void));

extern char *file_name ANSI_PROTO((file_pos_t pos));
extern char *file_name_from_ord ANSI_PROTO((int ord));
extern file_pos_t add_file ANSI_PROTO((char *path));
extern file_pos_t set_file_pos ANSI_PROTO((char *path, int line));

/* returns -1 if file not found */
extern file_pos_t find_file ANSI_PROTO((char *path));

extern size_t sizeof_file ANSI_PROTO((int fd));
extern void *map_file ANSI_PROTO((int fd, size_t fsize));
extern int unmap_file ANSI_PROTO((void *addr, size_t len));
extern int compare_path ANSI_PROTO((char *s1, char *s2));

/* convenience functions to use file_pos_t for warnings */
extern void error_at  ( file_pos_t pos, char * fmt, ...);
extern void warning_at( file_pos_t pos, char * fmt, ...);
extern void inform_at ( file_pos_t pos, char * fmt, ...);


#endif /* _H_FILES_ */
