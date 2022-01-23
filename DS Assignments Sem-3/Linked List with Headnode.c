#include <stdio.h>
#include <malloc.h>
struct Node
{
    int value;
    struct Node *next;
}*ptr, *newptr;
struct Headnode
{
    int count;
    struct Node *start, *end;
};
struct Headnode H;

void InsertBeg(struct Headnode *H, int x)
{
    newptr = (struct Node *)malloc(sizeof(struct Node *));
    newptr->value = x;
    newptr->next = NULL;
    if (H->start == NULL)
    {
        H->end = newptr;
    }
    else
    {
        newptr->next = H->start;
    }
    H->start = newptr;
    H->count = H->count + 1;
}
void Append(struct Headnode *H, int x)
{
    newptr = (struct Node *)malloc(sizeof(struct Node *));
    newptr->value = x;
    newptr->next = NULL;
    if (H->start == NULL)
    {
        H->start = newptr;
    }
    ptr = H->start;
    while (ptr->next != NULL)
    ptr = ptr->next;
    ptr->next = newptr;
    H->end = newptr;
    H->count = H->count + 1;
}
void Delete(struct Headnode *H, int x)
{
    if (H->start == NULL)
    {
        printf("List is Empty!");
    }
    else
    {
        ptr = H->start;
        newptr = NULL;
        while (ptr != NULL && ptr->value != x)
        {
            newptr = ptr;
            ptr = ptr->next;
        }
        if (newptr == NULL)
        ptr = ptr->next;
        else
        newptr->next = ptr->next;
        printf("Node Deleted!\n");
        if (H->end == ptr)
        H->end = newptr;
        free(ptr);
        H->count = H->count - 1;
    }
}
int search(struct Headnode H, int x)
{
    ptr = H.start;
    while (ptr != NULL)
    {
        if (ptr->value == x)
        return 1;
        ptr = ptr->next;
    }
    return 0;
}
void Count(struct Headnode H)
{
    printf("No. of nodes in Linked List is: %d\n", H.count);
}
void Print(struct Headnode H)
{
    ptr = H.start;
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->value);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
int main ()
{
    int choice;
    H.start = NULL;
    H.end = NULL;
    H.count = 0;
    while (choice != 7)
    {
        printf("\nEnter your Choice!");
        printf("\n1.Insert at the Beginning");
        printf("\n2.Append");
        printf("\n3.Count");
        printf("\n4.Delete Node");
        printf("\n5.Search Node");
        printf("\n6.Print Linked List");
        printf("\n7.EXIT\n");
        scanf("%d", &choice);
        
        int x,y;
        switch(choice)
        {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &x);
                InsertBeg(&H, x);
                break;
            case 2:
                printf("Enter the value to be inserted: ");
                scanf("%d", &x);
                Append(&H, x);
                break;
            case 3:
                Count(H);
                break;
            case 4:
                printf("Enter the value to be deleted: ");
                scanf("%d", &x);
                Delete(&H, x);
                break;
            case 5:
                printf("Enter the value to be searched in the list: ");
                scanf("%d", &x);
                int ans = search(H, x);
                if (ans == 1)
                printf("Element is present in the list.\n");
                else
                printf("Element is not present in the list.\n");
                break;
            case 6:
                Print(H);
                break;
            default:
            printf("Wrong Input!");
        }
    }
}