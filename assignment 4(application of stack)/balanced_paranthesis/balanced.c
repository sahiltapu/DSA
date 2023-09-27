//Program to check for  balanced palenthesis // 

#include <stdio.h>
#define MAXSTK 10

void push(char [], char , int *);
void pop(char [], int *);

int main()
{

    char stk[MAXSTK],str[20];
    int i , top = -1;

    printf("Enter A String : ");
    scanf("%[^\n]",str);

    for(i=0;str[i]!='\0';i++)
    {
        if(str[i] == '(')
        {

            push(stk,str[i],&top);
        }

        else if(str[i] == ')')
        {

            pop(stk,&top);
        }

    }

    if(top == -1)
    {

        printf("The Expression is palenthesis balanced");
    }
    else
    {
        printf("The Expression is not palenthesis balanced");
    }
    return 0;
}


void push(char stk[],char ch, int *t)
{

    if(*t == MAXSTK)
        printf("Stack Overflow");
    else
    {

        (*t)++;
        stk[*t]=ch;
    }
}

void pop(char stk[],int *t)
{


    if(*t == -1)
        printf("Stack Underflow");
    else
    {
        (*t)--;
    }
}