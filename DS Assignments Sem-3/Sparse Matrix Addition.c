#include <stdio.h>
struct sparse
{
    int row, col, val;
};
typedef struct sparse Sparsematrix;


void Readmat(Sparsematrix *t)
{
    int m, n, k;
    printf("\nEnter matrix dimensions: ");
    scanf("%d %d", &m, &n);
    printf("Enter the no. of non-zero elements: ");
    scanf("%d", &k);
    t[0].row = m;
    t[0].col = n;
    t[0].val = k;
    printf("Enter matrix:\n");
    for (int i = 1; i <= k; i++)
    {
        scanf("%d %d %d", &t[i].row, &t[i].col, &t[i].val);
    }
}

void Add(Sparsematrix *a, Sparsematrix *b, Sparsematrix *c)
{
    int i = 1, j = 1, k = 1;
    while (i <= a[0].val && j <= b[0].val)
    {
        if (a[i].row < b[j].row)
        {
            c[k].row = a[i].row;
            c[k].col = a[i].col;
            c[k].val = a[i].val;
            i++; k++;
        }
        else if (a[i].row > b[j].row)
        {
            c[k].row = b[j].row;
            c[k].col = b[j].col;
            c[k].val = b[j].val;
            j++; k++;
        }
        else
        {
            if (a[i].col < b[j].col)
            {
                c[k].row = a[i].row;
                c[k].col = a[i].col;
                c[k].val = a[i].val;
                i++; k++;
            }
            else if (a[i].col > b[j].col)
            {
                c[k].row = b[j].row;
                c[k].col = b[j].col;
                c[k].val = b[j].val;
                j++; k++;
            }
            else
            {
                c[k].row = a[i].row;
                c[k].col = a[i].col;
                c[k].val = a[i].val + b[j].val;
                i++; j++; k++; 
            }
        }
    }
    while (i <= a[0].val)
    {
        c[k].row = a[i].row;
        c[k].col = a[i].col;
        c[k].val = a[i].val;
        i++; k++;
    }
    while (j <= b[0].val)
    {
        c[k].row = b[j].row;
        c[k].col = b[j].col;
        c[k].val = b[j].val;
        j++; k++; 
    }
    c[0].row = a[0].row;
    c[0].col = a[0].col;
    c[0].val = k-1;
}

void Printmat(Sparsematrix *t)
{
    int k = 1;
    for (int i = 0; i < t[0].row; i++)
    {
        for (int j = 0; j < t[0].col; j++)
        {
            if (k <= t[0].val)
            {
                if (i == t[k].row && j == t[k].col)
                {
                    printf("%4d", t[k].val);
                    k++;
                }
                else
                printf("%4d", 0);
            }
            else
            printf("%4d", 0);
        }
        printf("\n");
    }
}
int main ()
{
    Sparsematrix a[10];
    Sparsematrix b[10];
    Sparsematrix c[10];
    printf("For matrix A :-");
    Readmat(a);
    printf("For matrix B :-");
    Readmat(b);
    if (b[0].row != a[0].row || b[0].col != a[0].col)
    {
        printf("Wrong Input!");
        return 0;
    }
    Add(a, b, c);
    printf("Matrix A :-\n");
    Printmat(a);
    printf("Matrix B :-\n");
    Printmat(b);
    printf("Final Matrix is :-\n");
    Printmat(c);

}