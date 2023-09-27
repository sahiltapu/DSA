// Reversing the node //
#include<stdio.h>
#include<malloc.h>
struct Node
{
    int info;
    struct Node *next;
};
typedef struct Node node;
node* create(node*);
void traverse(node *);
node* reverse(node*);
int main()
{
    node *start=NULL;
    start=create(start);
    traverse(start);
    start=reverse(start);
    traverse(start);
    return 0;
}
node* create(node *s)
{
    node *temp;
    if(s==NULL)
    {
        s=(node*)malloc(sizeof(node));
        printf("Enter data to first node=");
        scanf("%d",&(s->info));
    }
    temp=s;
    char ch='Y';
    while(ch=='Y')
    {
        temp->next=(node*)malloc(sizeof(node));
        temp=temp->next;
        printf("\nEnter data to New Node=");
        scanf("%d",&(temp->info));
        printf("\nEnter 'Y' to continue or Press 'N' to stop=");
        scanf(" %c",&ch);
    }
    temp->next=NULL;
    return s;
}
void traverse(node *start)
{
    node* ptr;
    ptr=start;
    printf("\nThe created List is=\n");
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->info);
        ptr=ptr->next;
    }
}
node* reverse(node *start)
{
    node *current,*prev,*temp;
    current=start;
    prev=current->next;
    current->next=NULL;
    while(prev!=NULL)
    {
        temp=prev->next;
        prev->next=current;
        current=prev;
        prev=temp;
    }
    start=current;
    return start;
}