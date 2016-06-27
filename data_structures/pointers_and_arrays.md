# Pointers and arrays

We learn by mistakes: 
```
void arraytest(int a[])
{
    // changed the array a
    a[0]=a[0]+a[1];
    a[1]=a[0]-a[1];
    a[0]=a[0]-a[1];
}

void main()
{
    int arr[]={1,2};
    printf("%d \t %d",arr[0],arr[1]);
    arraytest(arr);
    printf("\n After calling fun arr contains: %d\t %d",arr[0],arr[1]);
}
```
In this code the non educated user expects the 
compiler to copy the aray into the `araytest` scope and manipulate the memory
inside the scope. 

Now comes a question: "How the compile nows at run time, what's the size of the
memory he has to copy?". We already know the answer: he does not know. 

This is why the compiler substitutes the original function
`void arraytest(int a[])` with:
```
void arraytest(int *a)
{
    // changed the array a
    a[0]=a[0]+a[1];
    a[1]=a[0]-a[1];
    a[0]=a[0]-a[1];
}
```
