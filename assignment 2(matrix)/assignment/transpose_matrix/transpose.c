// Transpose of a matrix //
#include<stdio.h>
#define row 4
#define col 5
void Input(int [][col]);
void display(int [][col]);
void transpose(int [][col],int [][row]);
int main()
{
    int MAT[row][col],TRA[col][row];
    Input(MAT);
    display(MAT);
    transpose(MAT,TRA);
    return 0;
}
void Input(int MAT[][col])
{
    int i,j;
    printf("Input the element\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            
            scanf("%d",&MAT[i][j]);
        }
    }
}
void display(int MAT[][col])
{
    int i,j;
    printf("The elements of the matrix\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d\t",MAT[i][j]);
        }
        printf("\n");
    }
}
void transpose(int MAT[][col], int TRA[][row])
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            TRA[j][i]=MAT[i][j];
        }
    }
    int k,l;
    printf("The elements of the transpose matrix\n");
    for(k=0;k<col;k++)
    {
        for(l=0;l<row;l++)
        {
            printf("%d\t",TRA[k][l]);
        }
        printf("\n");
    }
}