// Deleting ith node (except 1st and last node)//
#include <stdio.h>
#include <stdlib.h>
typedef struct NODE
{
    int info;
    struct node *next, *prev;
} node;
node *create(node *);
void traverse(node *);
void reverse_traverse(node *);
void delete_ith(node *);
int count = 0;
int main()
{
    node *START;
    START = NULL;
    START = create(START);
    printf("\nElements of the list are :: \n");
    traverse(START);
    delete_ith(START);
    printf("\nAfter deleting the node the list is :: \n");
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
        count++;
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
            count++;
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
void delete_ith(node *start)
{
    node *temp, *ptr, *ptr1;
    int n, k = 1;
    temp = start;
    printf("\nEnter the node you want to delete :: ");
    scanf("%d", &n);
    if ((n < 1) || (n > count))
    {
        printf("\nThe node is not present in the list.");
        exit(0);
    }
    else
    {
        for (k = 1; k < n; k++)
        {
            temp = temp->next;
        }
        ptr = temp->next;
        ptr1 = temp->prev;
        ptr1->next = ptr;
        ptr->prev = ptr1;
        free(temp);
    }
}