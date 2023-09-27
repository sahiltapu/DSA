//Addition of Matrix //
#include<stdio.h>
void input(int [][100],int [][100]);
int check(int [][100],int[][100],int ,int ,int ,int );
void display1(int [][100],int [][100],int ,int ,int ,int );
void add(int [][100],int [][100],int ,int );
void display2(int [][100],int ,int);
int main()
{
    int A[100][100],B[100][100];
    input(A ,B );
    return 0;
}
void input(int A[][100],int B[][100])
{
    int r1,r2,c1,c2,i,j;
    printf("Enter the rows & columns of 1st matrix :: ");
    scanf("%d%d",&r1,&c1);
    printf("Enter the elements of matrix 1 :: \n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    printf("Enter the row & columns of 2nd matrix :: ");
    scanf("%d%d",&r2,&c2);
    printf("Enter the elements of matrix 2 :: \n");
    for(i=0;i<r2;i++)
   {
       for(j=0;j<c2;j++)
       {
           scanf("%d",&B[i][j]);
       }
   } 
   display1( A, B, r1, c1, r2, c2);
}
void display1(int A[][100],int B[][100],int r1,int c1,int r2,int c2)
{
    int i,j ;
    printf("ELements of 1st matrix are :: \n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            printf("%d \t",A[i][j]);
        }
        printf("\n");
    }
    printf("Elements of 2nd matrix are :: \n");
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            printf("%d \t",B[i][j]);
        }
        printf("\n");
    }
    check(A,B,r1 ,c1 ,r2 ,c2);
}
int check(int A[][100],int B[][100],int r1,int c1,int r2,int c2)
{
    if(r1==r2 && c1==c2)
    {
        add(A,B,r1,c1);
    }
    else
    {
       printf("Addition will not takes place.");
    }
}
void add(int A[][100],int B[][100],int r1,int c1)
{
    int SUM[100][100];
    int z,j;
    int r=0,c=0;
    r=r1;
    c=c1;
    for(z=0;z<r1;z++)
    {
        for(j=0;j<c1;j++)
        {
            SUM[z][j] = A[z][j] + B[z][j];
        }
    }
    display2(SUM,r,c);
}
void display2(int sum[][100],int r,int c)
{
    int i,j;
    printf("After adding the new matrix is :: \n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
           printf("%d \t",sum[i][j]);
        }
        printf("\n");
    }
}
