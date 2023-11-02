#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *next;
};
void add_at_pos(struct node *head, int a, int pos)
{
    struct node *ptr = head;
    struct node *ptr2;
    ptr2 = (struct node *)malloc(sizeof(struct node));
    ptr2->data = a;
    ptr2->next = NULL;
    pos--;
    while(pos!=1)
    {
        ptr=ptr->next;
        pos--;
    }
    ptr2->next = ptr->next;
    ptr->next = ptr2;

}
void traversal(struct node *head)
{
    if(head==NULL)
    {
        printf("List is empty");
    }
    struct node *ptr;
    ptr = head;
    while(ptr!=NULL)
    {
        printf(" %d",ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 47;
    head->next = NULL;

    struct node *current;
    current = malloc(sizeof(struct node));
    current->data = 90;
    current->next = NULL;
    head->next = current;

    current = malloc(sizeof(struct node));
    current->data = 37;
    current->next = NULL;
    head->next->next = current;

    current = malloc(sizeof(struct node));
    current->data = 51;
    current->next = NULL;
    head->next->next->next = current;

    add_at_pos(head,36,2);
    traversal(head);

    return 0;

}
