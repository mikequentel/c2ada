/* $Source: /home/CVSROOT/c2ada/hash.c,v $ */
/* $Revision: 1.1.1.1 $ $Date: 1999/02/02 12:01:51 $ $Author: nabbasi $ */
#include "lowlevel.h"
#include "hash.h"

hash_t
common_hash(str)
	char *str;
{
	hash_t val;

	for (val = HASH_PRIME; *str; str++) {
		val -= (hash_t) *str;
	}

	return val;
}

int
lcase(c)
	int c;
{
	if (c >= 'A' && c <= 'Z') {
		return c - 'A' + 'a';
	}
	return c;
}

hash_t
lcase_hash(str)
	char *str;
{
	hash_t val;
	char c;

	for (val = HASH_PRIME; *str; str++) {
		c = lcase(*str);
		val -= (hash_t) c;
	}

	return val;
}

int
lcasecmp(s1, s2)
	char *s1, *s2;
{
	char c1, c2;

	for (;;) {
		c1 = lcase(*s1++);
		c2 = lcase(*s2++);
		if (c1 != c2 || c1 == 0) break;
	}

	/*
	 * return  0 if s1 == s2
	 * return <0 if s1 < s2
	 * return >0 if s1 > s2
	 */
	return ((int)c1) - ((int)c2);
}
