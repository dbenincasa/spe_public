#include <stdio.h>
#include <stdlib.h>

#include "matrix_tools.h"
#include "vector_tools.h"

int main() {

    printf("Sto grandissimo cazzo\n");
    
    matrix_t a;    

    allocate_m(&a,3,2);
    assign_m(&a,5);
    print_m(&a);
    deallocate_m(&a);
    
    vector_t v; 
    
    allocate_v(&v,3);
    assign_v(&v,5);
    print_v(&v);
    deallocate_v(&v);

    return 0;
}
