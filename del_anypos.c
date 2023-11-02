#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void del_pos(struct node **head, int pos)  
{
    struct node *current = *head;
    struct node *previous = *head;
    if(*head==NULL)
    {
        printf("The list is empty");
    }
    else if(pos==1)
    {
        *head = current->next;
        free(current);
        current = NULL;
    }
    else
    {
        while(pos!=1)
        {
            previous = current;
            current = current->next;
            pos--;
        }
        previous->next = current->next;
        free(current);
        current = NULL;
    }

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

    del_pos(&head, 4);
    traversal(head);

    return 0;

}
