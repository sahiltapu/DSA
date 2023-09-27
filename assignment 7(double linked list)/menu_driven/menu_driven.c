// Menu driven programme //
#include <stdio.h>
#include <stdlib.h>
typedef struct NODE
{
    int info;
    struct NODE *next, *prev;
} node;
node *create(node *);
void traverse(node *);
void reverse_traverse(node *);
node *add_at_1st(node *);
void add_at_last(node *);
void add_after_ith(node *);
void add_after_value(node *);
node *delete_1st(node *);
void delete_last(node *);
void delete_ith(node *);
void search_ele(node *, int);
int count = 0;
int main()
{
    node *START;
    START = NULL;
    int opt, opt1, opt2;
    int c, c1, n, ele;
    while (1)
    {
        printf("\n1.create list\n2.Add element\n3.Delete element\n4.Search element\n5.traverse\n6.Reverse traverse\n7.EXIT\nyour choise :: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            START = NULL;
            START = create(START);
            printf("\nYour list is :: \n");
            traverse(START);
            break;
        case 2:
            c = 1;
            while (c != 0)
            {
                printf("\nAdding element \n1.using node number\n2.using value\n3.EXIT\nyour choise :: ");
                scanf("%d", &opt1);
                switch (opt1)
                {
                case 1:
                    c1 = 1;
                    while (c1 != 0)
                    {
                        printf("\nAdd element \n1.At first\n2.At last\n3.After ith node\n4.EXIT\nyour choise :: ");
                        scanf("%d", &opt2);
                        switch (opt2)
                        {
                        case 1:
                            START = add_at_1st(START);
                            break;
                        case 2:
                            add_at_last(START);
                            break;
                        case 3:
                            add_after_ith(START);
                            break;
                        case 4:
                            c1 = 0;
                            break;
                        default:
                            printf("\nWrong option .");
                        }
                    }
                    break;
                case 2:
                    add_after_value(START);
                    break;
                case 3:
                    c = 0;
                    break;
                default:
                    printf("\nWrong option.");
                }
                break;
            case 3:
                printf("\nEnter the node you want to delete :: ");
                scanf("%d", &n);
                if (n == 1)
                {
                    START = delete_1st(START);
                }
                else if (n == count)
                {
                    delete_last(START);
                }
                else
                {
                    delete_ith(START);
                }
                break;
            case 4:
                printf("\nEnter the element you want to seaarch :: ");
                scanf("%d", &ele);
                search_ele(START, ele);
                break;
            case 5:
                traverse(START);
                break;
            case 6:
                reverse_traverse(START);
                break;
            case 7:
                exit(0);
            default:
                printf("Wrong option .");
            }
        }
    }
    return 0;
}
node *create(node *start)
{
    node *temp, *pre;
    char ch = 'y';
    if (start == NULL)
    {
        start = (node *)malloc(sizeof(node));
        printf("\nEnter 1st element of the list :: ");
        count++;
        scanf("%d", &(start->info));
        start->prev = NULL;
        start->next = NULL;
    }
    temp = start;
    while (ch == 'y')
    {
        printf("\nEnter y to continue or n to stop here :: ");
        scanf(" %c", &ch);
        if (ch == 'y')
        {
            temp->next = (node *)malloc(sizeof(node));
            pre = temp;
            temp = temp->next;
            printf("\nEnter element to the list :: ");
            count++;
            scanf("%d", &(temp->info));
            temp->prev = pre;
        }
        else
        {
            break;
        }
    }
    temp->next = NULL;
    return start;
}
void traverse(node *start)
{
    node *ptr;
    ptr = start;
    while (ptr != NULL)
    {
        printf("%d\t", (ptr->info));
        ptr = ptr->next;
    }
}
void reverse_traverse(node *start)
{
    node *temp, *ptr;
    temp = start;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    ptr = temp;
    while (ptr != NULL)
    {
        printf("%d\t", (ptr->info));
        ptr = ptr->prev;
    }
}
node *add_at_1st(node *start)
{
    node *new, *n;
    new = (node *)malloc(sizeof(node));
    printf("\nEnter the element which will be added at 1st place :: ");
    count++;
    scanf("%d", &(new->info));
    new->prev = NULL;
    new->next = start;
    start->prev = new;
    start = new;
    return start;
}
void add_after_value(node *start)
{
    node *temp, *new, *ptr;
    int ele;
    temp = start;
    printf("\nEnter the value after which u want to incert the element :: ");
    scanf("%d", &ele);
    while (temp != NULL)
    {
        if (temp->info == ele)
        {
            break;
        }
        else
        {
            temp = temp->next;
        }
    }
    if (temp == NULL)
    {

        printf("\nElement not found  .");
        exit(0);
    }
    new = (node *)malloc(sizeof(node));
    printf("\nEnter the new element :: ");
    count++;
    scanf("%d", &(new->info));
    ptr = temp->next;
    new->prev = temp;
    temp->next = new;
    new->next = ptr;
    ptr->prev = new;
}
void add_at_last(node *start)
{
    node *temp, *new;
    temp = start;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    new = (node *)malloc(sizeof(node));
    printf("\nEnter the element which will be added at the last position :: ");
    count++;
    scanf("%d", &(new->info));
    new->next = NULL;
    new->prev = temp;
    temp->next = new;
}
void add_after_ith(node *start)
{
    node *new, *temp, *ptr;
    int i, k = 1;
    printf("\nEnter the place after which the element will be added :: ");
    scanf("%d", &i);
    if ((i < 1) || (i > count))
    {
        printf("\nYou have entered a wrong wrong option \n");
        exit(0);
    }
    else
    {
        k = 1;
        temp = start;
        while (k != i)
        {
            temp = temp->next;
            k++;
        }
        ptr = temp->next;
        new = (node *)malloc(sizeof(node));
        printf("\nEnter the element :: ");
        count++;
        scanf("%d", &(new->info));
        new->prev = temp;
        temp->next = new;
        new->next = ptr;
        ptr->prev = new;
    }
}
node *delete_1st(node *start)
{
    node *temp;
    temp = start;
    start = start->next;
    start->prev = NULL;
    free(temp);
    return start;
}
void delete_last(node *start)
{
    node *temp;
    temp = start;
    int k = 1;
    while (k < count - 1)
    {
        temp = temp->next;
        k++;
    }
    temp->next = NULL;
}
void delete_ith(node *start)
{
    node *temp, *ptr, *ptr1;
    int n, k = 1;
    temp = start;
    printf("\nEnter the node you want to delete :: ");
    scanf("%d",&n);
    if ((n < 1) || (n > count))
    {
        printf("\nThe node is not present in the list.");
        exit(0);
    }
    else
    {
        for (k = 1; k < n; k++)
        {
            temp = temp->next;
        }
        ptr = temp->next;
        ptr1 = temp->prev;
        ptr1->next = ptr;
        ptr->prev = ptr1;
        free(temp);
    }
}
void search_ele(node *start, int ele)
{
    node *temp;
    temp = start;
    while (temp != NULL)
    {
        if (temp->info == ele)
        {
            printf("\nThe element is present in the list . \n");
            return;
        }
        else
        {
            temp = temp->next;
        }
    }
    if (temp == NULL)
    {
        printf("\nElement not found.\n");
        return;
    }
}
