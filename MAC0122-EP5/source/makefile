CFLAGS=-Wall -O2 -ansi -pedantic -Wno-unused-result
CC=gcc
RM=rm -f

#-------------------------------------------------


ep5: utils.o iofilmes.o filmes.o  main.o
	$(CC) utils.o iofilmes.o filmes.o main.o -o ep5

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

filmes.o: filmes.h filmes.c
	$(CC) $(CFLAGS) -c filmes.c

iofilmes.o: iofilmes.h iofilmes.c
	$(CC) $(CFLAGS) -c iofilmes.c

utils.o: utils.h utils.c
	$(CC) $(CFLAGS) -c utils.c

clean: 
	$(RM) *.o *~
