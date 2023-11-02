#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* add_begining(struct node *head, int a)
{
    if(head==NULL)
    {
        printf("List is empty");
    }
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = a;
    ptr->next = NULL;
    
    ptr->next = head;
    head = ptr;
    return head;
}
void display(struct node *head)
{
    if(head==NULL)
    {
        printf("List is empty");
    }
    struct node *ptr;
    ptr = head;
    while(ptr!=NULL)
    {
        printf("%4d",ptr->data);
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
    current = (struct node *)malloc(sizeof(struct node));
    current->data = 90;
    current->next = NULL;
    head->next = current;

    current = (struct node *)malloc(sizeof(struct node));
    current->data = 37;
    current->next = NULL;
    head->next->next = current;

    current = (struct node *)malloc(sizeof(struct node));
    current->data = 51;
    current->next = NULL;
    head->next->next->next = current;
    
    head = add_begining(head, 12);
    
    current=head;
    
    display(head);
}