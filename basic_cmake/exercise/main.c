#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void matml_(int n, int *a, int *b, int *c);

int main(int argc, char** argv)
{
    int i,j,n,index;
    double *a,*b,*c;
    clock_t start,end;
#ifdef USEBLAS
    const char TRANS='N';
    const double alpha=1.0;
    const double beta=1.0; 
#endif 


    if (argc<2)
       {
       printf(" Usage: %s [Size of the matrix] \n", argv[0]);
       return 1;
       }

    n=atoi(argv[1]);
    a=(double*)malloc(n*n*sizeof(double));
    b=(double*)malloc(n*n*sizeof(double));
    c=(double*)malloc(n*n*sizeof(double));

    index=1.0;
    // here we fill the matrix with element index. We fill by column, since we will pass it to a fortran subroutine. 
    // It's we are passing the transpose
    for (i=0;i<n;i++)
        {
        for (j=0;j<n;j++)
            {
            a[j*n+i]=index;
            b[j*n+i]=index+n*n;
            c[i*n+j]=0.0;
            index++;
            }
        }
    start = clock(); 
#ifdef USEBLAS
    dgemm_(&TRANS,&TRANS,&n,&n,&n,&alpha,a,&n,b,&n,&beta,c,&n);
#else
    matmul_(&n,a,b,c);
#endif
    end = clock();
#ifdef USEBLAS
    printf(" dgemm took: %f seconds \n",(double)(end-start)/CLOCKS_PER_SEC);
#else
    printf(" Matmul took: %f seconds \n",(double)(end-start)/CLOCKS_PER_SEC);
#endif 
    
    FILE * output;
    output = fopen("output.txt","w");
   
    if (n<11)
       {
       for (i=0;i<n;i++)
           {
           for (j=0;j<n;j++)
               {
               fprintf(output, " %8.3f ", c[j*n+i]);
               }
           fprintf(output, " \n");
           }
       }
    fclose (output);
    free(a);
    free(b);
    free(c);
    return 0;
}
