#include <stdio.h>
#define SIZE 100
int k = 0, k2 = 0;
struct Sparse
{
    float coeff;
    int expo;
};
typedef struct Sparse polynomial;
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
void Add(polynomial p1[], polynomial p2[], polynomial p3[], int size1, int size2)
{
    int i = 0, j = 0;
    while (i < size1 && j < size2)
    {
        if (p1[i].expo > p2[j].expo)
        {
            p3[k].expo = p1[i].expo;
            p3[k].coeff = p1[i].coeff;
            i++;
            k++;
        }
        else if (p1[i].expo < p2[j].expo)
        {
            p3[k].expo = p2[j].expo;
            p3[k].coeff = p2[j].coeff;
            j++;
            k++;
        }
        else
        {
            p3[k].expo = p1[i].expo;
            p3[k].coeff = p1[i].coeff + p2[j].coeff;
            i++, j++;
            k++;
        }
    }
    while (i < size1)
    {
        p3[k].expo = p1[i].expo;
        p3[k].coeff = p1[i].coeff;
        i++; k++;
    }
    while (j < size2)
    {
        p3[k].expo = p2[j].expo;
        p3[k].coeff = p2[j].coeff;
        j++; k++;
    }
}
void Mul(polynomial p1[], polynomial p2[], polynomial p4[], int size1, int size2)
{
    int count[SIZE] = {0}, pos[SIZE] = {0};
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            p4[k2].expo = p1[i].expo + p2[j].expo;
            if (count[p4[k2].expo] >= 1)
            {
                p4[pos[p4[k2].expo]].coeff += (p1[i].coeff * p2[j].coeff);
            }
            else
            {
                p4[k2].coeff = (p1[i].coeff * p2[j].coeff);
                count[p4[k2].expo]++;
                pos[p4[k2].expo] = k2;
            }
            k2++;
        }
    }
}
void printpoly(polynomial t[], int size)
{
    for (int i =0; i < size; i++)
    {
        if (t[i].coeff != 0.00)
        {
            printf("%0.2f %d\n",t[i].coeff, t[i].expo);
        }
    }
}
int main ()
{
    polynomial p1[SIZE], p2[SIZE], p3[SIZE], p4[SIZE];
    int size1, size2, size3=0, size4 = 0;
    printf("Enter polynomial1 size: ");
    scanf("%d", &size1);
    printf("Enter your polynomial1 in sparse form(Coefficient/Exponent):\n");
    readpoly(p1, size1);
    printf("Enter polynomial2 size: ");
    scanf("%d", &size2);
    printf("Enter your polynomial2 in sparse form(Coefficient/Exponent):\n");
    readpoly(p2, size2);
    Add(p1, p2, p3, size1, size2);
    size3 = k;
    printf("Addition of Polynomial: \n");
    printpoly(p3, size3);
    Mul(p1, p2, p4, size1, size2);
    size4 = k2;
    printf("Multiplication of Polynomial: \n");
    printpoly(p4, size4);

}
/*
#include <stdio.h>
#define size 100
typedef struct polynomial poly;

struct polynomial
{
    float coeff;
    int exp;
};

void readPoly(poly p[], int n)
{
    printf("Enter coefficient and power:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &p[i].coeff);
        scanf("%d", &p[i].exp);
    }
}

int addPoly(poly p1[], poly p2[], poly p4[], int n1, int n2)
{
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (p1[i].exp == p2[j].exp)
        {
            p4[k].coeff = p1[i].coeff + p2[j].coeff;
            p4[k].exp = p1[i].exp;
            k++;
            i++;
            j++;
        }
        else if (p1[i].exp > p2[j].exp)
        {
            p4[k].coeff = p1[i].coeff;
            p4[k].exp = p1[i].exp;
            k++;
            i++;
        }
        else
        {
            p4[k].coeff = p2[j].coeff;
            p4[k].exp = p2[j].exp;
            k++;
            j++;
        }
    }

    while (i < n1)
    {
        p4[k].coeff = p1[i].coeff;
        p4[k].exp = p1[i].exp;
        k++;
        i++;
    }
    while (j < n2)
    {
        p4[k].coeff = p2[j].coeff;
        p4[k].exp = p2[j].exp;
        k++;
        j++;
    }
    return k;
}

int multiplyPoly(poly p1[], poly p2[], poly p4[], int n1, int n2)
{
    int i, j, k, count[size] = {0}, pos[size] = {0};
    for (k = 0; k < size; k++)
    {
        p4[k].coeff = 0;
        p4[k].exp = 0;
    }
    k = 0;
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            if (p1[i].coeff != 0 && p2[j].coeff != 0)
            {
                p4[k].exp = p1[i].exp + p2[j].exp;
                if (count[p4[k].exp] >= 1)
                {
                    p4[pos[p4[k].exp]].coeff += (p1[i].coeff * p2[j].coeff);
                }
                else
                {
                    p4[k].coeff += (p1[i].coeff * p2[j].coeff);
                    count[p4[k].exp]++;
                    pos[p4[k].exp] = k;
                }
                k++;
            }
        }
    }
    return k;
}

void printPoly(poly p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (p[i].coeff != 0)
        {
            printf("(%.2f) x^%d ", p[i].coeff, p[i].exp);
            if (i != n - 1)
                printf("+ ");
        }
    }
    printf("\n");
}

int main()
{
    poly p1[size], p2[size], p41[size], p42[size];
    int n1, n2;
    printf("Enter no. of distinct exponential terms for polynomial 1:");
    scanf("%d", &n1);
    readPoly(p1, n1);
    printPoly(p1, n1);
    printf("Enter no. of distinct exponential terms for polynomial 2:");
    scanf("%d", &n2);
    readPoly(p2, n2);
    printPoly(p2, n2);

    int p41Size = addPoly(p1, p2, p41, n1, n2);
    printf("Addition of polynomials P1 and P2:\n");
    printPoly(p41, p41Size);

    int p42Size = multiplyPoly(p1, p2, p42, n1, n2);
    printf("Multiplication of polynomials P1 and P2:\n");
    printPoly(p42, p42Size);

    return 0;
}*/
