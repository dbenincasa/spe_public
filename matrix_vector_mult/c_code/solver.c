#include <stdio.h>
#include <stdlib.h>

#include "matrix_tools.h"
#include "vector_tools.h"

void conjugate_gradient(matrix_t *mat, vector_t *x, vector_t *b)
{
}

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


    vector_t x;

    allocate_v(&x,n);
    assign_i(0,2.,&x);
    assign_i(1,1.,&x);
    print_v(&x);

    vector_t r, b, p, tmp;

    allocate_v(&r,n);
    allocate_v(&p,n);
    allocate_v(&b,n);
    allocate_v(&tmp,n);

    assign_zero_v(&r);
    assign_zero_v(&tmp);

    assign_i(0,1.,&b);
    assign_i(1,2.,&b);

    vmult(&a,&x,&tmp);

    diff(&b,&tmp,&r);

    print_v(&r);

    dump_b_into_a(&p,&r);

    double res_old = sum_prod(&r,&r);

    printf("res_old = %f\n",res_old);

    unsigned int iter = 0;

    for (iter = 0; iter<1; iter++)
    {
        vmult(&a,&p,&tmp);
        double den = sum_prod(&p,&tmp);
        double alpha = res_old/den;
        printf("alpha = %f\n",alpha);
        a_equals_a_plus_alpha_b(&x,&p,alpha);
        a_equals_a_minus_alpha_b(&r,&tmp,alpha);
        print_v(&r);
        double res_new = sum_prod(&r,&r);
        double beta = res_new/res_old;
        printf("beta = %f\n",beta);
        a_equals_b_plus_alpha_a(&p,&r,beta);
        print_v(&p);
    }

    deallocate_m(&a);
    deallocate_v(&x);
    deallocate_v(&r);
    deallocate_v(&p);
    deallocate_v(&b);
    deallocate_v(&tmp);

    return 0;
}
