// Deleting last node of the list //
#include<stdio.h>
#include<stdlib.h>
typedef struct NODE
{
    int info;
    struct NODE * next;
} node;
node * create(node *);
void traverse(node *);
node * delete_last(node *);
int count = 0;
int main()
{
    node *START;
    START = NULL;
    START = create(START);
    printf("\nThe list is :: \n");
    traverse(START);
    printf("\nAfter deleting the last element the list is :: \n");
    START = delete_last(START);
    traverse(START);
    return 0;
}
node * create(node * start)
{
    node *temp;
    char ch = 'y';
    if(start == NULL)
    {
        start = (node *) malloc(sizeof(node));
        printf("\nEnter the value of 1st node :: ");
        count++;
        scanf("%d",&(start->info));
    }
    temp = start;
    while(ch == 'y')
    {
        printf("\nEnter y to continue or n to end the list here :: ");
        scanf(" %c",&ch);
        if(ch == 'y')
        {
            temp->next = (node *) malloc(sizeof(node));
            temp = temp->next;
            printf("\nEnter element into the list :: ");
            count++;
            scanf("%d",&(temp->info));
        }
        else
        {
            break;
        }
    }
    temp->next = NULL;
    return start;
}
void traverse(node * start)
{
    node *ptr;
    ptr = start;
    while(ptr != NULL)
    {
        printf("%d\t",(ptr->info));
        ptr = ptr->next;
    }
}
node * delete_last(node * start)
{
   node *ptr;
   ptr = start;
   int i;
   for(i = 1 ; i < count - 1 ; i++)
    {
       ptr = ptr->next;
    }
    ptr->next = NULL;
    return start;
}