// Adding element after ith location in a double linked list //
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
void add_after_ith(node *);
int count = 0;
int main()
{
    node *START;
    START = NULL;
    START = create(START);
    printf("\nElements of the list are :: \n");
    traverse(START);
    add_after_ith(START);
    printf("\nAfter adding the element the list is :: \n");
    traverse(START);
    printf("\nAfter reversing the elements the list is :: \n");
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
void add_after_ith(node *start)
{
    node *new, *temp, *ptr;
    int i, k = 1;
    printf("\nEnter the place after which the element will be added :: ");
    scanf("%d", &i);
    if ((i < 1) || (i > count))
    {
        printf("\nYou have entered a wrong wrong option \n");
        exit(0);
    }
    else
    {
        k = 1;
        temp = start;
        while (k != i)
        {
            temp = temp->next;
            k++;
        }
        ptr = temp->next;
        new = (node *)malloc(sizeof(node));
        printf("\nEnter the element :: ");
        scanf("%d", &(new->info));
        new->prev = temp;
        temp->next = new;
        new->next = ptr;
        ptr->prev = new;
    }
}