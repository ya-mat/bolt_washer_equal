LINKER	     = g++
CC	     = g++
LDFLAGS     = 
#INCLUDE     = -I/usr/include/eigen3
#INCLUDE     = -I/home/matsumoto/matsumoto/github/lapack_etc_make -I/usr/include/python3.9
#INCLUDE     = -I/home/matsumoto/matsumoto/github/lapack_etc_make
#COPTS	     = -cpp -O3 -fmax-errors=3 --pedantic-errors -std=c++2a
#COPTS	     = -cpp -O2 -fmax-errors=3 -Wall --pedantic-errors -std=c++2a
COPTS	     = -cpp -Og -fmax-errors=3 -g -Wall --pedantic-errors -std=c++2a
#COPTS	     = -cpp -O0 -fmax-errors=3 -Wall --pedantic-errors -std=c++2a

OBJS          = main.o\

PROGRAM      = a.out

all:		$(PROGRAM)

$(PROGRAM): $(OBJS)
		$(LINKER) $(COPTS) $(OBJS) -o $(PROGRAM) $(LDFLAGS)

clean:
		rm -f $(PROGRAM) *.o *~ *.mod;\

.SUFFIXES: .o .cc

.cc.o :
		$(CC) $(COPTS) $(INCLUDE) -c -o $*.o $*.cc
