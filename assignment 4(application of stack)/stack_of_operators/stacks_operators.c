// program for postfix evaluation //
#include <stdio.h>
#include <string.h>
#define max 10
void push(int[], int, int *);
int pop(int[], int *);
int main()
{

    char str[max];
    int stk[max], a, b, i, top = -1, opt, ele, len;
    printf("Enter the postfix expression\n");
    scanf("%s", str);
    i = 0;
    len = strlen(str);
    while (i < len)
    {
        opt = 0;
        if (isdigit(str[i]))
        {
            opt = 1;
        }
        else
        {
            opt = 2;
        }
        switch (opt)
        {
        case 1:
            ele = (int)str[i] - (int)'0';
            push(stk, ele, &top);
            break;
        case 2:
            b = pop(stk, &top);
            a = pop(stk, &top);
            printf("%c\n", str[i]);
            if (str[i] == '+')
            {
                ele = a + b;
                push(stk, ele, &top);
            }
            else if (str[i] == '-')
            {
                push(stk, (a - b), &top);
            }
            else if (str[i] == '*')
            {
                push(stk, (a * b), &top);
            }
            else
            {
                push(stk, (a / b), &top);
            }
        }
        i++;
    }
    printf("result of the expression =%d\n", stk[top]);
    return 0;
}
void push(int stk[], int ele, int *t)
{

    if (*t == max - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        (*t)++;
        stk[*t] = ele;
    }
}
int pop(int stk[], int *t)
{
    int ele;
    if (*t == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        ele = stk[*t];
        (*t)--;
        return ele;
    }
}
