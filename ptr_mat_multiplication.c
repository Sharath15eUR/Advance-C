#include <stdio.h>
#include <stdlib.h>

void multiply(int n, int* mat1, int* mat2, int* result)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            *(result+i*n+j) = 0;
            for(int k=0;k<n;k++)
            {
                *(result+i*n+j) += (*(mat1 + i*n + k)) * (*(mat2 + k*n + j));
            }
        }
    }
}


int main()
{
    int n;
    printf("Enter the dimension of the matrix: ");
    scanf("%d",&n);
    int* mat1 = (int*)malloc(n*n*sizeof(int));
    int* mat2 = (int*)malloc(n*n*sizeof(int));
    int* result = (int*)malloc(n*n*sizeof(int));

    printf("\nEnter the elements of first matrix:\n");
    for(int i=0;i<n*n;i++)
    {
        printf("Enter mat%d [%d][%d]:",1,i/n,(i%n));
        scanf("%d",&mat1[i]);

    }
    printf("\nEnter the elements of second matrix:\n");
    for(int i=0;i<n*n;i++)
    {
        printf("Enter mat%d [%d][%d]:",2,i/n,(i%n));
        scanf("%d",&mat2[i]);
    }
    multiply(n,mat1,mat2,result);

    printf("\nMultiplied result:\n");
    for(int i=0;i<n*n;i++)
    {
        if(i%n==0)printf("\n");
        printf("%3d ",result[i]);

    }

}
