//implementation of STACK using Structure //
#include<stdio.h>
#include<stdlib.h>
#define maxstk 10
typedef struct S
{
    int top;
    int val[maxstk];
}stack;
void push(stack *,int );
int pop(stack *);
void traverse(stack *);
int main()
{
    stack stk;
    int ele,opt,i;
    stk.top = -1;
    while(1)
    {
        printf("\ninput\n 1.push()\n 2.pop()\n 3.traverse()\n 4.exit()\n");
        scanf("%d",&opt);
        switch(opt)
        {
        case 1:
            printf("insert element to stack :\n");
            scanf("%d",&ele);
            push(&stk,ele);
            break;
        case 2:
            ele=pop(&stk);
            printf("the poped element is %d\n",ele);
            break;
        case 3:
            traverse(&stk);
            printf("\n");
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong Operation\n");
        }
    }
    return 0;
}
void push(stack *stk, int ele )
{
    if((*stk).top==maxstk-1)
        printf("stack is full\n no elements can be inserted\n");
    else
    {
        (*stk).top++;
        (*stk).val[(*stk).top]=ele;
    }
}
int pop(stack *stk)
{
    int temp;
    if((*stk).top == -1)
        printf("the stack is empty\n");
    else
    {
        temp=(*stk).val[(*stk).top];
        (*stk).top--;
    }
    return temp;
}
void traverse(stack *stk)
{
    int i;
    printf("\nthe element of stack\n");
    for(i=(*stk).top; i>=0; i--)
        printf("%d\t",(*stk).val[i]);

}
  
   