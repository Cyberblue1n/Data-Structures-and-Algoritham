//Creating a single linked list without using user input
//And also not display the elements
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *next;
};
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

    return 0;

}
