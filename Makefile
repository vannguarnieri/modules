CFLAGS=	-Wall -pedantic -std=c11  -I. -g

all: test

list.o:	list.c list.h
	gcc $(CFLAGS) -c list.c

test.o: test.c list.h
	gcc $(CFLAGS) -c test.c

test:	list.o test.o
		gcc $(CFLAGS) test.o list.o -o test

clean:
	rm -f *.o test
