#ifndef VECTOR_TOOLS_H
#define VECTOR_TOOLS_H

typedef struct 
{
    unsigned int size; // # of rows
    double* data;
} vector_t;

void allocate_v(vector_t *vec, unsigned int m);

void assign_v(vector_t *vec, double offset);

void assign_i(const unsigned int  i, const double val, vector_t *vec);

double sum_prod(vector_t *a_in, vector_t *b_in);

void assign_zero_v(vector_t *vec);

void prod(vector_t *a_in, vector_t *b_in, vector_t *c_out);

void deallocate_v(vector_t *vec);

void print_v(vector_t *vec);

#endif
