#include <stdio.h>
#include <stdlib.h>

#include "matrix_tools.h"

void allocate(matrix_t *mat, unsigned int m, unsigned int n)
{
    mat->m = m;
    mat->n = n;
    mat->data=(double*)malloc(m*n*sizeof(double));
};

void assign(matrix_t *mat, double offset)
{
  unsigned int i = 0, j=0;
  
  for (i = 0; i< mat->m; i++)
      for (j = 0; j< mat->n; j++)
         mat->data[i*mat->n+j] = offset + i*mat->n+j;
};

void deallocate(matrix_t *mat)
{
   mat->m = 0;
   mat->n = 0;
   free(mat->data);
};

void print(matrix_t *mat)
{
  unsigned int i = 0, j=0;
  
  printf("matrix rows = %d\n",mat->m);
  printf("matrix cols = %d\n",mat->n);
  
  for (i = 0; i< mat->m; i++)
  {
      for (j = 0; j< mat->n; j++)
      {
         printf("%f, ",mat->data[i*mat->n+j]);
      }
      printf("\n");
  }
};
