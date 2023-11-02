#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* delete_node(struct node *head)
{
    if(head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
        temp = NULL;
    }
    return head;
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

    
    head = delete_node(head);
    traversal(head);

    return 0;

}
