#include <stdio.h>
#include <malloc.h>
struct Node
{
    int value;
    struct Node *next;
} *start, *newptr, *ptr;

void InsertBeg(struct Node **s, int x)
{
    newptr = (struct Node *)malloc(sizeof(struct Node));
    newptr->value = x;
    newptr->next = *s;
    *s = newptr;
}
void Append(struct Node **s, int x)
{
    newptr = (struct Node *)malloc(sizeof(struct Node));
    newptr->value = x;
    newptr->next = NULL;
    if (*s == NULL)
    {
        newptr->next = *s;
        *s = newptr;
    }
    else
    {
        ptr = *s;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newptr;
    }
}
int search(struct Node *s, int x)
{
    ptr = s;
    if (s == NULL)
    {
        printf("List is empty!\n");
        return 0;
    }
    while (ptr != NULL && ptr->value != x)
    ptr = ptr->next;

    if (ptr != NULL)
    {
        printf("Element is present!\n");
        return 1;
    }
    else
    {
        printf("Element Not present!\n");
        return 0;
    }
}
void InsertBetween(struct Node **s, int x, int y)
{
    newptr = (struct Node *)malloc(sizeof(struct Node));
    newptr->value = x;
    ptr = *s;
    if (search(ptr, y))
    {
        while (ptr->next != NULL)
        {
            if (ptr->value == y)
            break;
            ptr = ptr->next;
        }
        newptr->next = ptr->next;
        ptr->next = newptr;
    }
    else
    printf("Element y is Absent!");
}
void Delete(struct Node **s, int x)
{
    if (*s == NULL)
    printf("List is empty!");

    newptr = NULL;
    ptr = *s;
    while (ptr != NULL && ptr->value != x)
    {
        newptr = ptr;
        ptr = ptr->next;
    }
    if (newptr == NULL)
    {
        *s = ptr->next;
        printf("Node Deleted!\n");
        free(ptr);
    }
    else if(ptr != NULL)
    {
        newptr->next = ptr->next;
        printf("Node Deleted!\n");
        free(ptr);
    }
}
void Print(struct Node *s)
{
    while (s != NULL)
    {
        printf("%d -> ", s->value);
        s = s->next;
    }
    printf("NULL\n");
}
int main ()
{
    int choice;
    start = NULL;
    while (choice != 7)
    {
        printf("Enter your Choice!");
        printf("\n1.Insert at the Beginning");
        printf("\n2.Append");
        printf("\n3.Insert after a Node");
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
                InsertBeg(&start, x);
                break;
            case 2:
                printf("Enter the value to be inserted: ");
                scanf("%d", &x);
                Append(&start, x);
                break;
            case 3:
                printf("Enter the value to be inserted: ");
                scanf("%d", &x);
                printf("Enter the value after which x has to be inserted: ");
                scanf("%d", &y);
                InsertBetween(&start, x, y);
                break;
            case 4:
                printf("Enter the value to be deleted: ");
                scanf("%d", &x);
                Delete(&start, x);
                break;
            case 5:
                printf("Enter the value to be searched in the list: ");
                scanf("%d", &x);
                search(start, x);
                break;
            case 6:
                Print(start);
                break;
            default:
            printf("Wrong Input!");
        }
    }
}