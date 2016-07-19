#include <stdio.h>
#include <stdlib.h>

#include "matrix_tools.h"

int main() {

    printf("Sto grandissimo cazzo\n");
    
    matrix_t a;    

    allocate(&a,3,2);
    
    assign(&a,5);
    
    print(&a);
    
    deallocate(&a);

    return 0;
}
