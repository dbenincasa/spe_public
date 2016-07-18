#include <stdio.h>
#include <stdlib.h>

int main()
{
   function_one();
   printf("Hi from the main file\n");
   #ifdef DEBUG
   printf("This is the debug version of the main file\n");
   #endif
   return 0;
}
