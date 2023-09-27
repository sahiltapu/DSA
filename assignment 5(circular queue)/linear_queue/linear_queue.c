// Linear queaue //
#include <stdio.h>
#include <stdlib.h>
#define max 10
void enqueue(int [], int*, int*, int);
int dequeue(int [], int*, int*);
void traverse(int [], int, int);
int main()
{
    int Q[max];
    int front = -1, rear = -1, ele, pele;
    int opt;
    while (1)
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
void enqueue(int Q [], int *f, int *r, int e)
{
    if ((*f == -1) && (*r == -1))
    {
        *f = *r = 0;
        Q[*r] = e;
    }
    else if (*r == (max - 1))
    {
        printf("\nQueue is full.\n");
        return;
    }
    else
    {
        (*r)++;
        Q[*r] = e;
    }
}
int dequeue(int Q [], int *f, int *r)
{
    int el;
    if ((*f == -1) && (*r == -1))
    {
        printf("\nNo elements present .\n");
        return;
    }
    else if ((*f) == (*r))
    {
        el = Q[*f];
        *f = *r = -1;
    }
    else
    {
        el = Q[*f];
        (*f)++;
    }
    return el;
}
void traverse(int Q [], int f, int r)
{
    int i;
    printf("\nThe elements of the queue :: \n");
    for (i = f; i <= r; i++)
    {
        printf("%d \t", Q[i]);
    }
}
