// Deleting ith node from the list //
#include<stdio.h>
#include<stdlib.h>
typedef struct NODE
{
    int info;
    struct NODE * next;
} node;
node * create(node *);
void traverse(node *);
void delete(node *);
int count = 0;
int main()
{
    node *START;
    START = NULL;
    START = create(START);
    printf("\nElements of the list are :: \n");
    traverse(START);
    delete(START);
    printf("\nAfter deleting the list is :: ");
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
        count++;
        ptr = ptr->next;
    }
}
void delete(node * start)
{
    node *cur,*prev;
    int i,k;
    printf("\nEnter the node u want to delete the element :: ");
    scanf("%d",&i);
    if(i > count)
    {
        printf("\nThe ith node not present in the list .");
        return;
    }
    cur = start;
    k = 1;
    while(k < i)
    {
        prev = cur;
        cur = cur->next;
        k++;

    }
    prev->next = cur->next;
    free(cur);

}