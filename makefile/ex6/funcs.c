#include <stdio.h>

void function_one()
{
     printf("Hi from function one\n");
     #ifdef DEBUG
     printf("This is the debug version of the function\n");
     #endif
}
