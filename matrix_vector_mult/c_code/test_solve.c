#include <stdio.h>
#include <stdlib.h>

#include "solver.h"

int main() {

    printf("Sto grandissimo cazzo\n");

    matrix_t a;

    unsigned int n = 2;

    allocate_m(&a,n,n);

    assign_ij(0,0,4.,&a);
    assign_ij(0,1,1.,&a);
    assign_ij(1,0,1.,&a);
    assign_ij(1,1,3.,&a);

    print_m(&a);


    vector_t x, b;

    allocate_v(&x,n);
    allocate_v(&b,n);
    assign_i(0,2.,&x);
    assign_i(1,1.,&x);
    print_v(&x);
    
    
    assign_i(0,1.,&b);
    assign_i(1,2.,&b);

    conjugate_gradient(&a, &x, &b);

    deallocate_m(&a);
    deallocate_v(&x);
    deallocate_v(&b);

    return 0;
}
