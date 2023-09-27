// Implementation of Quick Sort //
#include<stdio.h>
#define size 5
void Input(int []);
void Display(int []);
void quicksort(int [],int,int);
int partition(int [],int,int);
int main()
{
    int A[size],p,r;
    Input(A);
    Display(A);
    p = 0;
    r = size - 1;
    quicksort(A,p,r);
    Display(A);
    return 0;
}
void Input (int A[])
{
    int i;
    printf("Enter %d element :: ",size);
    for(i = 0 ; i < size ; i++)
    {
        scanf("%d",&A[i]);
    }
}
void Display (int A[])
{
    int i;
    printf("The elements of the array is :: \n");
    for(i = 0 ; i < size ; i++)
    {
        printf("%d\t",A[i]);
    }
    printf("\n");
}
void quicksort(int A[],int p,int r)
{
    int q;
    if (p < r)
    {
        q = partition(A,p,r);
        quicksort(A,p,q-1);
        quicksort(A,q+1,r);
    }
}
int partition(int A[],int p,int r)
{
    int i, j, pivot,temp;
    pivot = A[r];
    i = p - 1;
    j = p;
    while(j <= r - 1)
    {
        if(A[j] <= pivot)
        {
            i++;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
        j++;
    }
    temp = A[r];
    A[r] = A[i + 1];
    A[i + 1] = temp;
    return(i + 1);
}