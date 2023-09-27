// Adding element at 1st of a double linked list //
#include <stdio.h>
#include <stdlib.h>
typedef struct NODE
{
    int info;
    struct NODE *prev, *next;
} node;
node *create(node *);
void traverse(node *);
void reverse_traverse(node *);
node *add_at_1st(node *);
int main()
{
    node *START;
    START = NULL;
    START = create(START);
    printf("\nElements of the list are :: \n");
    traverse(START);
    START = add_at_1st(START);
    printf("\nAfter adding element at 1st the list is :: \n");
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
node *add_at_1st(node *start)
{
    node *new, *n;
    new = (node *)malloc(sizeof(node));
    printf("\nEnter the element which will be added at 1st place :: ");
    scanf("%d", &(new->info));
    new->prev = NULL;
    new->next = start;
    start->prev = new;
    start = new;
    return start;
}
void reverse_traverse(node * start)
{
    node *temp,*ptr;
    temp = start;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    ptr = temp;
    while(ptr != NULL)
    {
        printf("%d\t",(ptr->info));
        ptr = ptr->prev;
    }
}