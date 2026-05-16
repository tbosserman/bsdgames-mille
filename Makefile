CC=cc
CFLAGS=-DSYSV -g

#LDADD=	-lcurses -ltermcap -lcompat
LDADD=	-lncurses
OBJ=	comp.o end.o extern.o init.o mille.o misc.o move.o print.o \
	roll.o save.o types.o varpush.o wrapper.o debug.o

mille: $(OBJ)
	$(CC) -o mille $(OBJ) $(LDADD)

clean:
	$(RM) *.o mille

comp.o: mille.h
end.o: mille.h
extern.o: mille.h
init.o: mille.h
mille.o: mille.h
misc.o: mille.h
move.o: mille.h
print.o: mille.h
roll.o: mille.h
save.o: mille.h
table.o: mille.h
types.o: mille.h
varpush.o: mille.h
: mille.h
