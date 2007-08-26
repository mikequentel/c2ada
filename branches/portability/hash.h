/* $Source: /home/CVSROOT/c2ada/hash.h,v $ */
/* $Revision: 1.1.1.1 $ $Date: 1999/02/02 12:01:51 $ $Author: nabbasi $ */
#ifndef _H_HASH_
#define _H_HASH_

#ifndef HASH_PRIME
#define HASH_PRIME		31741
#endif

typedef unsigned long hash_t;

extern hash_t common_hash ANSI_PROTO((char*));
extern hash_t lcase_hash ANSI_PROTO((char*));
extern int lcase ANSI_PROTO((int));
extern int lcasecmp ANSI_PROTO((char*,char*));

#endif /* _H_HASH_ */
