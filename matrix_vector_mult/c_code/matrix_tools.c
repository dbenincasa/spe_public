#include <stdio.h>
#include <stdlib.h>

#include "matrix_tools.h"

void allocate_m(matrix_t *mat, unsigned int m, unsigned int n)
{
    mat->m = m;
    mat->n = n;
    mat->data=(double*)malloc(m*n*sizeof(double));
};

void assign_m(matrix_t *mat, double offset)
{
  unsigned int i = 0, j=0;
  
  for (i = 0; i< mat->m; i++)
      for (j = 0; j< mat->n; j++)
         mat->data[i*mat->n+j] = offset + i*mat->n+j;
};

void assign_zero_m(matrix_t *mat)
{
  unsigned int i = 0, j=0;
  
  for (i = 0; i< mat->m; i++)
      for (j = 0; j< mat->n; j++)
         mat->data[i*mat->n+j] = 0.;
};

void assign_ij(const unsigned int i, const unsigned int j, 
               const double val, matrix_t *mat)
{
  mat->data[i*mat->n+j] = val;
}

void deallocate_m(matrix_t *mat)
{
   mat->m = 0;
   mat->n = 0;
   free(mat->data);
};

void print_m( matrix_t *mat)
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


void vmult( matrix_t *mat,  vector_t *v_in, vector_t *v_out )
{

  unsigned int i = 0, j=0;
    
  for (i = 0; i< mat->m; i++)
  {
      double sum = 0;
      for (j = 0; j< mat->n; j++)
         sum+= mat->data[i*mat->n+j] * v_in->data[j];

      assign_i(i,sum,v_out);
  }
}
