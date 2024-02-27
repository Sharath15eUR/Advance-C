
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    if(n & 1)
    {
        printf("\nThe Entered number %d is odd.\n",n);
    }
    else
    {
        printf("\nThe Entered number %d is even.\n",n);
    }
    return 0;
}

