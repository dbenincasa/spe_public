# A fifth Makefile: a final maquillage

CC=gcc
CFLAGS=-c

TEST = testing.x
TEST_SRC = main.c
TEST_OBJ = $(TEST_SRC:.c=.o)

SRCS = matrix_tools.c vector_tools.c
OBJS = $(SRCS:.c=.o)


# say that we want linking roules a little 
# different

LD=gcc
LDOPTS=-o

test : $(TEST)

debug: CFLAGS += -g -DDEBUG
debug: $(TEST)

$(TEST): $(TEST_OBJ) $(OBJS)
	$(LD) $(LDOPTS) $(TEST) $(TEST_OBJ) $(OBJS)

# Pattern rule, tells that
# the target n.o dependes
# on n.c source

# Automatic variable, the first dependency on the list
	
%.o: %.c
	$(CC) $(CFLAGS) $<

clean:
	rm *.x *.o
