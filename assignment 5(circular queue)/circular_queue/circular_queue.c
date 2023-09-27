// Implementation of circular queue //
#include<stdio.h>
#include<stdlib.h>
#define max 4
void enqueue(int [],int *,int *,int);
int dequeue(int [],int *,int *);
void traverse(int [],int ,int );
int main()
{
    int Q[max];
    int front  = -1,rear = -1,ele,pele;
    int opt;
    while(1)
    {
        printf("\ninput\n1.Enqueue()\n2.Dequeue()\n3.Traverse()\n4.Exit()\nyour choise :: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("Incert element  into the queue :: \n");
            scanf("%d", &ele);
            enqueue(Q, &front, &rear, ele);
            break;
        case 2:
            pele = dequeue(Q, &front, &rear);
            printf("The popped element is ::\n%d", pele);
            break;
        case 3:
            traverse(Q, front, rear);
            break;
        case 4:
            exit(0);
        default :
            printf("There is no option to  be executed .\n");
        }
    }
    return 0;
}
void enqueue(int Q[],int *f,int *r,int e)
{
    if((*f == -1) && (*r == -1))
    {
        *f = *r = 0;
        Q[*r] = e;
    }
    else if((*f == 0) && (*r == max - 1) || (*f) == ((*r) + 1))
    {
        return
        printf("\nQueue is full .\n");
    }
    else
    {
        *r = (((*r) + 1) % max);
        Q[*r] = e;
    }
}
int dequeue(int Q[],int *f,int *r)
{
    int ele;
    if((*f == -1) && (*r == -1))
    {
        printf("\nThe queue is empty .\n");
    }
    else if(*f == *r)
    {
        ele = Q[*f];
        *f = *r = -1;
    }
    else
    {
        ele = Q[*f];
        *f = (((*f) + 1) % max);
    }
    return ele;
}
void traverse(int Q[],int f,int r)
{
   int i;
   printf("\nThe elements of the circular queue :: \n");
   if(f <= r)
    {
        for(i = f ; i <= r ; i++)
           {
              printf("%d\t",Q[i]);
           }
    }
    else
    {
        for(i = f ; i < max ; i++)
            printf("%d\t",Q[i]);
        for(i = 0 ; i <= r ; i++)
            printf("%d\t",Q[i]);
    }
   
}