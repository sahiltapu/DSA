// searching element in the link list //
#include <stdio.h>
#include <stdlib.h>
typedef struct NODE
{
    int info;
    struct NODE * next;
} node;
void search(node *);
void traverse(node *);
int main()
{
    node *START, *temp;
    char ch = 'y';
    START = (node *) malloc(sizeof(node));
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
            temp->next = (node *) malloc(sizeof(node));
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
    search(START);
    return 0;
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
void search(node *start)
{
    node *temp;
    int i;
    temp = start;
    printf("\nEnter the element u want to search :: ");
    scanf("%d",&i);
    while(temp != NULL)
    {
        if(temp->info == i)
        {
            printf("\nElement is present.");
            break;
        }
        else
        {
            temp = temp->next;
        }
    }
    if(temp == NULL)
    {
        printf("\nElement is not present.\n");
    }
}