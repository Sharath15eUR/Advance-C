#include<stdio.h>

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}


int main()
{
    int a,b;
    printf("Enter the first number: ");
    scanf("%d",&a);
    printf("Enter the second number: ");
    scanf("%d",&b);
    printf("The numbers before swapping\na = %d\nb = %d\n",a,b);
    void (*swapper)(int*, int*) = swap;
    (*swapper)(&a,&b);
    printf("The numbers after swapping\na = %d\nb = %d\n",a,b);
    return 0;
}
