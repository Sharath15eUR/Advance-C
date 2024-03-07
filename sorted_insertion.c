#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node* prev;
    int val;
    struct Node* next;
}Node;

Node* head = NULL;
Node* tail;

void add_new_node(int val)
{
    if(head == NULL)
    {
        head = (Node*)malloc(sizeof(Node));
        head->prev = NULL;
        head->val = val;
        head->next = NULL;
        tail = head;
        return;
    }
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->val = val;
    newnode->next = NULL;
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
    return;
}

void insert(int x)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->val = x;
    Node* loop  = head;
    while(loop->next != NULL && loop->next->val<x)
    {
        loop = loop->next;
    }
    newnode->next = loop->next;
    loop->next->prev = newnode;
    loop->next = newnode;
    newnode->prev=loop;
    return;
}

void display()
{
    Node* loop = head;
    printf("\nThe elements of the list are: ");
    while(loop != NULL)
    {
        printf("%d ",loop->val);
        loop = loop->next;
    }
    return;
}

int main()
{

    for(int i=1;i<=20;i++)
    {
        if(i%3==0){
            continue;
        }
        else
            add_new_node(i);
    }
    printf("The initial list is:\n");
    display();

    int x;
    printf("\nEnter an element to insert: ");
    scanf("%d",&x);
    insert(x);
    printf("\nAfter insertion:\n");
    display();


    return 0;
}
