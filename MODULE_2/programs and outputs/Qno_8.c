#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node* next;
}node;
struct node* front = NULL;
struct node* back;

void push_back(int val)
{
    if(front == NULL)
    {
        front = (node*) malloc(sizeof(node));
        front->val = val;
        front->next = NULL;
        back = front;
        return;
    }
    node* newnode = (node*)malloc(sizeof(node));
    newnode->val = val;
    newnode->next = NULL;
    back->next = newnode;
    back = newnode;
    return;
}

void pop_front()
{
    node* del = front;
    front = front->next;
    printf("The popped element is :%d\n",del->val);
    free(del);
    return;
}

int is_empty()
{
    if(front == NULL)
        return 1;
    else
        return 0;
}

int count()
{
    int len = 0;
    node* loop = front;
    while(loop != NULL)
    {
        len++;
        loop = loop->next;
    }
    return len;
}


void display()
{
    node* loop = front;
    printf("The elements of the queue are: ");
    while(loop != NULL)
    {
        printf("%d ",loop->val);
        loop = loop->next;
    }
    return;
}



int main()
{
    int x = is_empty();
    if(x)
        printf("The queue is empty!\n");
    else
        printf("The queue is not empty!\n");

    push_back(1);
    push_back(2);
    push_back(3);
    display();
    printf("\nNumber of elements in the queue: %d\n",count());
    pop_front();
    pop_front();
    display();
    printf("\nNumber of elements in the queue: %d\n",count());
    push_back(4);
    display();
    printf("\nNumber of elements in the queue: %d\n",count());

    printf("\n");

    return 0;
}
