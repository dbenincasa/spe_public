# Setp 6: Unit Testing.

A super simple `main.c`.
```c++
#include <stdio.h>

int main ()
{
   FILE * output;
   output = fopen("output.txt","w");
   fprintf (output, "ciao bel\n");
   fclose (output);

   return 0;
}
```
Notice that the output is saved to a *special* file called `output.txt`