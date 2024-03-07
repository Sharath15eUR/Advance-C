#include <stdio.h>
#include <stdlib.h>


int is_subset(int* a,int* b,int a_size,int b_size)
{
    for(int i=0;i<b_size;i++)
    {
        int flag = 0;
        for(int j=0;j<a_size;j++)
        {
            if(b[i] == a[j])
            {
                flag = 1;
            }
        }
        if(flag == 0)
            return 0;
    }
    return 1;
}


int main()
{
    int a,b;
    printf("Enter the number of elements in array 1: ");
    scanf("%d",&a);
    printf("\nEnter the number of elements in array 2: ");
    scanf("%d",&b);
    int arr_1[a],arr_2[b];
    printf("\nEnter the elements of array_1:\n");
    for(int i=0;i<a;i++){
        printf("\narray_1[%d]: ",i);
        scanf("%d",&arr_1[i]);
    }
    printf("\nEnter the elements of array_2:\n");
    for(int i=0;i<b;i++){
        printf("\narray_2[%d]: ",i);
        scanf("%d",&arr_2[i]);
    }

    if(b<a && is_subset(arr_1,arr_2,a,b))
        printf("\nArray 2 is the subset of Array 1.");
    else
        printf("\nArray 2 is not a subset of Array 1.");

    printf("\n");
    return 0;
}
