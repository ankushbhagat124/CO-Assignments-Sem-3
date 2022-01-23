#include <stdlib.h>
#include<stdio.h>

struct SparseMat {
    int row, col, val;
    struct SparseMat *next;
};

struct SparseMat *InsertAtLast(struct SparseMat *s, int row, int col, int value){
    struct SparseMat *p, *q;
    p = (struct SparseMat*)malloc(sizeof(struct SparseMat));
    p->row = row;
    p->col = col;
    p->val = value;
    p->next = NULL;
    if(s == NULL){ //At head
        p->next = s;
        s = p;
    }
    else{
        q = s;
        while (q->next != NULL) {
            q = q->next;
        }
        p->next = q->next;
        q->next = p;
    }
    return s;
}

struct SparseMat *Read(struct SparseMat *s){
    int n;
    int i;
    int row, col, val;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    for (i=0; i<n; i++) {
        printf("Enter the row and col of term %d: ",i+1);
        scanf("%d %d",&row, &col);
        printf("Enter the value of term %d: ",i+1);
        scanf("%d",&val);
        s = InsertAtLast(s, row, col, val);
    }
    return s;
}

void display(struct SparseMat *s, int row, int col){
    if (s == NULL) {
        printf("Matrix is empty\n");
        return;
    }
    else{
       struct SparseMat *q;
        q = s;
        for (int i=0; i<=row; i++) {
            for (int j=0; j<=col; j++) {
                if (q != NULL && (q->row == i && q->col == j)) {
                    printf(" %d ",q->val);
                    q = q->next;
                }
                else{
                    printf(" %d ",0);
                }
            }
            printf("\n");
        }
    }
}

struct SparseMat *add(struct SparseMat *s1, struct SparseMat *s2){
    struct SparseMat *s = NULL;
    struct SparseMat *p = s1;
    struct SparseMat *q = s2;
    while (p != NULL && q !=NULL) {
        if (p->row == q->row) {
            if (p->col == q->col) {
                s = InsertAtLast(s, p->row, p->col, (p->val + q->val));
                p = p->next;
                q = q->next;
            }
            else{
                if (p->col < q->col) {
                    s = InsertAtLast(s, p->row, p->col, p->val);
                    p = p->next;
                }
                else{
                    s = InsertAtLast(s, q->row, q->col, q->val);
                    q = q->next;
                }
            }
        }
        else{
            if (p->row < q->row) {
                s = InsertAtLast(s, p->row, p->col, p->val);
                p = p->next;
            }
            else{
                s = InsertAtLast(s, q->row, q->col, q->val);
                q = q->next;
            }
        }
    }
    while (p != NULL) {
        s = InsertAtLast(s, p->row, p->col, p->val);
        p = p->next;
    }
    while (q != NULL) {
        s = InsertAtLast(s, q->row, q->col, q->val);
        q = q->next;
    }
    return s;
}

int main()
{
    printf("For addition dimensions of S1 and S2 must be same!\n");
    struct SparseMat *s1 = NULL;
    int r1,c1;
    printf("\nEnter no of rows for S1: ");
    scanf("%d",&r1);
    printf("Enter no of columns for S1: ");
    scanf("%d",&c1);
    s1 = Read(s1);
    struct SparseMat *s2 = NULL;
    int r2,c2;
    printf("\nEnter no of rows for S2: ");
    scanf("%d",&r2);
    printf("Enter no of columns for S2: ");
    scanf("%d",&c2);
    s2 = Read(s2);
    struct SparseMat *s = NULL;
    s = add(s1, s2);
    printf("\nSparse Matrix S1-\n");
    display(s1,r1,c1);
    printf("\nSparse Matrix S2-\n");
    display(s2,r2,c2);
    printf("\n\nS1 + S2 = \n");
    if (r1 == r2 && c1 == c2) {
        display(s,r1,c1);
    }
    else{
        printf("Dimensions of S1 and S2 are different\n");
    }
    return 0;
}
// #include <stdio.h>
// #include <stdlib.h>
// #define SIZE 100
// int size1 = 0, size2 = 0;
// struct Sparse
// {
//     float coeff;
//     int expo;
// };
// typedef struct Sparse polynomial;
// struct poly
// {
//     float cof;
//     int exp;
//     struct poly *next;
// };
// void readpoly(polynomial t[], int size)
// {
//     float a;
//     int b;
//     for (int i = 0; i < size; i++)
//     {
//         scanf("%f %d", &a, &b);
//         t[i].coeff = a;
//         t[i].expo = b;
//     }
// }
// void convertpoly(struct poly **s, polynomial pr[], int sz1)
// {
//     struct poly *p, *q;
//     for (int i = 0; i < sz1; i++)
//     {
//         p = malloc(sizeof(struct poly));
//         p->next = NULL;
//         p->cof = pr[i].coeff;
//         p->exp = pr[i].expo;
//         if (*s == NULL)
//             *s = p;
//         else
//
//         {
//             q = *s;
//             while (q->next != NULL)
//             {
//                 q = q->next;
//             }
//             q->next = p;
//         }
//     }
// }
// struct poly *polyadd(struct poly *p1, struct poly *p2)
// {
//     struct poly *p3 = NULL, *p, *q;
//     if (p1 == NULL)
//     {
//         p3 = p2;
//         return p3;
//     }
//     else if (p2 == NULL)
//     {
//         p3 = p1;
//         return p3;
//     }
//     while (p1 != NULL || p2 != NULL)
//     {
//         p = malloc(sizeof(struct poly));
//         p->next = NULL;
//         if (p1 != NULL && p2 != NULL)
//         {
//             if (p1->exp == p2->exp)
//             {
//                 p->cof = p1->cof + p2->cof;
//                 p->exp = p1->exp;
//                 p1 = p1->next;
//                 p2 = p2->next;
//             }
//             else if (p1->exp > p2->exp)
//             {
//                 p->cof = p1->cof;
//                 p->exp = p1->exp;
//                 p1 = p1->next;
//             }
//             else
//             {
//                 p->cof = p2->cof;
//                 p->exp = p2->exp;
//                 p2 = p2->next;
//             }
//         }
//         else
//         {
//             if (p2 == NULL)
//             {
//                 p->cof = p1->cof;
//                 p->exp = p1->exp;
//                 p1 = p1->next;
//             }
//             else if (p1 == NULL)
//             {
//                 p->cof = p2->cof;
//                 p->exp = p2->exp;
//                 p2 = p2->next;
//             }
//         }
//         if (p3 == NULL)
//             p3 = p;
//         else
//         {
//             q = p3;
//             while (q->next != NULL)
//             {
//                 q = q->next;
//             }
//             q->next = p;
//         }
//     }
//     return p3;
// }
// void output(struct poly *s)
// {
//     struct poly *p;
//     p = s;
//     if (p == NULL)
//         printf("0");
//     while (p != NULL)
//     {
//         if (p->next == NULL)
//             printf("(%.2f)x^%d", p->cof, p->exp);
//         else
//             printf("(%.2f)x^%d+", p->cof, p->exp);
//         p = p->next;
//     }
// }
// int main()
// {
//     polynomial p1[SIZE], p2[SIZE];
//     struct poly *pt1 = NULL, *pt2 = NULL;
//     printf("Enter polynomial1 size: ");
//     scanf("%d", &size1);
//     printf("Enter your polynomial1 in sparse form(Coefficient/Exponent):\n");
//     readpoly(p1, size1);
//     printf("\nEnter polynomial2 size: ");
//     scanf("%d", &size2);
//     printf("Enter your polynomial2 in sparse form(Coefficient/Exponent):\n");
//     readpoly(p2, size2);
//     convertpoly(&pt1, p1, size1);
//     convertpoly(&pt2, p2, size2);
//     printf("\nPolynomial 1 in Linked List form is: \n");
//     output(pt1);
//     printf("\nPolynomial 2 in Linked List form is: \n");
//     output(pt2);
//     printf("\nAddition of two sparsematrix in linked list representations is: \n");
//     output(polyadd(pt1, pt2));
// }
