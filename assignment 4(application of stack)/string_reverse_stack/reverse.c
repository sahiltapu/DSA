// String reverse //
#include<stdio.h>
#define max 100
void push(char [],char,int *);
char pop(char [],int *);
int main()
{
    char stk[max],str[max],ch;
    int top=-1,i;
    printf("Input the string\n");
    scanf("%[^\n]",str);
    printf("The string before reverse=%s\n",str);
    i=0;
    while(str[i]!='\0')
    {
        push(stk,str[i],&top);
        i++;
    }
    i=0;
    while(top!=-1)
    {
        ch=pop(stk,&top);
        str[i]=ch;
        i++;
    }
    str[i]='\0';
    printf("The string after reverse=%s\n",str);
    return 0;
}
void push(char stk[],char ch,int *top)
{
    if(*top==(max-1))
        printf("stack overflow\n");
    else
    {
        (*top)++;
        stk[*top]=ch;
    }
}
char pop(char stk[],int *top)
{
    char ch;
    if(*top==-1)
        printf("stack underflow\n");
    else
    {
        ch=stk[*top];
        (*top)--;
        return ch;
    }
}