#include <stdlib.h>
#include <stdio.h>


int main(){

    int n=5;
    int m=2;
    int a[n][m];
    int **b;
    int i,j;

    b= (int**)malloc(n*sizeof(int*));
    for (i=0;i<n;i++)
		b[i]=(int*)malloc(m*sizeof(int));

    for (i=0;i<n;i++)
	for (j=0;j<m;j++)
		{
		a[i][j]=i*m+j;
		b[i][j]=i*m+j;
		}

    for (i=0;i<n;i++)
	{
        for (j=0;j<m;j++)
		{
		printf("%d ",a[i][j]);
		}
	printf("\n");
	}

    for (i=0;i<n;i++)
        {
        for (j=0;j<m;j++)
                {
                printf("%d ",b[i][j]);
                }
        printf("\n");
        }



    printf(" size of int %ld and int* %ld\n", sizeof(int), sizeof(int*));
    printf(" address of a[0][0]: %p | address of a[0][1]: %p. Distance is %ld bytes and should be %ld bytes \n",&a[0][0], &a[0][1], (&a[0][1]-&a[0][0])*sizeof(int), sizeof(int));
    printf(" address of b[0][0]: %p | address of b[0][1]: %p. Distance is %ld bytes and should be %ld bytes \n",&b[0][0], &b[0][1], (&b[0][1]-&b[0][0])*sizeof(int), sizeof(int));
    printf(" address of a[0][0]: %p | address of a[1][0]: %p. Distance is %ld bytes and should be %ld bytes \n",&a[0][0], &a[1][0], (&a[1][0]-&a[0][0])*sizeof(int), m*sizeof(int));
    printf(" address of b[0][0]: %p | address of b[1][0]: %p. Distance is %ld bytes and should be %ld bytes \n",&b[0][0], &b[1][0], (&b[1][0]-&b[0][0])*sizeof(int), m*sizeof(int));

    for (i=0;i<n;i++)
        {
	free(b[i]);
	}
     free(b);

     return 0;
}
