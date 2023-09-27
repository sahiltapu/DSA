// Implementation of merge-sort //
#include <stdio.h>
#include <stdlib.h>
#define size 5
void input(int[]);
void display(int[]);
void merge_sort(int[], int, int);
void merge(int[], int, int, int);
int main()
{
    int A[size];
    int p, r;
    printf("\nEnter %d elements in the array :: \n", size);
    input(A);
    p = 0;
    r = size - 1;
    printf("\nElements are :: \n");
    display(A);
    merge_sort(A, p, r);
    printf("\nElements after sorting :: \n");
    display(A);
    return 0;
}
void input(int A[])
{
    int i;
    for (i = 0; i < size; i++)
    {
        scanf("%d", &A[i]);
    }
}
void display(int A[])
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d\t", A[i]);
    }
    printf("\n");
}
void merge_sort(int A[], int p, int r)
{
    int q;
    if (p < r)
    {
        q = (p + r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}
int B[size];
void merge(int A[], int p, int q, int r)
{
    
    int l1, r1, i;
    i = p;
    l1 = p;
    r1 = q + 1;
    while ((l1 <= q) && (r1 <= r))
    {
        if (A[l1] <= A[r1])
        {
            B[i] = A[l1];
            l1 = l1 + 1;
            i++;
        }
        else
        {
            B[i] = A[r1];
            r1 = r1 + 1;
            i++;
        }
    }
    while (l1 <= q)
    {
        B[i] = A[l1];
        l1 = l1 + 1;
        i++;
    }
    while (r1 <= r)
    {
        B[i] = A[r1];
        r1 = r1 + 1;
        i++;
    }
    for (i = p; i <= r; i++)
    {
        A[i] = B[i];
    }
}

