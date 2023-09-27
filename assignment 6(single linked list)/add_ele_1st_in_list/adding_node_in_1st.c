// Adding a node at the beginning  //
#include<stdio.h>
#include<stdlib.h>
typedef struct NODE
{
    int info;
    struct NODE * next;
} node;
node * incertat1(node *);
void traverse(node *);
int main()
{
    node *START,*temp;
    char c = 'y';
    START = (node *) malloc(sizeof(node));
    printf("\nEnter element to the list :: ");
    scanf("%d",&(START->info));
    START->next = NULL;
    temp = START;
    while(c == 'y')
    {
        printf("\nEnter y to continue or n to stop :: ");
        scanf(" %c",&c);
        if(c == 'y')
        {
            temp->next = (node*) malloc(sizeof(node));
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
    printf("\nThe list is :: \n");
    traverse(START);
    printf("\n");
    START = incertat1(START);
    printf("\nThe new list is :: \n");
    traverse(START);
    printf("\n");
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
node * incertat1(node * start)
{
    node *new;
    new = (node*) malloc(sizeof(node));
    printf("Enter the new element in the list :: ");  /* The element is added at the beginning */
    scanf("%d",&(new->info));
    new->next = start;
    start = new;

}