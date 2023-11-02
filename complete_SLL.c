//linkedlist complete program
//instructor:  1. Sutapa ma'am   2. Neso academy
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    struct node *next;
};
struct node *create(struct node *head)
{
    int a;
    printf("\nEnter your data or stop by -999\n");
    scanf("%d",&a);
    struct node *current,*ptr;
    head=ptr=NULL;
    while(a!=-999)
    {
        current = (struct node *)malloc(sizeof(struct node));
        current->data = a;
        current->next = NULL;
        if(head==NULL)
        {
            head = current;
        }
        else
        {
            ptr->next = current;
        }
        ptr = current;
        printf("\nEnter your data or stop by-999\n");
        scanf("%d",&a);
    }
    return head;
}
void add_at_pos(struct node *head)
{
    int pos, a;
    printf("Enter number you want to insert: ");
    scanf("%d",&a);
    printf("Position: ");
    scanf("%d",&pos);
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
void del_pos(struct node **head)  
{
    int pos;
    printf("Enter position you want to delete: ");
    scanf("%d",&pos);
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
        int count = 1;
        while(current!=NULL && count<pos)
        {
            previous = current;
            current = current->next;
            count++;
        }
        if(current==NULL)
        {
            printf("Position %d is not found in the list \n",pos);
        }
        previous->next = current->next;
        free(current);
        current = NULL;
    }

}    
void display(struct node *head)
{
    if(head==NULL)
    {
        printf("List is empty");
    }
    struct node *ptr;
    ptr = head;
    printf("\nYou list contains: \n");
    while(ptr!=NULL)
    {
        printf("%4d",ptr->data);
        ptr=ptr->next;
    }
}
int main()
{
    struct node *head;
    char c;
    int quit = 0;
    printf("\nCreate/Insert/Delete/Quit (C/I/D/Q)");
    do 
    {
        printf("\nEnter choice: ");
        scanf(" %c",&c);
        switch (c)
        {
        case 'c':
        case'C':
            head = create(head);
            display(head);
            break;
        case 'i':
        case 'I':
            add_at_pos(head);
            printf("\n Linked list after insertion");
            display(head);
            break;
        case 'd':
        case 'D':
            del_pos(&head);
            printf("\n Linked list after deletion");
            display(head);
            break;
        case 'q':
        case 'Q':
            exit(0);
            break;
        }
        /*clear the input buffer to remove any remaining
        newline characters*/
        while(getchar()!='\n')
        {
            continue;
        }
    }
    while(!quit);
    return 0;
}