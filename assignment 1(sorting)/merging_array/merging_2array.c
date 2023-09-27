// Merging two array //
#include<stdio.h>
#define size 10
void input1(int []);
void input2(int []);
void display1(int [], int[]);
void display2(int []);
void merge(int [], int[]);
int main()
{
    int a[20],b[20];
    input1(a);
    input2(b);
    display1(a, b);
    merge(a, b);
    
    return 0;
  }
  void input1(int a[])      // Inputing the 1st array
  {
      int i;
      
      printf("\n Enter 10 elements of the 1st array :: \n");
      for(i=0;i<size;i++)
      {
          scanf("%d",&a[i]);
      }
  }
  void input2(int b[])        // inputing the 2nd array
  {
      int i;
      printf("\n Enter 10 elements of the 2nd array :: \n ");
      for(i=0;i<size;i++)
      {
          scanf("%d",&b[i]);
      }
  }
  void display1(int a[], int b[])        // Display 1st and 2nd array separately
  {
      int i;
      printf("\n Elements of the 1st array is :: \n");
      for(i=0;i<size;i++)
      {
          printf("%d \t",a[i]);
      }
      printf("\n");
      printf("\n Elements of the 2nd array is :: \n");
      for(i=0;i<size;i++)
      {
          printf("%d \t",b[i]);
      }
      printf("\n");

  }
  void merge(int a[], int b[])          // Merging process
  {
      int i,j;
      int c[40];
      for(i=0;i<size;i++)
      {
           c[i]=a[i];
      }
      for(j=0;j<size;j++)
      {
          c[i+j]=b[j];
      }
      display2(c);
  }
  void display2(int c[])                // Displaying the final array
  {
      int i;
      printf("\n After merging the new array is :: \n");
      for(i=0;i<size+size;i++)
      {
            printf("%d\t",c[i]);
      }

}