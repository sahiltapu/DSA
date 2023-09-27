/*  C Program to convert decimal to binary using stack  */

#include<stdio.h>
#define MAX 50

void push(int , int*, int []);
int pop(int* , int []);
void binary(int);

int main()
{
        int num;
        printf("Enter an integer : ");
        scanf("%d",&num);
        printf("Binary Equivalent is : ");
        binary(num);

        return 0;

}
void binary(int num)
{
        int stack[MAX], top=-1, rem;
        while(num!=0)
        {
                rem = num%2;
                push(rem, &top, stack);
                num/=2;
        }
        while(top!=-1)
                printf("%d", pop(&top, stack));
        printf("\n");
}
void push(int x, int *top, int stack_arr[])
{
        if(*top == (MAX-1))
                printf("Stack is Full\n");
        else
        {
                *top=*top+1;
                stack_arr[*top] = x;
        }
}

int pop(int *top, int stack_arr[])
{
        int x;
        if(*top == -1)
        {
                printf("Stack is Empty\n");
                return;
        }
        else
        {
                x = stack_arr[*top];
                *top=*top-1;
        }
        return x;
}
