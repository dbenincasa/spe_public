/* fprintf example */
#include <stdio.h>

int main ()
{
   FILE * output;
   output = fopen("output.txt","w");
   fprintf (output, "ciao bel\n");
   fclose (output);

   return 0;
}
