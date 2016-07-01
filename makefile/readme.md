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

## More Advanced Features

Onece we understood the mechanics of a Makefile, there are 
serveral useful features (there are a pletora of features, but we are going to 
see just a few of them). 

 - **Macros**
   - easy way to change items that appears in many places of your makefile.
   - By convention macro names should be uppercase, but lowercase letters, 
   numbers and underscores are safe to use also. `SOMEMACRO=somemacro`
   - Macros are used in the Makefile by bracketing the macro name with either 
   parentheses `()` or braces`{}` and prepending a dollar sign `$`. `$(SOMEMACRO)`
   `${SOMEMACRO}`
   
  

