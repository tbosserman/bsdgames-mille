CC=cc
CFLAGS=-DSYSV -O

#LDADD=	-lcurses -ltermcap -lcompat
LDADD=	-lncurses
OBJ=	comp.o end.o extern.o init.o mille.o misc.o move.o print.o \
	roll.o save.o types.o varpush.o wrapper.o

mille: $(OBJ)
	$(CC) -o mille $(OBJ) $(LDADD)

clean:
	$(RM) *.o mille
