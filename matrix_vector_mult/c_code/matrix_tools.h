#ifndef MATRIX_TOOLS_H
#define MATRIX_TOOLS_H

#include "vector_tools.h"

typedef struct matrix
{
    unsigned int m; // # of rows
    unsigned int n; // # of colums
    double* data;
} matrix_t;

void allocate_m(matrix_t *mat, unsigned int m, unsigned int n);

void assign_m(matrix_t *mat, double offset);

void assign_zero_m(matrix_t *mat);

void assign_ij(const unsigned int i, const unsigned int j, 
               const double val, matrix_t *mat);

void deallocate_m(matrix_t *mat);

void print_m( matrix_t *mat);

void vmult( matrix_t *mat, vector_t *v_in, vector_t *v_out );

#endif
