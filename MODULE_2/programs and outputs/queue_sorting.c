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


void sort()
{
    int swapped = 1;
    node* ptr;
    node* lptr = NULL;

    if (front == NULL || front->next == NULL) {
        return;
    }

    while (swapped) {
        swapped = 0;
        ptr = front;

        while (ptr->next != lptr) {
            if (ptr->val > ptr->next->val) {
                int temp = ptr->val;
                ptr->val = ptr->next->val;
                ptr->next->val = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }

        lptr = ptr;
    }
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
    push_back(4);
    push_back(2);
    push_back(7);
    push_back(5);
    push_back(1);
    printf("\nQueue before sorting:\n");
    display();
    sort();
    printf("\n\nQueue after sorting:\n");
    display();


    printf("\n");

    return 0;
}
