// Reversing the elements of the list //
#include<stdio.h>
#include<stdlib.h>
#define max 100
typedef struct NODE
{
    int info;
    struct NODE * next;
} node;
node * create(node *);
void traverse(node *);
int reverse(node *);
void reverse_push(int [] ,int *,int );
int reverse_pop(int [] ,int *);
int count = 0;
int main()
{
    node *START;
    START = NULL;
    START = create(START);
    printf("\nElements of the list are :: \n");
    traverse(START);
    printf("\nAfter reversing the elements of the list :: \n");
    reverse(START);
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
int reverse(node *start)
{
    node *ptr;
    int A[max],B[max];
    int top = -1,ele;
    ptr = start;
    while(ptr != NULL)
    {
       reverse_push(A,&top,ptr->info);
       ptr = ptr->next;
    }
    int i = 0;
    while(top != -1)
    {
       ele = reverse_pop(A,&top);
       B[i] = ele;
       i++;
    }
    for(i = 0 ; i < count ; i++)
    {
        printf("%d\t",B[i]);
    }
    printf("\n");
    return;
}
void reverse_push(int A[],int *t,int ele)
{
    if((*t) == (max - 1))
    {
        return
        printf("\nThe list is full \n");
    }
    else
    {
        (*t)++;
        A[(*t)] = ele;
    }
}
int reverse_pop(int A[],int *t)
{
   int ele;
   if((*t) == -1)
   {
       return
       printf("\nThe list is empty.\n");
   }
   else
   {
       ele = A[(*t)];
       (*t)--;
   }
   return ele;
}