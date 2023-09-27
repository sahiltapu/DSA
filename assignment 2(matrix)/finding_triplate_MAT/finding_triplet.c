// Finding the triplete of a sparse matrix //
#include<stdio.h>
#define row 5
#define col 4
void input(int [][col]);
void display(int [][col],int ,int);
void display1(int [][3],int ,int);
void find_trip(int [][col],int [][3]);
int count = 0;
int main()
{
    int sparse [row][col],trip[100][3];
    input(sparse);
    display(sparse,row,col);
    find_trip(sparse,trip);
    display1(trip,count+1,3);
    return 0;
}
void input(int sparse[][col])
{
    int i,j;
    printf("Enter a 5X4 sparse matrix :: \n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            scanf("%d",&sparse[i][j]);
            if(sparse[i][j]!=0)
                 count=count+1;
        }
    }
}
void display(int sparse[][col],int r,int c)
{
     int i,j;
     printf("The elements of the matrix is :: \n");
     for(i=0;i<r;i++)
     {
          for(j=0;j<c;j++)
          {
              printf("%d \t",sparse[i][j]);
          }
          printf("\n");
     }
}
void find_trip(int sparse[][col],int trip[][3])
{
    int i,j,k=1;
    trip[0][0]=row;
    trip[0][1]=col;
    trip[0][2]=count;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(sparse[i][j]!=0)
            {
                trip[k][0]=i;
                trip[k][1]=j;
                trip[k][2]=sparse[i][j];
                k++;

            }
        }
    }
}
void display1(int trip[][3],int r,int c)
{
    int i,j;
    printf("Elements of the triplet matrix are :: \n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d \t",trip[i][j]);
        }
        printf("\n");
    }
}