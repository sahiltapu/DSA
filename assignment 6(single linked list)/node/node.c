// Link list starting //
#include<stdio.h>
struct NODE
{
    int info;
    struct NODE * next;
};
typedef struct NODE node;
int main()
{
    node n1,n2,n3,n4,n5,*ptr;
    
    printf("Enter 5 values :: \n");
    scanf("%d%d%d%d%d",&(n1.info),&(n2.info),&(n3.info),&(n4.info),&(n5.info));
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = NULL;
    ptr = &n1;
    printf("\nYour Entered elements are :: \n");
    while(ptr != NULL)
    {
        printf("%d\t",ptr -> info);
        ptr = ptr -> next;
    }
    return 0;
}