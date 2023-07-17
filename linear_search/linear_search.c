#include <stdio.h>
#include <stdlib.h>

void input_array(int arr[], int size)
{
    printf("Enter %d elements in the array :: ", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}
void display_array(int arr[], int size)
{
    printf("Array is :: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}
void linear_search(int arr[], int size, int key)
{
    int i = 0;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            printf("Element Found at index :: %d\n", i);
            break;
        }
    }
    if (i == size)
    {
        printf("Element not found.\n");
    }
}
int main()
{
    int size = 0, arr[size], key = 0;
    printf("Enter the size of array :: ");
    scanf("%d", &size);
    input_array(arr, size);
    display_array(arr, size);
    printf("Enter the element to find :: ");
    scanf("%d", &key);
    linear_search(arr, size, key);
    return 0;
}
