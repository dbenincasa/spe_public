#include <stdio.h>
#include <stdlib.h>

#include "vector_tools.h"

void allocate_v(vector_t *vec, unsigned int m)
{
    vec->size = m;
    vec->data=(double*)malloc(m*sizeof(double));
};

void assign_v(vector_t *vec, double offset)
{
  unsigned int i = 0;
  
  for (i = 0; i< vec->size; i++)
         vec->data[i] = offset + i;
};

void deallocate_v(vector_t *vec)
{
   vec->size = 0;
   free(vec->data);
};

void print_v(vector_t *vec)
{
  unsigned int i = 0;
  
  printf("vector size = %d\n",vec->size);
  
  for (i = 0; i< vec->size; i++)
         printf("%f \n",vec->data[i]);
};
