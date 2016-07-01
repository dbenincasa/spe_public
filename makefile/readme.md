# Makefile

## Ex1

```
                   |-----------------|
                   | target: program |
                   |-----------------|
                            /\
                    _______/  \______
                   /                 \
                  /                   \
                  |                   |
                  V                   V
|-----------------------|     |---------------------|
| dependence: program.c |     | dependence: funcs.c |
|-----------------------|     |---------------------|

```

## Ex2

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

 - Some useful macros.
 
 - Additional targets.
 
 ```
 clean:
	rm $(EXE) *.o
 ```
