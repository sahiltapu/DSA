// Adding element after a perticular value //
#include <stdio.h>
#include <stdlib.h>
typedef struct NODE
{
    int info;
    struct NODE *next;
} node;
void incert_after_value(node *);
void traverse(node *);
int main()
{
    node *START, *temp;
    char ch = 'y';
    START = (node *)malloc(sizeof(node));
    printf("\nEnter the 1st node :: ");
    scanf("%d", &(START->info));
    START->next = NULL;
    temp = START;
    while (ch == 'y')
    {
        printf("\nEnter y to continue or enter n to end here :: ");
        scanf(" %c", &ch);
        if (ch == 'y')
        {
            temp->next = (node *)malloc(sizeof(node));
            temp = temp->next;
            printf("\nEnter next element :: ");
            scanf("%d", &(temp->info));
        }
        else
        {
            break;
        }
    }
    temp->next = NULL;
    traverse(START);
    incert_after_value(START);
    traverse(START);
    return 0;
}
void traverse(node *start)
{
    node *ptr;
    ptr = start;
    printf("\nThe list is ::\n");
    while(ptr != NULL)
    {
        printf("%d\t",(ptr->info));
        ptr = ptr->next;
    }
    printf("\n");
}
void incert_after_value(node *start)
{
    node *new,*temp;
    int i;
    printf("\nEnter the value after which u want to incert the node :: ");
    scanf("%d",&i);
    temp = start;
    while(temp != NULL)
    {
        if(temp->info == i)
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
        printf("\nThe element is not present in the list.\n");
        return;
    }
    else
    {
        new = (node *) malloc(sizeof(node));
        printf("\nEnter the value :: ");
        scanf("%d",&(new->info));
        new->next = temp->next;
        temp->next = new;
    }

}

