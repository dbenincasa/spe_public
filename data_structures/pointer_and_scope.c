/* Created by G.P. Brandino for the Course P1.1 Scientific Programming Environment @ MHPC
 * Last Revision: July 2016 NC
 */
#include <stdio.h>
#include <stdlib.h>

void fill_int(int *p)
{
     int a=5; 
     p=&a;
}

int main()
{
   int *p;
   fill_int(p);
   printf("%d \n",*p);
   return 0;
}
