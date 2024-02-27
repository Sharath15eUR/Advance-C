
#include<stdio.h>
int main()
{
    int num,setbits=0;
    printf("Enter a number : ");
    scanf("%d",&num);
    while(num>0)
    {
        setbits++;
        num = num >> 1;
    }
    printf("The number of setbits in the number is %d\n",setbits);
    return 0;
}





