// ADDING ELEMENT AFTER ITH NODE //
#include <stdio.h>
#include <stdlib.h>
typedef struct NODE
{
    int info;
    struct NODE *next;
} node;
int count = 0;
void add_after_ith(node *);
void traverse(node *);
int main()
{
    node *START, *temp;
    char ch = 'y';
    START = (node *)malloc(sizeof(node));
    printf("\nEnter the element in the list :: ");
    scanf("%d", &(START->info));
    START->next = NULL;
    temp = START;
    while (ch == 'y')
    {
        printf("\nEnter y to continue or enter n to stop the list here :: ");
        scanf(" %c", &ch);
        if (ch == 'y')
        {
            temp->next = (node *)malloc(sizeof(node));
            temp = temp->next;
            printf("\nEnter the next node :: ");
            scanf("%d", &(temp->info));
        }
        else
        {
            break;
        }
    }
    temp->next = NULL;
    printf("\nYour list is :: \n");
    traverse(START);
    add_after_ith(START);
    return 0;
}
void traverse(node *start)
{
    node *ptr;
    ptr = start;
    while (ptr != NULL)
    {
        printf("%d\t", (ptr->info));
        count++;
        ptr = ptr->next;
    }
}
void add_after_ith(node *start)
{
    node *p, *new;
    int i, k = 1;
    printf("\nEnter the ith node after which u want to incert the node :: ");
    scanf("%d", &i);
    if ((i < 1) || (i > count))
    {
        printf("\nYou have entered a node which is not present.");
        
    }
    else
    {
        p = start;
        while (k < i)
        {
            p = p->next;
            k++;
        }
        new = (node *)malloc(sizeof(node));
        printf("\nEnter the value of the node :: ");
        scanf("%d", &(new->info));
        new->next = p->next;
        p->next = new;
        printf("\nYour list is :: \n");
        traverse(start);

        
    }
}