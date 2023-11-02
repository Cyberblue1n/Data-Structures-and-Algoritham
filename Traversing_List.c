//Linked list traversal
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *next;
};
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
//traversing the list
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

    traversal(head);

    return 0;

}
