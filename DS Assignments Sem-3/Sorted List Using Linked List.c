#include <stdio.h>
#include <malloc.h>
struct Node
{
    int value;
    struct Node *next;
}*ptr, *newptr, *start;

void Insert(struct Node **s, int x)
{
    newptr = (struct Node *)malloc(sizeof(struct Node));
    newptr->value = x;
    ptr = *s;
    if (*s == NULL)
    {
        *s = newptr;
        newptr->next = NULL;
    }
    else if (x < ptr->value)
    {
        newptr->next = *s;
        *s = newptr;
    }
    else
    {
        while (ptr->next != NULL && ptr->next->value <= x)
        {
            ptr = ptr->next;
        }
        newptr->next = ptr->next;
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
void Print(struct Node *s)
{
    while (s != NULL)
    {
        printf("%d -> ", s->value);
        s = s->next;
    }
    printf("NULL\n");
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
int main ()
{
    int choice;
    start = NULL;
    while (choice != 5)
    {
        printf("\nEnter your Choice!");
        printf("\n1.Insert Node");
        printf("\n2.Delete Node");
        printf("\n3.Search Node");
        printf("\n4.Print Linked List");
        printf("\n5.EXIT\n");
        scanf("%d", &choice);
        
        int x,y;
        switch(choice)
        {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &x);
                Insert(&start, x);
                break;
            case 2:
                printf("Enter the value to be deleted: ");
                scanf("%d", &x);
                Delete(&start, x);
                break;
            case 3:
                printf("Enter the value to be searched: ");
                scanf("%d", &x);
                int ans = search(start, x);
                break;
            case 4:
                Print(start);
                break;
            case 5:
                break;
            default:
            printf("Wrong Menu Input!");
        }
    }
}