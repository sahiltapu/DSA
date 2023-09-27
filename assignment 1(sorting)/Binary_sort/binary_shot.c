// binary sort //
#include<stdio.h>
#define SIZE 10
void Input(int []);
void display(int []);
void sort(int[]);
int binary(int [],int);
int main()
{
    int Arr[SIZE],ele,flag=0;
    Input(Arr);
    display(Arr);
    printf("Enter the element to be searched:");
    scanf("%d",&ele);
    sort(Arr);
    flag=binary(Arr,ele);
    if(flag==1)
        printf("The element is present");
    else
        printf("The element is absent");
    return 0;
}
void Input(int Arr[])
{
    int i;
    for(i=0;i<SIZE;i++)
    {
        printf("Enter the element into the array:\n");
        scanf("%d",&Arr[i]);
    }
}
void display(int Arr[])
{
    int i;
    printf("The element in the array\n");
    for(i=0;i<SIZE;i++)
        printf("%d\t",Arr[i]);
    printf("\n");
}
void sort(int Arr[])
{
    int i,j,min,loc;
    for(i=0;i<SIZE;i++)
    {
        min=Arr[i];
        loc=i;
        for(j=i+1;j<SIZE;j++)
        {
            if(Arr[j]<min)
            {
                min=Arr[j];
                loc=j;
            }
            Arr[loc]=Arr[i];
            Arr[i]=min;
        }
    }
}
int binary(int Arr[],int ele)
{
    int beg,mid,end,pos=-1;
    beg=0;
    end=SIZE-1;
    while(beg<=end)
    {
        mid=(beg+end)/2;
        if(Arr[mid]==ele)
        {
            pos=mid;
            break;
        }
        else if(ele>Arr[mid])
        {
            beg=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    if(pos>=0)
        return 1;
    else
        return 0;
}