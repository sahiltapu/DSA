// shorting array by using bubble shot //
#include <stdio.h>
int main()
{
  int array[100], n, c, d, swap;

  printf("Enter the size of array ::");     // Entering size
  scanf("%d", &n);

  printf("Enter the elements in the array :: \n", n);     //Entering elements

  for (c = 0; c < n; c++)
    scanf("%d", &array[c]);
  printf("The elements of the array before shorting :: \n ");  //Printing elements before shorting
  for(c = 0;c < n; c++)
  {
    printf("%d \t",array[c]);
    
  }
   printf("\n");

  for (c = 0 ; c < n - 1; c++)       // Bubble shorting process
  {
    for (d = 0 ; d < n - c - 1; d++)
    {
      if (array[d] > array[d+1]) 
      {
        swap       = array[d];
        array[d]   = array[d+1];
        array[d+1] = swap;
      }
    }
  }

  printf("After shoting the array in assending order :: \n");   // Printing elements after shorting

  for (c = 0; c < n; c++)
     printf("%d \t", array[c]);

  return 0;
}

