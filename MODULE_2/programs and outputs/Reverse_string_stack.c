#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top = -1;

void push(char* stack, char x)
{
    stack[++top] = x;
    return;
}

void pop(char* stack)
{
    printf("%c",stack[top--]);
    return;
}

int main()
{
    char string[100];
    printf("Enter the string: ");
    scanf("%[^\n]",&string);
    int len = strlen(string);
    char stack[len];

    for(int i=0;i<len;i++)
    {
        push(stack, string[i]);
    }

    printf("The reversed string is: ");
    while(top >= 0)
    {
        pop(stack);
    }
    printf("\n");
    return 0;

}
