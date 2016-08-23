# A fifth Makefile: a final maquillage

CC=gcc
CFLAGS=-c

SOLVER = solver.x
SOLVER_SRC = solver.c
SOLVER_OBJ = $(SOLVER_SRC:.c=.o)

TEST = testing.x
TEST_SRC = test.c
TEST_OBJ = $(TEST_SRC:.c=.o)

SRCS = matrix_tools.c vector_tools.c
OBJS = $(SRCS:.c=.o)


# say that we want linking roules a little 
# different

LD=gcc
LDOPTS=-o

all : $(TEST)

test : $(TEST)

solver : $(SOLVER)

debug: CFLAGS += -g -DDEBUG
debug: $(TEST)

$(TEST): $(TEST_OBJ) $(OBJS)
	$(LD) $(LDOPTS) $(TEST) $(TEST_OBJ) $(OBJS)
	
$(SOLVER): $(SOLVER_OBJ) $(OBJS)
	$(LD) $(LDOPTS) $(SOLVER) $(SOLVER_OBJ) $(OBJS)

# Pattern rule, tells that
# the target n.o dependes
# on n.c source

# Automatic variable, the first dependency on the list
	
%.o: %.c
	$(CC) $(CFLAGS) $<

clean:
	rm *.x *.o
