# $Source: /home/CVSROOT/c2ada/Makefile,v $
# $Revision: 1.3 $  $Date: 1999/02/09 18:16:51 $

# This variable should point to the "gperf" executable on your
# system; cf. ftp://ftp.gnu.ai.mit.edu/pub/gnu/cperf-2.1a.tar.gz .
#
GPERF		  = /usr/bin/gperf

# This variable should point to the top-level Python distribution
# directory on your system; cf. http://www.python.org .
#
PYTHON            = /usr/lib/python2.4

## this is the library name, on my system, I had python 1.5, so the
## library was libpython1.5.so, so I type python1.5 below
PYTHON_LIB        = python2.4

## this is where python .py stuff is
PYTHON_INCLUDE    = /usr/include/python2.4

# HERE should be set to the directory containing the *.py files
# in the C2Ada source distribution. The form here simply sets this
# to the source directory.
#
HERE = $(HOME)/sf/c2ada

### no need to change anything below this. Unless you want
### to change gcc flags to be non-debug.

####################################

# In PYTHONLIBS, the argument in the -L switch is the same as the
# target path for the "make libainstall" step in installing Python.
#
PYTHONLIBS        = -L$(PYTHON)/config \
		    -l$(PYTHON_LIB)

#		    -lm -lnsl -ldl -lm

PYTHON_INCLUDES   = -DHAVE_CONFIG_H -I$(PYTHON_INCLUDE)

# This is the path used to locate Python scripts and modules used by
# c2ada. See symset.c
#
PYTHON_SCRIPTS_PATH = $(HERE):$(PYTHON)/Lib
DEF_PPATH = -DPPATH=\"$(PYTHON_SCRIPTS_PATH)\"

GNU_C_OPTS = -g -Wall -Wimplicit -Wreturn-type
CC = gcc 
CFLAGS= $(GNU_C_OPTS) -DDEBUG $(PYTHON_INCLUDES) $(DEF_PPATH)
LINKER		  = gcc -g

MAKEFILE= Makefile

LOCAL_LIBS	= libcbind.a

SRCS	        = ada_name.c \
		ada_perf.c \
		allocate.c \
		anonymous.c \
		aux_decls.c \
		buffer.c \
		c_perf.c \
		cbfe.c \
		context.c \
		cpp.c \
		cpp_eval.c \
		cpp_perf.c \
		errors.c \
		files.c \
		fix_stmt.c \
		format.c \
		gen.c \
		gen_expr.c \
		gen_macros.c \
		gen_stmt.c \
		hash.c \
		initializer.c \
		htype.c \
		localfunc.c \
		macro.c \
		nodeop.c \
		order.c \
		package.c \
		scan.c \
		stab.c \
		stmt.c \
		symset.c \
		types.c \
		units.c \
		y.tab.c

OBJS		= $(SRCS:.c=.o)

COMMON_SRCS	= allocate.c \
		buffer.c \
		cpp.c \
		errors.c \
		files.c \
		cpp_perf.c \
		cpp_eval.c \
		macro.c \
		hash.c

COMMON_OBJS	= $(COMMON_SRCS:.c=.o)

FESRCS		= \
		ada_types.c \
		aux_decls.c \
	        cbfe.c \
		comment.c \
		configure.c \
		context.c \
		fix_stmt.c \
		gen.c \
		gen_stmt.c \
		gen_expr.c \
		gen_macros.c \
		ada_perf.c \
		ada_name.c \
		format.c \
		initializer.c \
		order.c \
		print.c \
		y.tab.c \
		scan.c \
		nodeop.c \
		package.c \
		c_perf.c \
		types.c \
		stab.c \
		stmt.c \
		symset.c \
		units.c \
		anonymous.c \
		localfunc.c

FEOBJS		= $(FESRCS:.c=.o)

GENED_SRC	= y.tab.c \
		y.tab.h \
		c_perf.c \
		ada_perf.c \
		cpp_perf.c

SCRIPTS		= gen.last \
		gen.makefile \
		gen.diffs \
		hostinfo

# OBSOLETE TARGETS
#		cbind.o
#		cbpp.o
#		cdep.o


all:	make cbfe

%c%y:;
%o%y:;

make::	hostinfo.h
make::	cpp_perf.c
make::	ada_perf.c
make::	c_perf.c
make::	y.tab.h
make::	$(OBJS)
make::	$(COMMON_OBJS)

make::	$(LOCAL_LIBS)

# OBSOLETE
# make::	cdep
# make::	cbpp
# make::	cbind

make::	cbfe


# OBSOLETE RULES
#install: all
#	- strip cbpp cbfe cbind cdep
#	- rm -f $(HOME)/bin/cbpp $(HOME)/bin/cbfe $(HOME)/bin/cbind $(HOME)/bin/cdep
#	- cp cbpp cbfe cbind cdep $(HOME)/bin


# This is the executable for C2Ada.
#
cbfe:	$(FEOBJS) $(LOCAL_LIBS) config.o
	@echo "LOCAL_LIBS = $(LOCAL_LIBS)" 
	@echo "LDFLAGS = $(LDFLAGS)" 
	@echo "LIBS = $(LIBS)" 
	@echo "PYTHONLIBS = $(PYTHONLIBS)"
		$(LINKER) $(LDFLAGS) $(FEOBJS) $(LOCAL_LIBS) \
                $(LIBS) config.o  $(PYTHONLIBS)  -o c2ada

#cbpp:	cbpp.o $(LOCAL_LIBS)
#		$(LINKER) $(LDFLAGS) cbpp.o $(LOCAL_LIBS) $(LIBS) -o $@

#cdep:	cdep.o $(LOCAL_LIBS)
#		$(LINKER) $(LDFLAGS) cdep.o $(LOCAL_LIBS) $(LIBS) -o $@

#cbind:	cbind.o $(LOCAL_LIBS)
#		$(LINKER) $(LDFLAGS) cbind.o $(LOCAL_LIBS) $(LIBS) -o $@

htype:	htype.c htype.o
		$(LINKER) $(LDFLAGS) htype.o $(LIBS) -o $@
		@ strip $@

libcbind.a:	$(COMMON_OBJS)
		@ rm -f $@
		ar rc $@ $(COMMON_OBJS)
		ranlib $@

clean::;	- rm -f cbind cbfe cbpp cdep
clean::;	- rm -f *.o *.d *.pyc
clean::;	- rm -f $(LOCAL_LIBS)
clean::;	- rm -f hostinfo.h htype htype.o

realclean:	clean
		- rm -f $(GENED_SRC)

mf:		hostinfo.h cpp_perf.c y.tab.c y.tab.h
		mkmf -f $(MAKEFILE)

tarfile:
	tar cf - \
	 -C DOC . -C CCOMP . -C COMP . -C MISC . -C YACC . \
	 -C CM catalog.des \
	| gzip > c2ada.tar.gz

# probably obsolete:
backup:
		- rm -f $(HOME)/save/newc2a.tar.Z
		tar -chf $(HOME)/save/newc2a.tar *.1 *.c *.h *.y *.prf $(SCRIPTS) DOCS README makefile
		compress $(HOME)/save/newc2a.tar

touch:;	touch $(GENED_SRC)

hostinfo.h: htype hostinfo
		./hostinfo $@

c_perf.c:	c.prf
		$(GPERF) -t -p c.prf > $@

ada_perf.c:	ada.prf
		$(GPERF) -k1,4,'$$' -N ada_keyword ada.prf > $@

cpp_perf.c:	cpp.prf
		$(GPERF) -N cpp_keyword -t -p cpp.prf > $@

cpp_perf.o: cpp_perf.c files.h hash.h cpp.h buffer.h
ada_perf.o: ada_perf.c

y.tab.h:	grammar.y
		yacc -d grammar.y

y.tab.c:	grammar.y
		echo "one reduce/reduce conflict expected"; yacc grammar.y

# Configuration file for Python module set

#config.o : $(PYTHON)/Modules/config.c
#	$(CC) $(CFLAGS) -DNO_MAIN -c $(PYTHON)/Modules/config.c

config.o : $(PYTHON)/config/config.c
	$(CC) $(CFLAGS) -DNO_MAIN -c $(PYTHON)/config/config.c

#--------------------------------------------------------------------------
# Dependencies

%.d: %.c
	$(SHELL) -ec 'gcc -MM $(CFLAGS) $< | sed "s/$*\\.o[n:]*/$@ &/g" >$@'

include $(SRCS:.c=.d)

