#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node* prev;
    char val;
    struct Node* next;
}Node;

Node* head = NULL;
Node* tail;

void add_new_node(char val)
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

void rotate(int x)
{
    while(x)
    {
        tail->next = head;
        head->prev = tail;
        head = tail;
        tail = tail->prev;
        tail->next = NULL;
        x--;
    }
    return;
}

void display()
{
    Node* loop = head;
    printf("\nThe elements of the list are: ");
    while(loop != NULL)
    {
        printf("%c ",loop->val);
        loop = loop->next;
    }
    return;
}

int main()
{
    add_new_node('a');
    add_new_node('b');
    add_new_node('c');
    add_new_node('d');
    add_new_node('e');
    int x;
    printf("\nList before rotation:\n");
    display();
    printf("\n\nEnter positions to rotate: ");
    scanf("%d",&x);
    printf("\nList after rotation:\n");
    rotate(x);
    display();
    printf("\n");
    return 0;
}
