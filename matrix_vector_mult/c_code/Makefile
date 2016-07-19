# A fifth Makefile: a final maquillage

CC=gcc
CFLAGS=-c

EXE = program
SRCS = main.c matrix_tools.c
OBJS = $(SRCS:.c=.o)

# say that we want linking roules a little 
# different

LD=gcc
LDOPTS=-o

all : $(EXE)

debug: CFLAGS += -g -DDEBUG
debug: $(EXE)

$(EXE): $(OBJS)
	$(LD) $(LDOPTS) $(EXE) $(OBJS)

# Pattern rule, tells that
# the target n.o dependes
# on n.c source

# Automatic variable, the first dependency on the list
	
%.o: %.c
	$(CC) $(CFLAGS) $<

clean:
	rm $(EXE) *.o