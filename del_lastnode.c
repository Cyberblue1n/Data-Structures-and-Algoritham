#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* delete_lastnode(struct node *head)
{
    if(head==NULL)
    {
        printf("List is empty");
        return NULL;
    }
    else if(head->next == NULL)
    {
        free(head);
        head = NULL;
        return NULL;
    }
    else
    {
        struct node *temp = head;
        struct node *temp2 = head;
        while(temp->next!=NULL)
        {
            temp2 = temp;
            temp = temp->next;
        }
        temp2->next = NULL;
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

    head = delete_lastnode(head);
    traversal(head);

    return 0;

}
