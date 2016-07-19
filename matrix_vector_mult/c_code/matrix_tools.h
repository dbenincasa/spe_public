#ifndef MATRIX_TOOLS_H
#define MATRIX_TOOLS_H

typedef struct matrix
{
    unsigned int m; // # of rows
    unsigned int n; // # of colums
    double* data;
} matrix_t;

void allocate(matrix_t *mat, unsigned int m, unsigned int n);

void assign(matrix_t *mat, double offset);

void deallocate(matrix_t *mat);

void print(matrix_t *mat);

#endif
