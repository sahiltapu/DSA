//Wap to represent a polynomial of single variable//

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coef, pow;
    struct Node *next;
};
typedef struct Node node;
node *create(node *);
void traverse(node *);
int main()
{
    node *start = NULL;
    start = create(start);
    traverse(start);
    return 0;
}
node *create(node *S)
{
    node *temp;
    if (S == NULL)
    {
        S = (node *)malloc(sizeof(node));
        printf("Enter coefficient and power of the variable :");
        scanf("%d %d", &(S->coef), &(S->pow));
        S->next = NULL;
    }
    temp = S;
    char ch = 'Y';
    while (ch == 'Y')
    {
        temp->next = (node *)malloc(sizeof(node));
        temp = temp->next;
        printf("Enter coefficient and power of the variable :");
        scanf("%d %d", &(temp->coef), &(temp->pow));
        printf("Enter Y to continue :\n");
        scanf(" %c", &ch);
        break;
    }
    temp->next = NULL;
    return S;
}
void traverse(node *S)
{
    printf("%dx^%d ", S->coef, S->pow);
    S = S->next;
    while (S != NULL)
    {
        printf("+ %dx^%d", S->coef, S->pow);
        S = S->next;
    }
    printf("\n");
}