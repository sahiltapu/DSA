// Adding element after a perticular value //
#include <stdio.h>
#include <stdlib.h>
typedef struct NODE
{
    int info;
    struct NODE *next, *prev;
} node;
node *create(node *);
void traverse(node *);
void reverse_traverse(node *);
void incert_after_value(node *);
int main()
{
    node *START;
    START = NULL;
    START = create(START);
    printf("\nElements of the list are :: \n");
    traverse(START);
    incert_after_value(START);
    printf("\nAfter incerting the list is :: \n");
    traverse(START);
    printf("\nReversing the list :: \n");
    reverse_traverse(START);
    return 0;
}
node *create(node *start)
{
    node *temp, *pre;
    char ch = 'y';
    if (start == NULL)
    {
        start = (node *)malloc(sizeof(node));
        printf("\nEnter 1st element of the list :: ");
        scanf("%d", &(start->info));
        start->prev = NULL;
        start->next = NULL;
    }
    temp = start;
    while (ch == 'y')
    {
        printf("\nEnter y to continue or n to stop here :: ");
        scanf(" %c", &ch);
        if (ch == 'y')
        {
            temp->next = (node *)malloc(sizeof(node));
            pre = temp;
            temp = temp->next;
            printf("\nEnter element to the list :: ");
            scanf("%d", &(temp->info));
            temp->prev = pre;
        }
        else
        {
            break;
        }
    }
    temp->next = NULL;
    return start;
}
void traverse(node *start)
{
    node *ptr;
    ptr = start;
    while (ptr != NULL)
    {
        printf("%d\t", (ptr->info));
        ptr = ptr->next;
    }
}
void reverse_traverse(node *start)
{
    node *temp, *ptr;
    temp = start;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    ptr = temp;
    while (ptr != NULL)
    {
        printf("%d\t", (ptr->info));
        ptr = ptr->prev;
    }
}
void incert_after_value(node *start)
{
    node *temp, *new, *ptr;
    int ele;
    temp = start;
    printf("\nEnter the value after which u want to incert the element :: ");
    scanf("%d", &ele);
    while (temp != NULL)
    {
        if (temp->info == ele)
        {
            break;
        }
        else
        {
            temp = temp->next;
        }
    }
    if(temp == NULL)
    {
        
        printf("\nElement not found  .");
        exit(0);
    } 
    new = (node *)malloc(sizeof(node));
    printf("\nEnter the new element :: ");
    scanf("%d", &(new->info));
    ptr = temp->next;
    new->prev = temp;
    temp->next = new;
    new->next = ptr;
    ptr->prev = new;
}
    