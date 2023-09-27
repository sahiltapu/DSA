// Searching an element //
#include <stdio.h>
#include <stdlib.h>
typedef struct NODE
{
    int info;
    struct NODE *next, *prev;
} node;
node * create(node *);
void traverse(node *);
void search(node *,int );
int main()
{
    node *START = NULL;
    int ele;
    START = create(START);
    printf("\nElements of the list are :: \n");
    traverse(START);
    printf("\nEnter the element u want to search :: ");
    scanf("%d",&ele);
    search(START,ele);
    return 0;
}
node *create(node *start)
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
void search(node * start,int ele)
{
    node *temp;
    temp = start;
    while(temp != NULL)
    {
        if(temp->info == ele)
        {
            printf("\nThe element is present in the list . \n");
            exit(0);
        }
        else
        {
            temp = temp->next;
        }
    }
    if(temp == NULL)
    {
        printf("\nElement not found.\n");
        exit(0);
    }
}