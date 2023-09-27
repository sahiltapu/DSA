// Merging 2 lists //
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *next;
};
typedef struct Node node;

node *input(node *);
node *merge(node *, node *);
void traverse(node *);

int count = 0;

int main()
{
    node *startA = NULL;
    node *startB = NULL;
    node *startC = NULL;

    startA = input(startA);
    traverse(startA);
    startB = input(startB);
    traverse(startB);
    printf("After merging :\n");
    startC = merge(startA, startB);
    traverse(startC);
    return 0;
}
node *input(node *S)
{
    node *temp;
    if (S == NULL)
    {
        S = (node *)malloc(sizeof(node));
        printf("Enter data to first node:");
        scanf("%d", &(S->info));
        count++;
    }
    temp = S;
    char ch = 'Y';
    while (ch == 'Y' || ch == 'y')
    {
        temp->next = (node *)malloc(sizeof(node));
        temp = temp->next;
        printf("\nEnter data to New Node:");
        scanf("%d", &(temp->info));
        count++;
        printf("\nEnter 'Y' to continue or Press 'N' to stop:");
        scanf(" %c", &ch);
    }
    temp->next = NULL;
    return S;
}
void traverse(node *start)
{
    node *ptr;
    ptr = start;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->info);
        ptr = ptr->next;
    }
    printf("\n");
}

node *merge(node *A, node *B)
{
    node *C, *temp;
    temp = A;
    C = temp;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = B;

    return C;
}