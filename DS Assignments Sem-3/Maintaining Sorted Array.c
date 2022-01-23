#include <stdio.h>
#include <malloc.h>
struct Node
{
    int value;
    struct Node *next;
}*start, *newptr, *ptr;
void fun(struct Node* start)
{
    if(start == NULL)
    return;
    printf("%d  ", start->value);
    if(start->next != NULL )
    fun(start->next->next);
    printf("%d  ", start->value);
}
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
int main ()
{
    start = NULL;
    int num;
    printf("Enter num: ");
    scanf("%d", &num);
    int x;
    for (int i = 0; i < num; i++)
    {
        printf("Enter the value to be inserted: ");
        scanf("%d", &x);
        Insert(&start, x);
    }
    fun(start);
}
