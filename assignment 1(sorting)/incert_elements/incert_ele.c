// Incerting element at ith location //
#include<stdio.h>
#define size 10
void input(int []);
void display(int []);
void delete(int [], int, int);
int main()
{
    int ele,loc;
    int ar[size];
    printf("\n Enter 10 elements in the arry :: \n");  
    input(ar);
    display(ar);
    printf("\n Enter the place you want to delete :: ");
    scanf("%d",&loc);
    printf("\n Enter the element you want to replace :: ");
    scanf("%d",&ele);
    delete(ar, loc, ele);
    display(ar);
    return 0;

}
void input(int ar[])   // Inputing array 
{
    int i;
    for(i=0;i<size;i++)
    {
        scanf("%d",&ar[i]);
    }
}
void display(int ar[])    //  display process 
{
    int i;
    printf("\n Array is ::\n");
    for(i=0;i<size;i++)
    {
        printf("%d \t",ar[i]);

    }
    printf("\n");
}
void delete(int ar[], int loc, int ele)      // Incerting process 
{
    int i,j;
    j=loc;
    for(i=0;i<size;i++)
    {
        if(i==j-1)
        {
            ar[i]=ele;
        } 
    }

}