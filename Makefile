# $Source: /home/CVSROOT/c2ada/Makefile,v $
# $Revision: 1.3 $  $Date: 1999/02/09 18:16:51 $

# This variable should point to the "gperf" executable on your
# system; cf. ftp://ftp.gnu.ai.mit.edu/pub/gnu/cperf-2.1a.tar.gz .
#
GPERF		  = /usr/bin/gperf

# This variable should point to the top-level Python distribution
# directory on your system; cf. http://www.python.org .
#
PYTHON            = /usr/lib/python2.3

## this is the library name, on my system, I had python 1.5, so the
## library was libpython1.5.so, so I type python1.5 below
PYTHON_LIB        = python2.3

## this is where python .py stuff is
PYTHON_INCLUDE    = /usr/include/python2.3

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

GNU_C_OPTS = -g -Wall -Wimplicit -Wreturn-type -MMD -trigraphs
CC = gcc 
CFLAGS= $(GNU_C_OPTS) -DDEBUG $(PYTHON_INCLUDES) $(DEF_PPATH)
LINKER		  = gcc -g

MAKEFILE= Makefile

LOCAL_LIBS	= libcbind.a

OBJS	        = ada_name.o \
		ada_perf.o \
		allocate.o \
		anonymous.o \
		aux_decls.o \
		buffer.o \
		c_perf.o \
		cbfe.o \
		context.o \
		cpp.o \
		cpp_eval.o \
		cpp_perf.o \
		errors.o \
		files.o \
		fix_stmt.o \
		format.o \
		gen.o \
		gen_expr.o \
		gen_macros.o \
		gen_stmt.o \
		hash.o \
		initializer.o \
		htype.o \
		localfunc.o \
		macro.o \
		nodeop.o \
		order.o \
		package.o \
		scan.o \
		stab.o \
		stmt.o \
		symset.o \
		types.o \
		units.o \
		y.tab.o

COMMON_OBJS	= allocate.o\
		buffer.o\
		cpp.o\
		errors.o\
		files.o\
		cpp_perf.o\
		cpp_eval.o\
		macro.o \
		hash.o

FEOBJ		= \
		ada_types.o \
		aux_decls.o \
	        cbfe.o\
		comment.o \
		configure.o \
		context.o \
		fix_stmt.o \
		gen.o\
		gen_stmt.o \
		gen_expr.o \
		gen_macros.o \
		ada_perf.o\
		ada_name.o\
		format.o\
		initializer.o \
		order.o \
		print.o \
		y.tab.o\
		scan.o\
		nodeop.o\
		package.o \
		c_perf.o\
		types.o\
		stab.o\
		stmt.o \
		symset.o \
		units.o\
		anonymous.o\
		localfunc.o

GENED_SRC	= y.tab.c\
		y.tab.h\
		c_perf.c\
		ada_perf.c\
		cpp_perf.c

SCRIPTS		= gen.last\
		gen.makefile\
		gen.diffs\
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
cbfe:	$(FEOBJ) $(LOCAL_LIBS) config.o
	@echo "LOCAL_LIBS = $(LOCAL_LIBS)" 
	@echo "LDFLAGS = $(LDFLAGS)" 
	@echo "LIBS = $(LIBS)" 
	@echo "PYTHONLIBS = $(PYTHONLIBS)"
		$(LINKER) $(LDFLAGS) $(FEOBJ) $(LOCAL_LIBS) \
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

depend: hostinfo.h y.tab.c y.tab.h cpp_perf.c ada_perf.c c_perf.c
		cdep -Mmakefile -S/usr/include *.c

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

###

ada_name.o : ada_name.c ada_name.h allocate.h comment.h configure.h \
  errors.h files.h hash.h host.h hostinfo.h il.h

ada_perf.o : ada_perf.c

ada_types.o : ada_types.c ada_types.h comment.h files.h hash.h host.h \
  hostinfo.h il.h types.h

allocate.o : allocate.c allocate.h errors.h

anonymous.o : ada_name.h ada_types.h allocate.h anonymous.c anonymous.h \
  comment.h errors.h files.h gen.h hash.h host.h hostinfo.h il.h \
  nodeop.h stab.h types.h units.h

#aux_decls.o : $(PYTHON_INCLUDE)/config.h ada_name.h \

aux_decls.o : ada_name.h \
  allocate.h aux_decls.c aux_decls.h comment.h errors.h files.h format.h \
  gen.h hash.h host.h hostinfo.h il.h nodeop.h stab.h types.h \
  units.h

buffer.o : allocate.h buffer.c buffer.h errors.h

c_perf.o : c_perf.c comment.h files.h hash.h host.h hostinfo.h il.h \
  stmt.h y.tab.h

cbfe.o : allocate.h buffer.h cbfe.c comment.h configure.h cpp.h \
  cpp_eval.h errors.h files.h hash.h host.h hostinfo.h il.h \
  macro.h symset.h types.h units.h vendor.h

cbind.o : cbind.c comment.h errors.h units.h

comment.o : allocate.h comment.c comment.h files.h format.h hash.h host.h \
  hostinfo.h il.h

#configure.o : $(PYTHON_INCLUDE)/config.h allocate.h \

configure.o :  allocate.h \
  configure.c configure.h errors.h

context.o : allocate.h comment.h context.c context.h files.h hash.h \
  host.h hostinfo.h il.h stab.h stmt.h types.h

cpp.o : allocate.h buffer.h comment.h cpp.c cpp.h cpp_eval.h cpp_hide.h \
  errors.h files.h hash.h host.h hostinfo.h il.h macro.h \
  units.h

cpp_eval.o : allocate.h buffer.h comment.h cpp.h cpp_eval.c cpp_eval.h \
  cpp_hide.h errors.h files.h hash.h host.h hostinfo.h il.h \
  macro.h

cpp_perf.o : buffer.h comment.h cpp.h cpp_eval.h cpp_hide.h cpp_perf.c \
  files.h hash.h host.h hostinfo.h il.h macro.h

errors.o : errors.c

files.o : errors.h files.c files.h hostinfo.h

fix_stmt.o : allocate.h anonymous.h aux_decls.h comment.h context.h \
  cpp_eval.h errors.h files.h fix_stmt.c fix_stmt.h gen.h hash.h host.h \
  hostinfo.h il.h localfunc.h macro.h nodeop.h package.h \
  print.h stab.h stmt.h types.h units.h

format.o : errors.h format.c format.h

gen.o : ada_name.h ada_types.h allocate.h anonymous.h aux_decls.h \
  buffer.h comment.h context.h cpp.h cpp_eval.h cpp_hide.h errors.h \
  files.h fix_stmt.h format.h gen.c gen.h gen_expr.h gen_macros.h hash.h \
  host.h hostinfo.h il.h initializer.h macro.h order.h \
  package.h stmt.h symset.h types.h units.h vendor.h

gen_expr.o : anonymous.h comment.h cpp_eval.h errors.h files.h format.h \
  gen.h gen_expr.c gen_expr.h hash.h host.h hostinfo.h il.h \
  macro.h nodeop.h print.h stmt.h types.h

gen_macros.o : ada_name.h allocate.h anonymous.h buffer.h comment.h cpp.h \
  cpp_eval.h cpp_hide.h errors.h files.h format.h gen.h gen_macros.c \
  gen_macros.h hash.h host.h hostinfo.h il.h macro.h \
  stab.h stmt.h types.h units.h

gen_stmt.o : allocate.h anonymous.h comment.h cpp_eval.h errors.h files.h \
  format.h gen.h gen_expr.h gen_stmt.c gen_stmt.h hash.h host.h \
  hostinfo.h il.h macro.h print.h stmt.h types.h

hash.o : hash.c hash.h

htype.o : htype.c

initializer.o : anonymous.h comment.h errors.h files.h fix_stmt.h \
  format.h gen.h gen_expr.h hash.h host.h hostinfo.h il.h initializer.c \
  initializer.h stmt.h types.h

localfunc.o : comment.h files.h hash.h host.h hostinfo.h il.h localfunc.c \
  localfunc.h nodeop.h stab.h stmt.h types.h

macro.o : allocate.h buffer.h comment.h cpp.h cpp_eval.h cpp_hide.h \
  errors.h files.h hash.h host.h hostinfo.h il.h macro.c \
  macro.h units.h

nodeop.o : allocate.h comment.h cpp_eval.h errors.h files.h hash.h host.h \
  hostinfo.h il.h macro.h nodeop.c nodeop.h types.h

order.o : comment.h files.h hash.h host.h hostinfo.h il.h \
  order.c order.h symset.h units.h

package.o : ada_name.h allocate.h anonymous.h comment.h context.h \
  errors.h files.h format.h gen.h hash.h host.h hostinfo.h il.h \
  package.c package.h stab.h stmt.h types.h units.h

print.o : comment.h cpp_eval.h files.h gen_expr.h gen_stmt.h hash.h \
  host.h hostinfo.h il.h macro.h print.c print.h \
  stmt.h

scan.o : allocate.h buffer.h comment.h cpp.h cpp_eval.h cpp_hide.h \
  errors.h files.h hash.h host.h hostinfo.h il.h macro.h \
  nodeop.h scan.c stab.h stmt.h types.h units.h y.tab.h

stab.o : allocate.h comment.h errors.h files.h hash.h host.h hostinfo.h \
  il.h stab.c stab.h units.h

stmt.o : allocate.h comment.h errors.h files.h fix_stmt.h format.h gen.h \
  gen_stmt.h hash.h host.h hostinfo.h il.h stab.h stmt.c \
  stmt.h types.h

#symset.o : $(PYTHON_INCLUDE)/config.h comment.h \

symset.o : comment.h \
  errors.h files.h hash.h host.h hostinfo.h il.h order.h \
  symset.c symset.h

types.o : ada_name.h allocate.h anonymous.h comment.h cpp_eval.h errors.h \
  files.h gen.h hash.h host.h hostinfo.h il.h macro.h nodeop.h \
  print.h stab.h stmt.h types.c types.h units.h

units.o : ada_name.h allocate.h comment.h cpp.h cpp_eval.h errors.h \
  files.h hash.h host.h hostinfo.h il.h macro.h \
  units.c units.h vendor.h

y.tab.o : comment.h files.h hash.h host.h hostinfo.h il.h \
  nodeop.h stab.h stmt.h types.h y.tab.c

