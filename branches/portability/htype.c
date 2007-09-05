/* $Source: /home/CVSROOT/c2ada/htype.c,v $ */
/* $Revision: 1.3 $ $Date: 1999/02/09 18:16:51 $ $Author: nabbasi $ */

#include <stdio.h>
#include <sys/types.h>

#include <sys/param.h>  /* for NBBY */

#define CHAR_SIZE				sizeof(char)
#define SHORT_SIZE				sizeof(short int)
#define INT_SIZE				sizeof(int)
#define LONG_SIZE				sizeof(long int)
#define ADDRESS_SIZE		   	        sizeof(char*)
#define FLOAT_SIZE				sizeof(float)
#define DOUBLE_SIZE				sizeof(double)
#define LONG_DOUBLE_SIZE		        sizeof(long double)

/*
 * Do not make static
 */
short host_byte_order = 0x0102;

static int
alignof_address()
{
	struct s {
		char x;
		char *y;
	};

	return CHAR_SIZE + (sizeof(struct s) - (CHAR_SIZE + ADDRESS_SIZE));
}

static int
alignof_short()
{
	struct s {
		char x;
		short int y;
	};

	return CHAR_SIZE + (sizeof(struct s) - (CHAR_SIZE + SHORT_SIZE));
}

static int
alignof_int()
{
	struct s {
		char x;
		int y;
	};

	return CHAR_SIZE + (sizeof(struct s) - (CHAR_SIZE + INT_SIZE));
}

static int
alignof_long()
{
	struct s {
		char x;
		long int y;
	};

	return CHAR_SIZE + (sizeof(struct s) - (CHAR_SIZE + LONG_SIZE));
}

static int
alignof_float()
{
	struct s {
		char x;
		float y;
	};

	return CHAR_SIZE + (sizeof(struct s) - (CHAR_SIZE + FLOAT_SIZE));
}

static int
alignof_double()
{
	struct s {
		char x;
		double y;
	};

	return CHAR_SIZE + (sizeof(struct s) - (CHAR_SIZE + DOUBLE_SIZE));
}

#ifndef sun
static int
alignof_long_double()
{
	struct s {
		char x;
		long double y;
	};

	return CHAR_SIZE + (sizeof(struct s) - (CHAR_SIZE + LONG_DOUBLE_SIZE));
}
#endif


int
main()
{

  /* On Linux, the BIG_ENDIAN, LITTLE_ENDIAN is allready defined
     in a system header file, no need to try to find what it is ourself
  */
#if !defined(LINUX)
	char *p = (char*) &host_byte_order;
#endif

	printf("#define BITS_PER_BYTE\t\t\t%d\n\n", NBBY);
	printf("#define SIZEOF_CHAR\t\t\t\t%lu\n", CHAR_SIZE);
	printf("#define SIZEOF_SHORT\t\t\t%lu\n", SHORT_SIZE);
	printf("#define SIZEOF_INT\t\t\t\t%lu\n", INT_SIZE);
	printf("#define SIZEOF_LONG\t\t\t\t%lu\n", LONG_SIZE);
	printf("#define SIZEOF_FLOAT\t\t\t%lu\n", FLOAT_SIZE);
	printf("#define SIZEOF_DOUBLE\t\t\t%lu\n", DOUBLE_SIZE);
#ifndef sun
	printf("#define SIZEOF_LONG_DOUBLE\t\t%lu\n", LONG_DOUBLE_SIZE);
#endif
	printf("#define SIZEOF_ADDRESS\t\t%lu\n", ADDRESS_SIZE);

	printf("\n#define ALIGNOF_CHAR\t\t\t%lu\n", CHAR_SIZE);
	printf("#define ALIGNOF_SHORT\t\t\t%d\n", alignof_short());
	printf("#define ALIGNOF_INT\t\t\t\t%d\n", alignof_int());
	printf("#define ALIGNOF_LONG\t\t\t%d\n", alignof_long());
	printf("#define ALIGNOF_FLOAT\t\t\t%d\n", alignof_float());
	printf("#define ALIGNOF_DOUBLE\t\t\t%d\n", alignof_double());
#ifndef sun
	printf("#define ALIGNOF_LONG_DOUBLE\t\t%d\n", alignof_long_double());
#endif
	printf("#define ALIGNOF_ADDRESS\t\t\t%d\n", alignof_address());

	printf("\n#define CHARS_ARE_%sSIGNED\n", (((char)-1) < 0) ? "" : "UN");


	/* This below is commented out since BIG_ENDIAN or LITTLE_ENDIAN
           is allready defined in Linux system here file 
	*/
#if !defined(LINUX)
	if (*p == 1) {
                puts("#if !defined(BIG_ENDIAN)");
		puts("#define BIG_ENDIAN");
                puts("#endif");
	}
	else {
                puts("#if !defined(LITTLE_ENDIAN)");
		puts("#define LITTLE_ENDIAN");
                puts("#endif");
	}
#endif

	return 0;
}


