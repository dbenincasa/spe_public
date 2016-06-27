# Playng with Pointers.

The variable, the reference and the pointer:
```
#include <stdio.h>

int main(){
    int i = 1;
    int* pt = &i;
    *pt = 100;
    printf("the reference to the variable is: %p\n", &i);
    printf("  the pointer to the variable is: %p\n", pt);
    printf("    the value of the variable is: %d\n", *pt);
    return 0;
}
```
The line `int* pt = &i;` does two things at the same time:

 1. declares a pointer to an integer type of data named pt, `int* pt`.
 2. assings to the pointer `pt` the address corresponding to the reference 
 of the variable `i`.

We learn by mistakes:
```
int main(){
    int* pt = NULL;
    *pt = 100;
    printf("%d\n",*pt);
    return 0;
}
```
 dereferencing a NULL pointer (i.e. you try to store value 100 into the 
 memory at address NULL), which results in undefined behavor. If you want to 
 avoid declaring a variable try:
```
 int main(){
    int i = 1;
    int* pt = &1;
    *pt = 100;
    printf("%d\n",*pt);
    return 0;
}
```
Swapping, without pointers:
```
void swap ( int x , int y )
{
int temp = x ;
x = y ;
y = temp ;
}
int a = 5 , b = 7;
swap(a , b ) ;
```
`a = 5`, `b = 7` still, because the two values are coied in the scope of the 
function and there they stay...
Swapping, without pointers:
```
void swap ( int *x , int *y ) {
int temp = *x ;
∗x = ∗y ;
∗y = temp ;
}
int a = 5 , b = 7 ;
swap(&a , &b ) ;
/∗ now , a = 7 , b = 5 ∗/
```
[Link to the code.](https://github.com/sissa/scientific_programming_environment/blob/master/data_structures/swap.c)


Pure sadism assining an address to a pointer:
```
char * p = (char *)0x28ff44;
```
