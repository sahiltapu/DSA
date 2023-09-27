// Incertion shot //
#include<stdio.h>
void incertionshot(int[], int);
void printarray(int[], int);
int main()
{
    int arr[20];
    int s,i;
    printf("Enter the size of array :: ");         // Entring size 
    scanf("%d",&s);
    printf("Enter the elements of array :: \n ");   // Entring elements
    for(i=0;i<s;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\n Before shoting the array is :: \n");
    for(i=0;i<s;i++)
    {
        printf("%d \t",arr[i]);
    }
    incertionshot(arr,s);
    printf("\n After shoting the new array is :: \n");
    printarray(arr,s);
    return 0;
}
void incertionshot(int arr[], int s)      // Shorting process 
{
    int i,key,j;
    for(i=0;i<s;i++)
   {
        key=arr[i];
        j=i-1;
    
      while(j>=0 && arr[i]>key)
        {
         arr[j+1]=arr[j];
         j=j-1;
        }
         arr[j+1]=key;
    }
    

}
void printarray(int arr[], int s)       // Printing array
{
    int i;
    for(i=0;i<s;i++)
    {
        printf("%d \t",arr[i]);

    }
}
