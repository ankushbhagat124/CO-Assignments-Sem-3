#include <stdio.h>
#include <string.h>
#define size 100
struct balance
{
    char arr[size];
    int top;
};
void push (struct balance *s, char ch)
{
    if (s->top == size-1)
        printf("Stack is Full!");
    else
    {
        s->top = s->top + 1;
        s->arr[s->top] = ch;
    }
}
int pop (struct balance *s)
{
    s->top = s->top - 1;
    return s->top;
}

void display (struct balance *s)
{
    int i = s->top;
    printf("\nElements are: ");
    while (i != -1)
    {
        printf("%c ", s->arr[i]);
        i--;
    }
}
int isEmpty(struct balance s)
{
    if (s.top == -1)
        return 1;
    else
    return 0;
}
int main ()
{
    struct balance s;
    int n; s.top = -1;
    printf("Enter the string: ");
    char st[size];
    scanf("%s", st);
    n = strlen(st);
    int j;
    for (j = 0; j < n; j++)
    {
        if (st[j] == ')')
        {
            int x = pop(&s);    
            if (x < -1)
            break;
        }
        else
            push(&s, st[j]);

    }
    int ans = isEmpty(s);
    if (ans == 1)
        printf("Balanced");
    else
        printf("Unbalanced");
}