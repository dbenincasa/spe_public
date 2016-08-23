#include <stdio.h>
#include <stdlib.h>

#include "matrix_tools.h"
#include "vector_tools.h"

int main() {

    printf("Sto grandissimo cazzo\n");
    
    matrix_t a;    

    allocate_m(&a,2,3);
    assign_m(&a,0.);

    //assign_ij(0,0,4.,&a);
    //assign_ij(0,1,1.,&a);
    //assign_ij(1,0,1.,&a);
    //assign_ij(1,1,3.,&a);
    
    print_m(&a);

    
    vector_t v_in; 
    
    allocate_v(&v_in,3);
    assign_v(&v_in,5);
    print_v(&v_in);

    
    vector_t v_out; 
    
    allocate_v(&v_out,2);
    assign_zero_v(&v_out);
    assign_i(1,3,&v_out);

    vmult(&a, &v_in, &v_out );
    
    print_v(&v_out);
    
    vector_t v0, v1, v2;
    
    allocate_v(&v0,3);
    allocate_v(&v1,3);
    allocate_v(&v2,3);
    
    assign_v(&v0,0);
    assign_v(&v1,1);
    assign_v(&v2,2);
    
    print_v(&v0);
    print_v(&v1);
    
    prod(&v0,&v1,&v2);
    
    print_v(&v2);
    
    double sum;
    
    sum = sum_prod(&v1,&v2);
    
    printf("sum = %f\n",sum);
    
    
    deallocate_m(&a);
    deallocate_v(&v_in);
    deallocate_v(&v_out);
    deallocate_v(&v0);
    deallocate_v(&v1);
    deallocate_v(&v2);
    return 0;
}
