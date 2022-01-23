#include <stdio.h>
#define size 30
struct stack
{
    char a[size];
    int top;
};
int operand(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
        return 1;
    return 0;
}
int operator_error(char ch)
{
    if (ch == '*' || ch == '/' || ch == '+' || ch == '-' || ch == '^')
        return 1;
    return 0;
}
int operator(char ch)
{
    if (ch == '*' || ch == '/' || ch == '+' || ch == '-' || ch == '(' || ch == '^')
        return 1;
    return 0;
}
//Error Handling
int isValid(char input[])
{
    struct paranthesis
    {
        char para[size];
        int top2;
    };
    int i = 0;
    struct paranthesis p;
    p.top2 = -1;
    while (input[i] != '$')
    {
        if (operand(input[i]))
        {
            if (i == 0 || operator_error(input[i - 1]))
            {
                i++;
            }
            else if (input[i - 1] == '(')
                i++;
            else
            {
                return 0;
            }
        }
        else if (operator_error(input[i]))
        {
            if (i == 0)
                return 0;
            else if (operator_error(input[i - 1]))
                return 0;
            i++;
        }
        else
        {
            if (input[i] == '(')
            {
                p.top2 = p.top2 + 1;
                p.para[p.top2] = '(';
            }
            else if (input[i] == ')')
            {
                if (p.top2 == -1)
                return 0;
                else
                {
                    p.top2 = p.top2 - 1;
                }
            }
            else
            return 0;
            i++;
        }
    }
    if (p.top2 != -1)
    return 0;
    else
    return 1;
}
int isp(char ch)
{
    if (ch == '^')
    return 4;
    else if (ch == '*' || ch == '/' || ch == '%')
    return 3;
    else if (ch == '+' || ch == '-')
    return 2;
    else if (ch == '(')
    return 1;
    else if (ch == '$')
    return 0;
}
int icp(char ch)
{
    if (ch == '^')
    return 4;
    if (ch == '*' || ch == '/' || ch == '%')
    return 3;
    else if (ch == '+' || ch == '-')
    return 2;
    else if (ch == '(')
    return 5;
}
void push (struct stack *s, char ch)
{
    if (s->top == size-1)
        printf("Stack is Full!");
    else
    {
        s->top = s->top + 1;
        s->a[s->top] = ch;
    }
}
char pop (struct stack *s)
{
    char cht = s->a[s->top];
    s->top = s->top - 1;
    return cht;
}
int main()
{
    char input[size];
    printf("Enter your infix expression: ");
    scanf("%s", input);
    char postfix[size];
    struct stack s;
    s.top = -1;
    push(&s, '$');
    if (isValid(input))
    {
        int i = 0, j = 0;
        while (input[i] != '$')
        {
            char x = input[i];
            if (operand(x))
            {
                postfix[j++] = x;
            }
            else if (x == ')')
            {
                int y;
                while (s.a[s.top] != '(')
                {
                    postfix[j++] = pop(&s);
                }
                y = pop(&s);
            }
            else if (operator(x))
            {
                while (isp(s.a[s.top]) >= icp(x))
                {
                    postfix[j++] = pop(&s);
                }
                push(&s, x);
            }
            i++;
        }
        while (s.top > 0)
        {
            postfix[j++] = pop(&s);
        }
        postfix[j] = '\0';
        printf("Result: %s", postfix);
    }
    else
    printf("Invalid Input!");
}
