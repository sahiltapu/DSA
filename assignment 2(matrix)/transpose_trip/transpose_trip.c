// Finding transpose of a triplete matrix //
#include<stdio.h>
#define row 4
#define col 5
void input_sparse(int [][col]);
void display(int [][col],int,int);
void find_triplet(int [][col],int [][3]);
void dis_trip(int [][3],int,int);
void find_transpose(int [][3],int [][3]);
int count = 0;
int main()
{
    int mat[row][col],triplet[100][3],trans_trip[100][3];
    printf("Enter the elements of the matrix (4X5):: \n");
    input_sparse(mat);
    printf("elements of sparse matrix ::\n");
    display(mat,row,col);
    find_triplet(mat,triplet);
    printf("elements of triplet ::\n");
    dis_trip(triplet,count+1,3);
    printf("transpose of the triplet ::\n");
    find_transpose(triplet,trans_trip);
    dis_trip(trans_trip,count+1,3);
    return 0;
}   
void input_sparse(int m[][col])
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            scanf("%d",&m[i][j]);
            if(m[i][j]!=0)
                count++;
        }
    }
}

void display(int m[][col],int r,int c)
{
    int i,j;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
            printf("%d\t",m[i][j]);
        printf("\n");
    }
}
void find_triplet(int m[][col],int trip[][3])
{
    int i,j,k=1;
    trip[0][0]=row;
    trip[0][1]=col;
    trip[0][2]=count;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            if(m[i][j]!=0)
            {
                trip[k][0]=i;
                trip[k][1]=j;
                trip[k][2]=m[i][j];
                k++;
            }
        }
    }
}
void dis_trip(int trip[][3],int r,int c)
{
    int i,j;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
            printf("%d\t",trip[i][j]);
        printf("\n");
    }
}

void find_transpose(int trip[][3],int trans_trip[][3])
{

    int i,j,k=1;
    trans_trip[0][0]=col;
    trans_trip[0][1]=row;
    trans_trip[0][2]=count;

    for(i=0; i<col; i++)
    {
        for(j=1; j<=count; j++)
        {
            if(trip[j][1] == i)
            {
                trans_trip[k][0] = trip[j][1];
                trans_trip[k][1] = trip[j][0];
                trans_trip[k][2] = trip[j][2];
                k++;
            }

        }
    }
}