// Arrenging elements in asscending order (selection shot) //
#include<stdio.h>
int main()
{
    int a[20];
    int min,j,i,n,temp;
    printf("Enter size of the array :: ");     // Enetring size of array
    scanf("%d",&n);             
    printf("Enter the elements of the array :: \n");   // Entering elements of the array
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n");
    printf("Enements of the array before shotting :: \n");   // Printiing elements before shotting 
    for(i=0;i<n;i++)
    {
        printf("%d \t",a[i]);
    }
    printf("\n");
    for(i=0;i<n;i++)          // shoting process
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
            if(min!=i)
            {
                temp=a[min];
                a[min]=a[i];
                a[i]=temp;
            }
        }
    }

    printf("After shoting the array (in assending order) is :: \n");   // Display the final array
    for(i=0;i<n;i++)
    {
        printf("%d \t",a[i]);
    }
    return 0;
}