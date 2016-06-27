#include <stdio.h>

void copy_swap ( int x , int y ) {
    int temp = x ;
    x = y ;
    y = temp ;
}

void pointer_swap ( int *x , int *y ) {
    int temp = *x ;
    *x = *y ;
    *y = temp ;
}

/* c++, c does not support pass by reference.
void reference_swap ( int &x , int &y ) {
    int temp = x ;
    x = y ;
    y = temp ;
}*/

int main() {

    int a = 5 , b = 7;

    printf("initial values:\n");    
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    copy_swap(a , b ) ;

    printf("copy swap:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    
    int* pa;
    pa = &a;
    int* pb;
    pb = &b;
    
    pointer_swap(pa,pb);
    
    printf("pointer swap:\n");
    printf("a = %d\n", *pa);
    printf("b = %d\n", *pb);
    
    
     
    return 0;
}
