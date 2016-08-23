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

void diff(vector_t *a_in, vector_t *b_in, vector_t *c_out);
// c_out = a_in - b_in

void dump_b_into_a(vector_t *a_in, vector_t *b_in);
// a_in <- b_in

void deallocate_v(vector_t *vec);

void print_v(vector_t *vec);

void scale(vector_t *a_in, double val);

void a_equals_a_minus_alpha_b(vector_t *a_in, vector_t *b_in, double alpha);

void a_equals_a_plus_alpha_b(vector_t *a_in, vector_t *b_in, double alpha);


#endif
