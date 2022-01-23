#include <stdio.h>
#define size 10
struct Stack
{
    int a[size];
    int top;
};
void push (struct Stack *s, int x)
{
    if (s->top == size-1)
        printf("Stack is Full!");
    else
    {
        s->top = s->top + 1;
        s->a[s->top] = x;
    }
}
int pop (struct Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is Empty!");
        return -1;
    }
    else
    {
        int y = s->a[s->top];
        s->top = s->top - 1;
        return y;
    }
}
void display (struct Stack s)
{
    int i = s.top;
    printf("Elements are: ");
    while (i != -1)
    {
        printf("%d ", s.a[i]);
        i--;
    }
}

int main ()
{
    struct Stack s;
    s.top = -1;
    int x, option;
    do
    {
        printf("\nMENU Options:\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        printf("4.EXIT\n");
        scanf("%d", &option);
        switch(option)
        {
            case 1: printf("Enter x: ");
                    scanf("%d", &x);
                    push(&s, x);
                    break;
            case 2: x = pop(&s);
                    printf("%d is deleted from the stack.\n", x);
                    break;
            case 3: display(s);
                    break;
        }
    }while (option != 4);
}