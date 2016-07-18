# Makefile

## Ex1: target, dependences, recipie.
Suppose you have a main file `main.c` and a 
`funcs.c` file conaining the functions you implemented.

You would like to have a `target`, your executable, that 
has two `dependencies`, your source files. The target is the 
result of a `recipie`, meaning, your command to compile your executable.

A simple graph representing the situation follows:

```
                   |-----------------|
                   | target: program |
                   |-----------------|
                            /\
                           /  \
                          /    \
                         V      V 
 |-----------------------|      |---------------------|
 | dependence: program.c |      | dependence: funcs.c |
 |-----------------------|      |---------------------|
```

The makefile provides a language to combine, `targets`, `dependencies` , 
and `recipies`:

```
target: dependencie_0.c dependencie_1.c
tab-space recipie 
```

Mutatis mutandis:

```
program: program.c funcs.c
	gcc -o program program.c funcs.c
```

## Ex2

In the second exercise we expand the first makefile, in 
such a way that if we modifay only the one source file, only the corresponding 
object file is created:


We firste define the linking phase:

```
program: program.o funcs.o
	gcc -o program program.o funcs.o
```

Then we have the compilation of each object file, following the `targets`, `dependencies` , 
and `recipies` scheme.

```
program.o: program.c
	gcc -c program.c

funcs.o: funcs.c
	gcc -c funcs.c
```


## Ex3: Macros

Onece we understood the mechanics of a Makefile, there are 
serveral useful features (there are a pletora of features, but we are going to 
see just a few of them). 


 - easy way to change items that appears in many places of your makefile.
 - By convention macro names should be uppercase, but lowercase letters, 
   numbers and underscores are safe to use also. `SOMEMACRO=somemacro`
 - Macros are used in the Makefile by bracketing the macro name with either 
   parentheses `()` or braces`{}` and prepending a dollar sign `$`. `$(SOMEMACRO)`
   `${SOMEMACRO}`
   
## Ex4: Suffix Rules and Automatic Variables

 - *Suffix Rules*: you can give make a set of rules for creating files with a
certain suffix from file with the same root file name but a
different suffix. Otherwise said: generic rules to converting, say .f90 files to .o
files

 - *Automatic Variables*
   - '$@' the name of the target of the current recipe
   - '$<' the name of the first dependency
   - '$^' the entire list of dependencies
   - '$?' The names of all the prerequisites that are newer than the target
   - And many others...

This translates in a very simple modification of the makefile:

```
program.o: program.c
	$(CC) $(CFLAGS) program.c

funcs.o: funcs.c
	$(CC) $(CFLAGS) funcs.c
```

Becomes:

```
%.o: %.c
	$(CC) $(CFLAGS) $<
```
  
## Ex5: A Little Maquillage of the Makefile

 - With these macros:

  ```
  EXE = program
  SRCS = program.c funcs.c
  OBJS = $(SRCS:.c=.o)

  LD=gcc
  LDOPTS=-o
  ```
  The target:

  ```
  program: program.o funcs.o
	  $(CC) -o program program.o funcs.o
  ```

  Becomes:

  ```
  $(EXE): $(OBJS)
	  $(LD) $(LDOPTS) $(EXE) $(OBJS)
  ```

 - Additional targets.
 
 ```
 clean:
	rm $(EXE) *.o
 ```
 
 ## Ex6: Target Specific variables
 
[From the gnu documentation](https://www.gnu.org/software/make/manual/html_node/Target_002dspecific.html) 
There is one more special feature of target-specific variables: when you define a target-specific variable that 
variable value is also in effect for all prerequisites of this target, and all their prerequisites, etc. 
(unless those prerequisites override that variable with their own target-specific variable value). 

In `funcs.c` add the lines:

```
#ifdef DEBUG
printf("This is the debug version of the function\n");
#endif
```

In `main.c` add:

```
#ifdef DEBUG
printf("This is the debug version of the main file\n");
#endif
```

Then add the target specific variables to the Makefile:

```
debug: CFLAGS += -g -DDEBUG
debug: $(EXEC)
```

