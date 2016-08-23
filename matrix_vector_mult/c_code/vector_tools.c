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

void assign_i(const unsigned int i, const double val, vector_t *vec)
{
   vec->data[i] = val;
}

void assign_zero_v(vector_t *vec)
{
  unsigned int i = 0;
  
  for (i = 0; i< vec->size; i++)
         vec->data[i] = 0.;
}

void diff( vector_t *a_in, vector_t *b_in, vector_t *c_out)
{
  unsigned int i = 0;
  
  for (i = 0; i< c_out->size; i++)
         c_out->data[i] = a_in->data[i] - b_in->data[i];
}

void prod( vector_t *a_in, vector_t *b_in, vector_t *c_out)
{
  unsigned int i = 0;
  
  for (i = 0; i< c_out->size; i++)
         c_out->data[i] = a_in->data[i] * b_in->data[i];
}

void dump_b_into_a( vector_t *a_in, vector_t *b_in)
{
  unsigned int i = 0;
  
  for (i = 0; i< b_in->size; i++)
         a_in->data[i] = b_in->data[i];
}

double sum_prod( vector_t *a_in, vector_t *b_in)
{
  unsigned int i = 0;
  double sum = 0;
  
  for (i = 0; i< a_in->size; i++)
         sum+= a_in->data[i] * b_in->data[i];
         
  return sum;
}

void scale(vector_t *a_in, double val)
{
  unsigned int i = 0;
  
  for (i = 0; i< a_in->size; i++)
         a_in->data[i] *= val;
}

void a_equals_a_minus_alpha_b(vector_t *a_in, vector_t *b_in, double alpha)
{
  unsigned int i = 0;
  
  for (i = 0; i< b_in->size; i++)
         a_in->data[i] -= alpha*b_in->data[i];

}

void a_equals_a_plus_alpha_b(vector_t *a_in, vector_t *b_in, double alpha)
{
  unsigned int i = 0;
  
  for (i = 0; i< b_in->size; i++)
         a_in->data[i] += alpha* b_in->data[i];
}

void a_equals_b_plus_alpha_a(vector_t *a_in, vector_t *b_in, double alpha)
{
  unsigned int i = 0;
  
  for (i = 0; i< b_in->size; i++)
         a_in->data[i] = b_in->data[i] + alpha * a_in->data[i];
}
