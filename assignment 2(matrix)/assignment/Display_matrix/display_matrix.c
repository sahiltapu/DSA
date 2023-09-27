// Displaying the Matrix //
#include<stdio.h>
#define row 4
#define col 5
void input(int[][col]);
void display(int[][col]);
int main()
{
    int M[row][col];
    input(M);
    display(M);
    return 0;
}
void input(int M[][col])
{
    int i,j;
    printf("\n Enter the elements of the matrix(4 x 5) :: \n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            scanf("%d",&M[i][j]);
        }
    }
}
void display(int M[][col])
{
    
    int i,j;
    printf("\n The elements of the matrix are ::  \n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
           printf("%d \t",M[i][j]);
        }
        printf("\n");
    }

}