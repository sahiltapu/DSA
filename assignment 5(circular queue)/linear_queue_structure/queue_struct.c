// implementation of queue using structure //
#include <stdio.h>
#include <stdlib.h>
#define max 10
typedef struct s
{
    int front, rear;
    int Q[max];
} queue;
void Enqueue(queue *, int);
int Dequeue(queue *);
void traverse(queue *);
int main()
{
    queue q;
    int ele,pele,opt;
    q.front = -1;
    q.rear = -1;
    while (1)
    {
        printf("\ninput\n1.Enqueue()\n2.Dequeue()\n3.Traverse()\n4.Exit()\nyour choise :: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("Incert element  into the queue :: \n");
            scanf("%d", &ele);
            Enqueue(&q,ele);
            break;
        case 2:
            pele = Dequeue(&q);
            printf("The popped element is ::\n%d", pele);
            break;
        case 3:
            traverse(&q);
            break;
        case 4:
            exit(0);
        default:
            printf("There is no option to  be executed .\n");
        }
    }
    return 0;
}
void Enqueue(queue *q,int e)
{
    if(((*q).front == -1) && ((*q).rear == -1))
    {
        (*q).front = (*q).rear = 0;
        (*q).Q[(*q).rear] = e;
    }
    else if((*q).rear == max - 1)
    {
        return 
        printf("\nQueure is full.\n");
    }
    else
    {
        (*q).rear++;
        (*q).Q[(*q).rear] = e;
    }
}
int Dequeue(queue *q)
{
    int ele;
    if(((*q).front == -1) && ((*q).rear == -1))
    {
        return
        printf("\nNo elements present.\n");
    }
    else if((*q).front == (*q).rear)
    {
        ele = (*q).Q[(*q).front];
        (*q).front = (*q).rear = -1;
    }
    else
    {
        ele = (*q).Q[(*q).front];
        (*q).front++;
    }
    return ele;
}
void traverse(queue *q)
{
    int i;
    printf("\nThe elements of the queue  are :: \n");
    for(i = (*q).front; i <= (*q).rear; i++)
    {
        printf("%d \t",(*q).Q[i]);
    }
}

