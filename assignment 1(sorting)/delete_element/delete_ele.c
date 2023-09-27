// Deletimg element from ith place // 
#include<stdio.h>
int main()
{
    int ar[20],c[20];
    int s,i,j,d,loc;
    printf("Enter the size of array :: ");      // Entering size
    scanf("%d",&s);
    printf("\n Enter the elements of the array :: \n");     // Entering elements
    for(i=0; i<s; i++)
        scanf("%d",&ar[i]);

    printf("\n Elements are :: \n");              // Printing elements before deleting
    for(i=0; i<s; i++)
        printf("%d \t",ar[i]);
    printf("\n");
    printf("Enter the place you want to delete the element :: ");    // Asking which place to delete
    scanf("%d",&loc);
    j=loc-1;                         // Deleting the element 
    while (j<s)   
    {
        ar[j] = ar[j+1];
        j++;
    }
    ar[s-1] = 0;

    printf("\n The new array is :: \n");      // Printing the final array
    for(j=0; j<s-1; j++)
        printf("%d \t",ar[j]);

    return 0;



}