// sorting the list //
#include <stdio.h>
#include <stdlib.h>
typedef struct NODE
{
    int info;
    struct NODE *next;
} node;
node *create(node *);
void traverse(node *);
void sort(node *);
int main()
{
    node *START;
    START = NULL;
    START = create(START);
    printf("\nYour list is :: \n");
    traverse(START);
    sort(START);
    printf("\nAfter sorting your list is :: \n");
    traverse(START);
    return 0;
}
node *create(node *start)
{
    node *temp;
    char ch = 'y';
    if (start == NULL)
    {
        start = (node *)malloc(sizeof(node));
        printf("\nEnter the 1st element to the node :: ");
        scanf("%d", &(start->info));
    }
    temp = start;
    while (ch == 'y')
    {
        printf("\nEnter y to continue or n to end the list here :: ");
        scanf(" %c", &ch);
        if (ch == 'y')
        {
            temp->next = (node *)malloc(sizeof(node));
            temp = temp->next;
            printf("\nEnter element into the list :: ");
            scanf("%d", &(temp->info));
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
void sort(node *start)
{
    int min;
    node *curnt,*nextpt,*minpt;
    curnt=start;
    while(curnt->next!=NULL)
    {
        min=curnt->info;
        minpt=curnt;
        nextpt=curnt->next;
        while(nextpt!=NULL)
        {
            if(nextpt->info<min)
            {
                min=nextpt->info;
                minpt=nextpt;
            }
            nextpt=nextpt->next;
        }
        if(min!=curnt->info)
        {
            minpt->info=curnt->info;
            curnt->info=min;
        }
        curnt=curnt->next;
    }
}