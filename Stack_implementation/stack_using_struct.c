#include <stdio.h>
#include <stdlib.h>
#define maxstk 10
typedef struct STACK
{
    int top;
    int val[maxstk];
} stack;
void push(stack *, int);
int pop(stack *);
void traverse(stack *);
int main()
{
    stack stk;
    int ele, opt, i, pele;
    stk.top = -1;
    while (1)
    {
        printf("\ninput\n1.PUSH\n2.POP\n3.TRAVERSE\n4.EXIT\nYOUR CHOISE >> ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("Enter element to insert :: ");
            scanf("%d", &ele);
            push(&stk, ele);
            break;
        case 2:
            pele = pop(&stk);
            printf("Popped element is :: %d\n", pele);
            break;
        case 3:
            traverse(&stk);
            printf("\n");
            break;
        case 4:
            exit(0);
        default:
            printf("WRONG NUMBER TRY AGAIN");
        }
    }
}

void push(stack *stk, int ele)
{
    if ((*stk).top == maxstk - 1)
    {
        printf("Stack is full.\n");
    }
    else
    {
        (*stk).top++;
        (*stk).val[(*stk).top] = ele;
    }
}
int pop(stack *stk)
{
    int temp;
    if ((*stk).top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        temp = (*stk).val[(*stk).top];
        (*stk).top--;
    }
    return temp;
}
void traverse(stack *stk)
{
    printf("Elements of the stack are :: \n");
    for (int i = (*stk).top; i >= 0; i--)
    {
        printf("%d\t", (*stk).val[i]);
    }
}
