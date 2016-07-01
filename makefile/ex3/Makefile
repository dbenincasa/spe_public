# A third Makefile: the usage of macros

CC=gcc

CFLAGS=-c

program: program.o funcs.o
	$(CC) -o program program.o funcs.o
	
program.o: program.c
	$(CC) $(CFLAGS) program.c

funcs.o: funcs.c
	$(CC) $(CFLAGS) funcs.c
