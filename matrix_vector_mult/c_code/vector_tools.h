#ifndef VECTOR_TOOLS_H
#define VECTOR_TOOLS_H

typedef struct 
{
    unsigned int size; // # of rows
    double* data;
} vector_t;

void allocate_v(vector_t *vec, unsigned int m);

void assign_v(vector_t *vec, double offset);

void deallocate_v(vector_t *vec);

void print_v(vector_t *vec);

#endif
