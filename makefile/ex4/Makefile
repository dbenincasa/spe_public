# A fourth Makefile: the usage of macros

CC=gcc
CFLAGS=-c

program: program.o funcs.o
	$(CC) -o program program.o funcs.o

# Pattern rule, tells that
# the target n.o dependes
# on n.c source

# Automatic variable, the first dependency on the list
	
%.o: %.c
	$(CC) $(CFLAGS) $<

