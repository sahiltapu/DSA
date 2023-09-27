// Deleting the 1st node //
#include<stdio.h>
#include<stdlib.h>
typedef struct NODE
{
    int info;
    struct NODE *prev,*next;
} node;
node * create(node *);
void traverse(node *);
void reverse_traverse(node *);
node * delet_1st(node *);
int main()
{
    node *START;
    START = NULL;
    START = create(START);
    printf("\nThe elements of the list are :: \n");
    traverse(START);
    START = delet_1st(START);
    printf("\nAfter deleting the 1st element the list is :: \n");
    traverse(START);
    printf("\nReversing the list :: \n");
    reverse_traverse(START);
    return 0;
}
node * create(node *start)
{
    node *temp,*pre;
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
            temp->next = (node *) malloc(sizeof(node));
            pre = temp;
            temp = temp->next;
            printf("\nEnter element to the list :: ");
            scanf("%d",&(temp->info));
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
    while(ptr != NULL)
    {
        printf("%d\t",(ptr->info));
        ptr = ptr->next;
    } 
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
node * delet_1st(node *start)
{
    node * temp;
    temp = start;
    start = start->next;
    start->prev = NULL;
    free(temp);
    return start;
}