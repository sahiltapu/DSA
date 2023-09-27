// Menu driven program on single linked list //
#include <stdio.h>
#include <stdlib.h>
typedef struct NODE
{
    int info;
    struct NODE *next;
} node;
node *create(node *);
node *add_at_1st(node *);
void add_ele_after_value(node *);
void add_at_last(node *);
void traverse(node *);
node *reverse(node *);
void add_ele(node *, int);
node *delet_at_1st(node *);
void delet_at_last(node *);
void del_ele(node *, int);
node *sort(node *);
int count = 0;
int main()
{
    node *START;
    int opt, opt1;
    int n, val, n1, c = 0;
    while (1)
    {
        printf("\n1.create list\n2.incert element\n3.delete element\n4.travese the list\n5.reverse the list\n6.Sorting\n7.EXIT\nYour choise :: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            START = NULL;
            START = create(START);
            printf("\nThe Elements of the list are :: \n");
            traverse(START);
            break;
        case 2:
            c = 0;

            while (c != 3)
            {
                opt1 = 0;
                printf("\nEnter the way u want add element in the list\n1.By giving node number\n2.By giving  a value\n3.EXIT\nYour choise :: ");
                scanf("%d", &opt1);
                switch (opt1)
                {
                case 1:
                    printf("\nEnter the node after which you want to incert element :: ");
                    scanf("%d", &n);
                    if (n == 1)
                    {
                        START = add_at_1st(START);
                        printf("\nAfter adding the list is :: \n");
                        traverse(START);
                    }
                    else if (n == count)
                    {
                        add_at_last(START);
                        printf("\nAfter adding the list is :: \n");
                        traverse(START);
                    }
                    else if ((n > count) || (n < 1))
                    {
                        printf("\nThe node is not present in the list .");
                    }
                    else
                    {
                        add_ele(START, n);
                        printf("\nAfter adding the list is :: \n");
                        traverse(START);
                    }
                    break;
                case 2:
                    add_ele_after_value(START);
                    printf("\nAfter adding the list is :: \n");
                    traverse(START);
                    break;
                case 3:
                    c = 3;
                default:
                    printf("\nYou have entered an wrong option .");
                }
            }
            break;
        case 3:
            printf("\nEnter the node you want to delete from the list :: ");
            scanf("%d", &n1);
            if (n1 == 1)
            {
                START = delet_at_1st(START);
                printf("\nAfter deleting the list is :: \n");
                traverse(START);
            }
            else if (n1 == count)
            {
                delet_at_last(START);
                printf("\nAfter deleting the list is :: \n");
                traverse(START);
            }
            else if ((n > count) || (n < 1))
            {
                printf("\nThe node is not present in the list.");
            }
            else
            {
                del_ele(START, n1);
                printf("\nAfter deleting the list is :: \n");
                traverse(START);
            }
            break;
        case 4:
            printf("\nThe elements of the list are :: \n");
            traverse(START);
            break;
        case 5:
            START = reverse(START);
            printf("\nAfter reversing the list is :: \n");
            traverse(START);
            START = reverse(START);
            break;
        case 6:
            START = sort(START);
            printf("\nAfter sorting the list is :: \n");
            traverse(START);
            break;
        case 7:
            exit(0);
        default:
            printf("\nYou have entered a wrong option.");
        }
    }
}
node *create(node *start)
{
    node *temp;
    char ch = 'y';
    if (start == NULL)
    {
        start = (node *)malloc(sizeof(node));
        printf("\nEnter the 1st element to the node :: ");
        count++;
        scanf("%d", &(start->info));
    }
    temp = start;
    while (ch == 'y')
    {
        printf("\nEnter y to continue or n to end the list here :: ");
        scanf(" %c", &ch);
        if (ch == 'y')
        {
            temp->next = (node *)malloc(sizeof(node));
            temp = temp->next;
            printf("\nEnter element into the list :: ");
            count++;
            scanf("%d", &(temp->info));
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
void add_ele_after_value(node *start)
{
    node *new, *temp;
    int i;
    printf("\nEnter the value after which u want to incert the element :: ");
    scanf("%d", &i);
    temp = start;
    while (temp != NULL)
    {
        if (temp->info == i)
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
        printf("\nThe element is not present in the list.\n");
        return;
    }
    else
    {
        new = (node *)malloc(sizeof(node));
        printf("\nEnter the value :: ");
        count++;
        scanf("%d", &(new->info));
        new->next = temp->next;
        temp->next = new;
    }
}
node *add_at_1st(node *start)
{
    node *new;
    new = (node *)malloc(sizeof(node));
    printf("Enter the new element in the list :: ");
    count++;
    scanf("%d", &(new->info));
    new->next = start;
    start = new;
}
void add_at_last(node *start)
{
    node *new, *temp;
    temp = start;
    new = (node *)malloc(sizeof(node));
    printf("\nEnter the new element ::");
    count++;
    scanf("%d", &(new->info));
    new->next = NULL;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
}
void add_ele(node *start, int n)
{
    node *p, *new;
    int k = 1;
    p = start;
    while (k < n)
    {
        p = p->next;
        k++;
    }
    new = (node *)malloc(sizeof(node));
    printf("\nEnter the value of the node :: ");
    count++;
    scanf("%d", &(new->info));
    new->next = p->next;
    p->next = new;
}
node *delet_at_1st(node *start)
{

    node *ptr;
    ptr = start->next;
    start = ptr;
    count--;
    return start;
}
void delet_at_last(node *start)
{
    node *ptr;
    ptr = start;
    int i;
    for (i = 1; i < count - 1; i++)
    {
        ptr = ptr->next;
    }
    ptr->next = NULL;
    count--;
    return start;
}
void del_ele(node *start, int n1)
{
    node *cur, *prev;
    int k;
    cur = start;
    k = 1;
    while (k < n1)
    {
        prev = cur;
        cur = cur->next;
        k++;
    }
    prev->next = cur->next;
    count--;
    free(cur);
}
node *reverse(node *start)
{
    node *current, *prev, *temp;
    current = start;
    prev = current->next;
    current->next = NULL;
    while (prev != NULL)
    {
        temp = prev->next;
        prev->next = current;
        current = prev;
        prev = temp;
    }
    start = current;
    return start;
}
node *sort(node *start)
{
    int min;
    node *curnt, *nextpt, *minpt;
    curnt = start;
    while (curnt->next != NULL)
    {
        min = curnt->info;
        minpt = curnt;
        nextpt = curnt->next;
        while (nextpt != NULL)
        {
            if (nextpt->info < min)
            {
                min = nextpt->info;
                minpt = nextpt;
            }
            nextpt = nextpt->next;
        }
        if (min != curnt->info)
        {
            minpt->info = curnt->info;
            curnt->info = min;
        }
        curnt = curnt->next;
    }
    return start;
}