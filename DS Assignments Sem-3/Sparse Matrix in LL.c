#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
int size1 = 0, size2 = 0;
struct Sparse
{
    float coeff;
    int expo;
};
typedef struct Sparse polynomial;
struct poly
{
    float cof;
    int exp;
    struct poly *next;
};
void readpoly(polynomial t[], int size)
{
    float a; int b;
    for (int i = 0; i < size; i++)
    {
        scanf("%f %d", &a, &b);
        t[i].coeff = a;
        t[i].expo = b;
    }
}
void convertpoly(struct poly **s, polynomial pr[], int sz1)
{
    struct poly *p, *q;
    for (int i = 0; i < sz1; i++)
    {
        p = malloc(sizeof(struct poly));
        p->next = NULL;
        p->cof = pr[i].coeff;
        p->exp = pr[i].expo;
        if (*s == NULL)
        *s = p;
        else
        {
            q = *s;
            while (q->next != NULL)
            {
                q = q->next;
            }
            q->next = p;
        }
    }
}
void output(struct poly *s)
{
    struct poly *p;
    p = s;
    if (p == NULL)
        printf("0");
    while (p != NULL)
    {
        if (p->next == NULL)
            printf("(%.2f)x^%d", p->cof, p->exp);
        else
            printf("(%.2f)x^%d+", p->cof, p->exp);
        p = p->next;
    }
}
int main ()
{
    polynomial p1[SIZE], p2[SIZE];
    struct poly *pt1 = NULL, *pt2 = NULL;
    printf("Enter polynomial1 size: ");
    scanf("%d", &size1);
    printf("Enter your polynomial1 in sparse form(Coefficient/Exponent):\n");
    readpoly(p1, size1);
    printf("\nEnter polynomial2 size: ");
    scanf("%d", &size2);
    printf("Enter your polynomial2 in sparse form(Coefficient/Exponent):\n");
    readpoly(p2, size2);

    convertpoly(&pt1, p1, size1);
    convertpoly(&pt2, p2, size2);
    printf("\nPolynomial 1 in Linked List form is: \n");
    output(pt1);
    printf("\nPolynomial 2 in Linked List form is: \n");
    output(pt2);
}
