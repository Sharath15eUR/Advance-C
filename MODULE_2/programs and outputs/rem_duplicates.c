#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node* next;
}node;
int len = 0;
struct node* head;
struct node* tail;

void add_new_node(int val)
{
    if(len == 0)
    {
        head = (node*) malloc(sizeof(node));
        head->val = val;
        head->next = NULL;
        tail = head;
        len++;
        return;
    }
    node* newnode = (node*)malloc(sizeof(node));
    newnode->val = val;
    newnode->next = NULL;
    tail->next = newnode;
    tail = newnode;
    len++;
}

void display()
{
    node* loop = head;
    printf("The elements of the linked list are:\n");
    while(loop != NULL)
    {
        printf("%d ",loop->val);
        loop = loop->next;
    }
    return;
}



void rem_duplicates()
{
    node* prev = head;
    node* curr;
    if(head->next != NULL)
    {
        curr = head->next;
    }
    else{
        printf("Only one element found no duplicates to remove!");
        return;
    }
    while(curr != NULL)
    {
        while(prev->val == curr->val && curr!=NULL)
        {
            prev->next = curr->next;
            node* del = curr;
            curr = curr->next;
            free(del);
            len--;
        }
        prev = prev->next;
        curr = curr->next;
    }

}





int main()
{

    add_new_node(2);
    add_new_node(3);
    add_new_node(3);
    add_new_node(3);
    add_new_node(4);
    printf("\nLength before removal : %d\n\n",len);
    display();
    rem_duplicates();
    printf("\n\n\n\nLength after removal : %d\n\n",len);
    display();
    printf("\n");

    return 0;
}
