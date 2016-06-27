#include <stdio.h>
#include <stdlib.h>

int foo()
{
  int* pBuffer; //<--nothing allocated yet (excluding the pointer itself, which is allocated here on the stack).
  int b = 0; // Allocated on the stack.
  if(b==0)
  {
    //Create 500 bytes on the stack
    char buffer[500];

    //Create 500 bytes on the heap
    
    pBuffer= (int*)malloc(500*sizeof(int));
    
    //pBuffer = new char[500];

   }//<-- buffer is deallocated here, pBuffer is not
}//<--- oops there's a memory leak, I should have called delete[] pBuffer;

int main()
{
   foo();
   return 0;
}
